/**
 * Project: CScreenie: A screenshot managing utility
 * File name: RectangleWidget.h
 * Description:  Rectangle header file
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
#ifndef RECTANGLE_WIDGET_H
#define RECTANGLE_WIDGET_H

#include <QtGui/QWidget>
#include <QPoint>
#include <QPixmap>
#include <QWidget>
#include <QFrame>
#include <string>
#include <QSettings>
#include <QProgressDialog>
#include <QSystemTrayIcon>
class QFrame;

using namespace std;

enum UploadLocation { SERVER, HDD, CLIPBOARD, PUBLIC};

class RectangleWidget : public QWidget
{
    Q_OBJECT
public:
    RectangleWidget(QWidget *parent,QSystemTrayIcon *Icon);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void resizerect(QPoint orig, QPoint current);
    void SaveScreenshot(QString file,int quality);
    void toClipboard();
    void processScreenshot();
private slots:
void ScreenShot(int x, int y, int w, int h);
public:


    QString GetRandomString( int length );
    QSettings settings;
    QWidget *parrent;
    QFrame *frame;
    QPoint original_loc;
    bool res;
    QPixmap screenshotgfx;
    UploadLocation where;
    QSystemTrayIcon *trayIcon;
};

#endif
