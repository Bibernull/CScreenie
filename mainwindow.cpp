/**
 * Project: CScreenie: A screenshot managing utility
 * File name: mainwindow.cpp
 * Description:  A main window overlay
 *
 * @author Biber Copyright (C) 2010.
 *
 * @see The GNU Public License (GPL)
 */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <QtGui>
#include <stdlib.h>
#include <QMessageBox>
#include <QKeySequence>

#ifdef Q_OS_WIN
    #include <windows.h>
    #include <shellapi.h>
#endif

#include "mainwindow.h"
#include "globalshortcutmanager.h"
#include "dialog.h"
#include "uploader.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QCoreApplication::addLibraryPath(QDir::currentPath());


    checksettings();

    setupPosition();

    createActions();
    createTrayIcon();

    trayIcon->show();
    setupWidgets();

    setupHotkeys();

    checkForUpdates();

}


void MainWindow::setupPosition(){

    QSize size;

    QDesktopWidget desk_widget;
    QRect r = desk_widget.screenGeometry(QPoint(-10,-10));

    this->move(QPoint(r.x()-10,-10));

    size.setWidth(QApplication::desktop()->width()+20);
    size.setHeight(QApplication::desktop()->height()+20);

    this->resize(size);


    this->setWindowFlags(Qt::X11BypassWindowManagerHint );
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAttribute(Qt::WA_NoSystemBackground,false);
    #ifdef WIN32
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);
    #endif
    this->setWindowOpacity(settings.value("general/opacity").toDouble());
    this->setAutoFillBackground(false);
    this->setStyleSheet("background-color:"+settings.value("general/overlaycolor").toString());

}

void MainWindow::setupHotkeys(){


    //TODO GlobalShortcutManager::instance()->clear();  disconnect all the keys, and reconnect with new ones
    GlobalShortcutManager::instance()->clear();
    /*
    GlobalShortcutManager::instance()->connect(QKeySequence(settings.value("keys/serverkey").toString()),this,SLOT(setToServer()));
    GlobalShortcutManager::instance()->connect(QKeySequence(settings.value("keys/hddkey").toString()),this,SLOT(setToHdd()));
    GlobalShortcutManager::instance()->connect(QKeySequence(settings.value("keys/clipkey").toString()),this,SLOT(setToClip()));
    GlobalShortcutManager::instance()->connect(QKeySequence(settings.value("keys/publickey").toString()),this,SLOT(setToPublic()));
    */

    GlobalShortcutManager::instance()->connect(QKeySequence(settings.value("keys/serverkey").toString()),this,SLOT(triggerScreen(int)), SERVER);
    GlobalShortcutManager::instance()->connect(QKeySequence(settings.value("keys/hddkey").toString()),this,SLOT(triggerScreen(int)), HDD);
    GlobalShortcutManager::instance()->connect(QKeySequence(settings.value("keys/clipkey").toString()),this,SLOT(triggerScreen(int)), CLIPBOARD);
    GlobalShortcutManager::instance()->connect(QKeySequence(settings.value("keys/publickey").toString()),this,SLOT(triggerScreen(int)), PUBLIC);

    if(settings.value("keys/prntscrnkey_enabled").toBool()){
        GlobalShortcutManager::instance()->connect(QKeySequence(settings.value("keys/prntscrnkey").toString()),this,SLOT(printScreen()));
    }

}

void MainWindow::checkForUpdates(){

    QString result = QString::fromStdString(Uploader::get("http://cscreenie.sourceforge.net/manifest.xml"));

if(!result.isEmpty()){

    version = atof(InBetween(result.toStdString(),"<version>","</version>").c_str());

    if(version > VERSION){

    update_url = InBetween(result.toStdString(),"<url>","</url>");

        QAction *updateAction = new QAction(tr("&Update"), this);
        connect(updateAction, SIGNAL(triggered()), this, SLOT(update()));
        trayIconMenu->addAction(updateAction);

    trayIcon->showMessage("New version found","New version of CScreenie is available for download, right click the tray icon and update");

            }
        }
}

void MainWindow::update(){

    QString file = QFileDialog::getSaveFileName(this, tr("Save"), QDir::homePath() + "/CScreenie_" + QString::number(version) + ".msi");

  if(file.isEmpty()) return;


  Uploader::getFile(file.toStdString(),update_url);


#ifdef Q_OS_WIN
    int result = (int)::ShellExecuteA(0, "open", file.toUtf8().constData(), 0, 0, SW_SHOWNORMAL);
    if (SE_ERR_ACCESSDENIED == result)
    {
        // Requesting elevation
        result = (int)::ShellExecuteA(0, "runas", file.toUtf8().constData(), 0, 0, SW_SHOWNORMAL);
    }
    if (result <= 32)
    {
        // error handling
    }
#else
    if (!QProcess::startDetached(file))
    {
        // error handling
    }
#endif


}

