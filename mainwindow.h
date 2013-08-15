/**
 * Project: CScreenie: A screenshot managing utility
 * File name: mainwindow.h
 * Description:  Main window header file
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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define VERSION 1.20

#include <QPixmap>
#include <QMainWindow>
#include <qwidget.h>
#include <QSystemTrayIcon>
#include <QComboBox>
#include <QPushButton>
#include <QSettings>
#include <QFileDialog>

#include "OptionsWindow.h"
#include "about.h"
#include "RectangleWidget.h"

class OptionsWindow;
class RectangleWidget;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    QSettings settings;
private slots:
    void triggerScreen(int);
    void setToServer();
    void setToHdd();
    void setToClip();
    void setToPublic();
    void options();
    void AboutShow();
    void existing_to_custom();
    void existing_to_public();
    void printScreen();

    void setupHotkeys();
    void update();
private:
        OptionsWindow *optionswindow;
        About *aboutWindow;
        void checksettings();
        void setIcon(int index);
        void iconActivated(QSystemTrayIcon::ActivationReason reason);
        void showMessage();
        void setupWidgets();
        void createIconGroupBox();
        void createActions();
        void createTrayIcon();
        void checkForUpdates();
        void setupPosition();

        QSystemTrayIcon *trayIcon;
        QMenu *trayIconMenu;
        QMenu *existingMenu;

             QAction *to_custom_action;
             QAction *to_public_action;
             QAction *quitAction;
             QAction *toServerAction;
             QAction *tohddAction;
             QAction *toClipAction;
             QAction *toPublicAction;
             QAction *optionsAction;
             QAction *aboutAction;


             std::string update_url;
             double version;

    RectangleWidget *rectangle;

    static std::string InBetween(std::string content, std::string begin, std::string end) {

        if(content.empty() || begin.empty() || end.empty()) return "";

           unsigned int pos1 = content.find(begin);
           unsigned int pos2 = 0;

           if(pos1 != std::string::npos){

                pos1 += begin.length();
                pos2 = content.find(end,pos1);

                if(pos2 != std::string::npos){
                    return content.substr(pos1, pos2 - pos1);
                }
            }

            return "";
        }

};

#endif
