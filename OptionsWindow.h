/**
 * Project: CScreenie: A screenshot managing utility
 * File name: OptionsWindow.h
 * Description:  Options window header file
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
#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H
#include <QMainWindow>
#include <qwidget.h>
#include <QSettings>

namespace Ui {
    class OptionsWindow;
}

class OptionsWindow : public QMainWindow
{
    Q_OBJECT
public:
    OptionsWindow(QWidget *parent);
private:
    QSettings settings;
    Ui::OptionsWindow *ui;
    QString overlaycolor,fillcolor;
private slots:
    void on_closebutton_clicked();
    void on_applybutton_clicked();
    void on_okbutton_clicked();
    void on_overlaybutton_clicked();
    void on_fillbutton_clicked();
    void ask_changed();
    void ask_prnt_changed();

signals:
    void closing();
};


#endif // OPTIONSWINDOW_H
