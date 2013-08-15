/**
 * Project: CScreenie: A screenshot managing utility
 * File name: dialog.h
 * Description: Fullscreen Dialog header file
 *
 * @author Biber Copyright (C) 2010.
 *
 * @see The GNU Public License (GPL)
 */

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

private slots:
    void on_cancelButton_clicked();
    void on_clipboardButton_clicked();
    void on_hddButton_clicked();
    void on_customButton_clicked();
    void on_publicButton_clicked();
};

#endif // DIALOG_H