void MainWindow::checksettings(){


    if(!settings.contains("general/serverurl")){
        settings.setValue("general/serverurl","empty");
    }
    if(!settings.contains("general/imagepath")){
        settings.setValue("general/imagepath","empty");
    }
    if(!settings.contains("general/screendir")){
        settings.setValue("general/screendir",QDir::homePath() + "/Screenshots");
    }
    if(!settings.contains("general/publicsite")){
        settings.setValue("general/publicsite","imgur");
    }
    if(!settings.contains("general/overlaycolor")){
        settings.setValue("general/overlaycolor","blue");
    }
    if(!settings.contains("general/bordercolor")){
        settings.setValue("general/bordercolor","orange");
    }
    if(!settings.contains("general/fillcolor")){
        settings.setValue("general/fillcolor","orange");
    }
    if(!settings.contains("general/opacity")){
        settings.setValue("general/opacity","0.50");
    }
    if(!settings.contains("general/askforloc")){
        settings.setValue("general/askforloc",QVariant(true));
    }
    if(!settings.contains("general/startup")){
        settings.setValue("general/",QVariant(false));
    }
    if(!settings.contains("general/quality")){
        settings.setValue("general/quality","40");
    }

    if(!settings.contains("keys/serverkey")){
        settings.setValue("keys/serverkey","Ctrl+1");
    }

    if(!settings.contains("keys/hddkey")){
        settings.setValue("keys/hddkey","Ctrl+2");
    }

    if(!settings.contains("keys/clipkey")){
        settings.setValue("keys/clipkey","Ctrl+3");
    }

    if(!settings.contains("keys/publickey")){
        settings.setValue("keys/publickey","Ctrl+4");
    }

    if(!settings.contains("keys/fullscreenkey")){
        settings.setValue("keys/fullscreenkey","Ctrl+5");
    }

    if(!settings.contains("keys/prntscrn_action")){
        settings.setValue("keys/prntscrn_action",3);
    }

    if(!settings.contains("keys/prntscrnkey_enabled")){
        settings.setValue("keys/prntscrnkey_enabled",QVariant(false));
    }

    if(!settings.contains("keys/prntscrnkey")){
        settings.setValue("keys/prntscrnkey","Ctrl+p");
    }

    settings.sync();
}





void MainWindow::options(){
   optionswindow = new OptionsWindow(this);
   optionswindow->show();
   this->connect(optionswindow,SIGNAL(closing()),this,SLOT(setupHotkeys()));
}

void MainWindow::AboutShow(){
   aboutWindow = new About(this);
   aboutWindow->show();
}

void MainWindow::triggerScreen(int value){
    settings.sync();
    this->setStyleSheet("background-color:"+settings.value("general/overlaycolor").toString());
    rectangle->frame->setStyleSheet("background-color:" + settings.value("general/fillcolor").toString());
    rectangle->where = (UploadLocation)value;
    rectangle->frame->hide();
    this->show();
    this->setFocus();
}

void MainWindow::setToServer(){
    settings.sync();
    this->setStyleSheet("background-color:"+settings.value("general/overlaycolor").toString());
    rectangle->frame->setStyleSheet("background-color:" + settings.value("general/fillcolor").toString());
    rectangle->where = SERVER;
    rectangle->frame->hide();
    this->show();
    this->setFocus();
}

void MainWindow::setToHdd(){
    settings.sync();
    this->setStyleSheet("background-color:"+settings.value("general/overlaycolor").toString());
    rectangle->frame->setStyleSheet("background-color:" + settings.value("general/fillcolor").toString());
    rectangle->where = HDD;
    rectangle->frame->hide();
    this->show();
    this->setFocus();
}

void MainWindow::setToPublic(){
    settings.sync();
    this->setStyleSheet("background-color:"+settings.value("general/overlaycolor").toString());
    rectangle->frame->setStyleSheet("background-color:" + settings.value("general/fillcolor").toString());
    rectangle->where = PUBLIC;
    rectangle->frame->hide();
    this->show();
    this->setFocus();
}

void MainWindow::setToClip(){
    settings.sync();
    this->setStyleSheet("background-color:"+settings.value("general/overlaycolor").toString());
    rectangle->frame->setStyleSheet("background-color:" + settings.value("general/fillcolor").toString());
    rectangle->where = CLIPBOARD;
    rectangle->frame->hide();
    this->show();
    this->setFocus();
}

