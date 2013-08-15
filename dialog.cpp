/**
 * Project: CScreenie: A screenshot managing utility
 * File name: dialog.cpp
 * Description: Fullscreen Dialog
 *
 * @author Biber Copyright (C) 2010.
 *
 * @see The GNU Public License (GPL)
 */
/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_customButton_clicked()
{
    this->done(0);
}

void Dialog::on_hddButton_clicked()
{
    this->done(1);
}

void Dialog::on_clipboardButton_clicked()
{
    this->done(2);
}

void Dialog::on_publicButton_clicked()
{
    this->done(3);
}



void Dialog::on_cancelButton_clicked()
{
    this->done(-1);
}
