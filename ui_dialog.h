/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Wed Aug 14 19:57:24 2013
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *customButton;
    QPushButton *hddButton;
    QPushButton *clipboardButton;
    QPushButton *publicButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(170, 172);
        QPalette palette;
        QBrush brush(QColor(255, 247, 239, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(246, 246, 246, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        Dialog->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/Tray"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        customButton = new QPushButton(Dialog);
        customButton->setObjectName(QString::fromUtf8("customButton"));
        customButton->setGeometry(QRect(40, 10, 75, 23));
        hddButton = new QPushButton(Dialog);
        hddButton->setObjectName(QString::fromUtf8("hddButton"));
        hddButton->setGeometry(QRect(40, 40, 75, 23));
        clipboardButton = new QPushButton(Dialog);
        clipboardButton->setObjectName(QString::fromUtf8("clipboardButton"));
        clipboardButton->setGeometry(QRect(40, 70, 75, 23));
        publicButton = new QPushButton(Dialog);
        publicButton->setObjectName(QString::fromUtf8("publicButton"));
        publicButton->setGeometry(QRect(40, 100, 75, 23));
        cancelButton = new QPushButton(Dialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(90, 140, 75, 23));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Fullscreen", 0, QApplication::UnicodeUTF8));
        customButton->setText(QApplication::translate("Dialog", "To Custom", 0, QApplication::UnicodeUTF8));
        hddButton->setText(QApplication::translate("Dialog", "To Hdd", 0, QApplication::UnicodeUTF8));
        clipboardButton->setText(QApplication::translate("Dialog", "To Clipboard", 0, QApplication::UnicodeUTF8));
        publicButton->setText(QApplication::translate("Dialog", "To Public", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("Dialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