void MainWindow::createActions()
 {

     quitAction = new QAction(tr("&Quit"), this);
     connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

     aboutAction = new QAction(tr("&About"), this);
     connect(aboutAction, SIGNAL(triggered()), this, SLOT(AboutShow()));


     tohddAction = new QAction(tr("To hdd"), this);
     connect(tohddAction,SIGNAL(triggered()),this,SLOT(setToHdd()));

     toServerAction = new QAction(tr("To server"), this);
     connect(toServerAction,SIGNAL(triggered()),this,SLOT(setToServer()));

     toPublicAction = new QAction(tr("To Public site"),this);
     connect(toPublicAction,SIGNAL(triggered()),this,SLOT(setToPublic()));

     toClipAction = new QAction(tr("To Clipboard"),this);
     connect(toClipAction,SIGNAL(triggered()),this,SLOT(setToClip()));

     optionsAction = new QAction(tr("Options"),this);
     connect(optionsAction,SIGNAL(triggered()),this,SLOT(options()));

     to_custom_action = new QAction(tr("To custom server"),this);
     connect(to_custom_action,SIGNAL(triggered()),this,SLOT(existing_to_custom()));

     to_public_action = new QAction(tr("To public server"),this);
     connect(to_public_action,SIGNAL(triggered()),this,SLOT(existing_to_public()));

 }


void MainWindow::createTrayIcon()
{
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(tohddAction);
    trayIconMenu->addAction(toServerAction);
    trayIconMenu->addAction(toPublicAction);
    trayIconMenu->addAction(toClipAction);
    trayIconMenu->addSeparator();

    existingMenu = new QMenu("Upload existing file",trayIconMenu);



    existingMenu->addAction(to_custom_action);
    existingMenu->addAction(to_public_action);
    trayIconMenu->addMenu(existingMenu);



    trayIconMenu->addAction(optionsAction);
    trayIconMenu->addAction(aboutAction);
    trayIconMenu->addAction(quitAction);
    trayIconMenu->setStyleSheet("QMenu{background:black;color:white;} QMenu::item:selected{background:white;color:black}");
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
    QIcon icon;

    icon.addFile(":/icon/Tray",QSize(22,22),QIcon::Normal);


    trayIcon->setIcon(icon);
    trayIcon->setToolTip("CScreenie");

    trayIcon->showMessage("test","test",QSystemTrayIcon::NoIcon,1000);
}



void MainWindow::setupWidgets()
{
    QFrame *frame = new QFrame;
    QHBoxLayout *frameLayout = new QHBoxLayout(frame);


    rectangle = new RectangleWidget(this,trayIcon);

    frameLayout->addWidget(rectangle);

    frame->show();
    setCentralWidget(frame);
}


void MainWindow::existing_to_custom(){

    QString filename = QFileDialog::getOpenFileName(this,"Select file", QDir::homePath());


    if(settings.value("general/serverurl").toString() != "empty"){

    std::string url = settings.value("general/serverurl").toString().toStdString();

    Uploader *uploader = new Uploader();

    QString result = uploader->toCustomServer(filename,url,settings.value("general/imagepath").toString().toStdString(),0);

    if(result != "Fail"){

    QApplication::clipboard()->setText(result);
    trayIcon->showMessage("Done","Uploaded to "+result);


    result.clear();

    }else{
        trayIcon->showMessage("Fail", "Failed uploading to "+QString::fromStdString(url));
        }

    url.clear();

    }else{ //No server set

        trayIcon->showMessage("Error","No server set");
    }

}

void MainWindow::existing_to_public(){

    QString filename = QFileDialog::getOpenFileName(this,"Select file", QDir::homePath());

    Uploader *uploader = new Uploader();

    QString result = uploader->toPublicServer(filename,settings.value("general/publicsite").toString(),0);

    if(result != "Fail"){

    QApplication::clipboard()->setText(result);
    trayIcon->showMessage("Done","Uploaded to "+result);

     }else{
       trayIcon->showMessage("Fail","Failed uploading to"+settings.value("general/publicsite").toString());
     }

     result.clear();
}

void MainWindow::printScreen(){

     UploadLocation action;
     switch(settings.value("keys/prntscrn_action").toInt()){
     case 0: action = HDD;break;
     case 1: action = SERVER;break;
     case 2: action = CLIPBOARD;break;
     case 3: action = PUBLIC;break;
     }

    rectangle->frame->resize(QApplication::desktop()->geometry().size());
    rectangle->where = action;
    rectangle->processScreenshot();

}
