/**
 * Project: CScreenie: A screenshot managing utility
 * File name: RectangleWidget.cpp
 * Description:  A Selection Rectangle, also contains the uploading actions
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

#include "RectangleWidget.h"
#include <QtGui>
#include <qwidget.h>
#include <QMessageBox>
#include <qwaitcondition.h>
#include <QMutex>
#include <qclipboard.h>
#include <QByteArray>

#include "uploader.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "qt_windows.h"





RectangleWidget::RectangleWidget(QWidget *parent, QSystemTrayIcon *Icon)
{

    this->trayIcon = Icon;

    res = false;
    QHBoxLayout *layout = new QHBoxLayout( this );
    layout->setMargin( 0 );

            frame = new QFrame(this);
            frame->setObjectName(QString::fromUtf8("frame"));
            frame->setGeometry(QRect(0, 0, 0, 0));
            frame->setFrameShape(QFrame::Box);
            frame->setFrameStyle(QFrame::Plain);
            frame->setStyleSheet("background-color:" + settings.value("general/fillcolor").toString());

    layout->addWidget(frame);

    this->setAutoFillBackground(false);
    frame->resize(QSize(0,0));



}


void RectangleWidget::mousePressEvent(QMouseEvent *event){


    if(event->button() == Qt::RightButton){

        this->parentWidget()->parentWidget()->hide();

    }else{

    res = true;

    frame->show();
    original_loc = event->pos();
    frame->move(original_loc);

        }
}


void RectangleWidget::mouseMoveEvent(QMouseEvent *event){

       resizerect(original_loc,event->pos());

}

void RectangleWidget::resizerect(QPoint orig, QPoint current){

    QPoint location(-1,-1);
    QSize size;

    if(res){

        if(orig.x() < current.x() ){
            location.setX(orig.x());
            size.setWidth(current.x() - orig.x());
        }else{
            location.setX(current.x());
            size.setWidth(orig.x() - current.x());
        }

        if(orig.y() < current.y() ){
            location.setY(orig.y());
            size.setHeight(current.y()-orig.y());
        }else{
            location.setY(current.y());
            size.setHeight(orig.y()-current.y());
        }

        if(location != QPoint(-1,-1)){
        frame->move(location);
        }

        frame->resize(size);
    }



}

void RectangleWidget::mouseReleaseEvent(QMouseEvent *event){



    if(event->button() == Qt::LeftButton){

    processScreenshot();
}



} //End mouseReleaseEvent



void RectangleWidget::processScreenshot(){


    QString result;

    result.clear();

        res = false;

        frame->hide();

        this->parentWidget()->parentWidget()->hide();


        #ifndef WIN32

        QMutex *mutex = new QMutex(QMutex::NonRecursive);

        QWaitCondition *sleep = new QWaitCondition();


        mutex->lock();  //Lock the thread
        sleep->wait(mutex,1000);    //Wait for the parents hide() function to settle,and unlock it

        #endif

        QDesktopWidget desk_widget;
        QRect r = desk_widget.screenGeometry(QPoint(-10,-10));



        ScreenShot(r.x() + frame->pos().x(), r.y() + frame->pos().y(), frame->size().width() - 2, frame->size().height() - 2); // take the screenshot



        int quality;

        switch(settings.value("general/quality").toInt()){
        case 0: quality = 0; break;
        case 1: quality = -1; break;
        case 2: quality = 100; break;
        default: quality = -1; break;
        }



        QByteArray *bytes = new QByteArray();
        QBuffer buff(bytes);
        buff.open(QIODevice::ReadWrite);
        screenshotgfx.save(&buff, "PNG");

        if(where == SERVER){  //Upload to a custom server


            if(settings.value("general/serverurl").toString() != "empty"){

                std::string url = settings.value("general/serverurl").toString().toStdString();

                Uploader *uploader = new Uploader();

                result = uploader->toCustomServer(bytes->constData(), bytes->size(), url, settings.value("general/imagepath").toString().toStdString() , 0);

                delete uploader;


                if(result != "Fail"){

                QApplication::clipboard()->setText(result);
                trayIcon->showMessage("Done","Uploaded to " + result);


                }else{
                    trayIcon->showMessage("Fail", "Failed uploading to " + QString::fromStdString(url));
                }

                url.clear();

                }else{ //No server set

                    trayIcon->showMessage("Error","No server set");
                }

                result.clear();

            } //End custom server


        if(where == HDD){   //Save to hdd

        SaveScreenshot(GetRandomString(6),quality);

        }// End to hdd



        if(where == CLIPBOARD){   //Copy to clipboard

            toClipboard();

            trayIcon->showMessage("Done","Image copied to your clipboard");
        } //End clipboard


        if(where == PUBLIC){ //Upload to a public server

        Uploader *uploader = new Uploader();

             result = uploader->toPublicServer(bytes->constData(),bytes->size(),settings.value("general/publicsite").toString(),0);


             if(result != "Fail"){

             QApplication::clipboard()->setText(result);
             trayIcon->showMessage("Done","Uploaded to "+result);

              }else{
                trayIcon->showMessage("Fail","Failed uploading to "+settings.value("general/publicsite").toString());
              }

              result.clear();
              delete uploader;

        } //End public

        screenshotgfx = QPixmap();
        bytes->clear();
        buff.close();
        delete  bytes;
}

  void RectangleWidget::ScreenShot(int x, int y, int w, int h){

        screenshotgfx = QPixmap();

        screenshotgfx = QPixmap::grabWindow(QApplication::desktop()->winId(),x,y,w,h);

        }

  void RectangleWidget::SaveScreenshot(QString file,int quality){

      QString format = "png";

      if(settings.value("general/askforloc").toBool()){
      file = QFileDialog::getSaveFileName(this->parentWidget()->parentWidget(), tr("Save ScreenShot"), QDir::homePath() + "/" + file, tr("Image Files (*.png )"));
      }else{
          file = settings.value("general/screendir").toString() + "/"  + file;
      }

#ifndef WIN32
  file.append(".png");
#endif

      screenshotgfx.save( file, format.toAscii(),quality);


  }


  void RectangleWidget::toClipboard(){




      QApplication::clipboard()->setImage( screenshotgfx.toImage() );

  }


  QString RectangleWidget::GetRandomString( int length )
  {
      static bool seed_flag = false;

      QString chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

      QString token;

      // qsrand() is a thread-safe version of srand(),
      // so the static seed_flag variable should not pose
      // concurrency problems
      if ( seed_flag == false )
      {
          qsrand( time( NULL ) );

          seed_flag = true;
      }

      for ( int i = 0; i < length; ++i )
      {
          token += chars[ qrand() % 36 ];
      }

      return token;
  }
