/**
 * Project: CScreenie: A screenshot managing utility
 * File name: OptionsWindow.cpp
 * Description:  Optoins window
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
#include "OptionsWindow.h"
#include "ui_optionswindow.h"
#include <QMainWindow>
#include <QRadioButton>
#include <QLineEdit>
#include <QColorDialog>

OptionsWindow::OptionsWindow(QWidget *parent):
        QMainWindow(parent),ui(new Ui::OptionsWindow)
{

    ui->setupUi(this);
    this->setStyleSheet("background-color:white");

    overlaycolor = settings.value("general/overlaycolor").toString();
    fillcolor    = settings.value("general/fillcolor").toString();

    ui->quality->setValue(settings.value("general/quality").toInt());

    ui->overlaybutton->setStyleSheet("background-color:"+overlaycolor);
    ui->fillbutton->setStyleSheet("background-color:"+fillcolor);

    if(settings.value("general/askforloc").toBool()){
        ui->askcheckbox->setCheckState(Qt::Checked);
        ui->screendirpath->setEnabled(false);
    }else{
        ui->askcheckbox->setCheckState(Qt::Unchecked);
        ui->screendirpath->setEnabled(true);
    }

    connect(ui->askcheckbox,SIGNAL(stateChanged(int)),this,SLOT(ask_changed()));
    connect(ui->prntscrn_checkbox,SIGNAL(stateChanged(int)),this,SLOT(ask_prnt_changed()));

    if(settings.value("general/publicsite").toString() == "imgshack"){
        ui->imgshackbutton->setChecked(true);
    }else{
        ui->imgurbutton->setChecked(true);
    }


    ui->prntscrn_comboBox->setCurrentIndex(settings.value("keys/prntscrn_action").toInt());



    if(settings.value("keys/prntscrnkey_enabled").toBool()){
        ui->prntscrn_checkbox->setChecked(true);
        ui->prntscrn_comboBox->setEnabled(true);
    }


    ui->serverurlbox->setText(settings.value("general/serverurl").toString());
    ui->imagepathbox->setText(settings.value("general/imagepath").toString());
    ui->screendirpath->setText(settings.value("general/screendir").toString());

    ui->custumkeybox->setText(settings.value("keys/serverkey").toString());
    ui->hddkeybox->setText(settings.value("keys/hddkey").toString());
    ui->clipkeybox->setText(settings.value("keys/clipkey").toString());
    ui->publickeybox->setText(settings.value("keys/publickey").toString());
    ui->fullscreenkeybox->setText(settings.value("keys/fullscreenkey").toString());
    ui->prntkeybox->setText(settings.value("keys/prntscrnkey").toString());
}

void OptionsWindow::ask_prnt_changed(){

    if(ui->prntscrn_checkbox->isChecked()){
        ui->prntscrn_comboBox->setEnabled(true);
    }else{
        ui->prntscrn_comboBox->setEnabled(false);
    }
}

void OptionsWindow::ask_changed(){

    if(ui->askcheckbox->checkState() == Qt::Checked){

        ui->screendirpath->setEnabled(false);
    }else{
        ui->askcheckbox->setCheckState(Qt::Unchecked);
        ui->screendirpath->setEnabled(true);
    }
}

void OptionsWindow::on_overlaybutton_clicked(){
    overlaycolor = QColorDialog::getColor(QColor(overlaycolor),this).name();
    ui->overlaybutton->setStyleSheet("background-color:" + overlaycolor);
}


void OptionsWindow::on_fillbutton_clicked(){
    fillcolor = QColorDialog::getColor(QColor(fillcolor),this).name();
    ui->fillbutton->setStyleSheet("background-color:" + fillcolor);
}

void OptionsWindow::on_okbutton_clicked()
{
    if(ui->askcheckbox->checkState() == Qt::Checked){
        settings.setValue("general/askforloc",QVariant(true));
    }else{
        settings.setValue("general/askforloc",QVariant(false));
    }

    if(ui->imgurbutton->isChecked()){
        settings.setValue("general/publicsite","imgur");
    }else{
        settings.setValue("general/publicsite","imgshack");
    }

    settings.setValue("general/imagepath",ui->imagepathbox->text());
    settings.setValue("general/serverurl",ui->serverurlbox->text());
    settings.setValue("general/screendir",ui->screendirpath->text());
    settings.setValue("general/overlaycolor",overlaycolor);
    settings.setValue("general/fillcolor",fillcolor);

    if(ui->prntscrn_checkbox->isChecked()){
         settings.setValue("keys/prntscrnkey_enabled",QVariant(true));
         settings.setValue("keys/prntscrn_action", ui->prntscrn_comboBox->currentIndex());
     }else{
          settings.setValue("keys/prntscrnkey_enabled",QVariant(false));
     }

    settings.setValue("keys/serverkey",ui->custumkeybox->text());
    settings.setValue("keys/hddkey",ui->hddkeybox->text());
    settings.setValue("keys/clipkey",ui->clipkeybox->text());
    settings.setValue("keys/publickey",ui->publickeybox->text());
    settings.setValue("keys/fullscreenkey",ui->fullscreenkeybox->text());
    settings.setValue("keys/prntscrnkey",ui->prntkeybox->text());

    settings.setValue("general/quality",QString::number(ui->quality->value()));
    settings.sync();
    emit closing();
    this->close();
}

void OptionsWindow::on_applybutton_clicked()
{
    if(ui->askcheckbox->checkState() == Qt::Checked){
        settings.setValue("general/askforloc",QVariant(true));
    }else{
        settings.setValue("general/askforloc",QVariant(false));
    }

    if(ui->imgurbutton->isChecked()){
        settings.setValue("general/publicsite","imgur");
    }else{
        settings.setValue("general/publicsite","imgshack");
    }

    if(ui->prntscrn_checkbox->isChecked()){
         settings.setValue("keys/prntscrnkey_enabled",QVariant(true));
         settings.setValue("keys/prntscrn_action", ui->prntscrn_comboBox->currentIndex());
    }

    settings.setValue("general/imagepath",ui->imagepathbox->text());
    settings.setValue("general/serverurl",ui->serverurlbox->text());
    settings.setValue("general/screendir",ui->screendirpath->text());
    settings.setValue("general/overlaycolor",overlaycolor);
    settings.setValue("general/fillcolor",fillcolor);
    settings.setValue("general/quality",QString::number(ui->quality->value()));
    settings.sync();
}

void OptionsWindow::on_closebutton_clicked()
{
    this->close();
}
