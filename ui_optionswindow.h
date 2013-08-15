/********************************************************************************
** Form generated from reading UI file 'optionswindow.ui'
**
** Created: Wed Aug 14 19:57:25 2013
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSWINDOW_H
#define UI_OPTIONSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptionsWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_12;
    QPushButton *applybutton;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_3;
    QPushButton *overlaybutton;
    QLineEdit *imagepathbox;
    QLineEdit *fullscreenkeybox;
    QLabel *label_2;
    QLineEdit *hddkeybox;
    QLabel *label_7;
    QLabel *label_9;
    QRadioButton *imgurbutton;
    QCheckBox *askcheckbox;
    QLabel *label_6;
    QLineEdit *serverurlbox;
    QLineEdit *screendirpath;
    QPushButton *closebutton;
    QLineEdit *custumkeybox;
    QLineEdit *clipkeybox;
    QLineEdit *publickeybox;
    QPushButton *fillbutton;
    QPushButton *okbutton;
    QLabel *label_11;
    QRadioButton *imgshackbutton;
    QLabel *label_5;
    QLabel *label_10;
    QSlider *quality;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QCheckBox *prntscrn_checkbox;
    QComboBox *prntscrn_comboBox;
    QLineEdit *prntkeybox;
    QLabel *label_17;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *OptionsWindow)
    {
        if (OptionsWindow->objectName().isEmpty())
            OptionsWindow->setObjectName(QString::fromUtf8("OptionsWindow"));
        OptionsWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/Tray"), QSize(), QIcon::Normal, QIcon::Off);
        OptionsWindow->setWindowIcon(icon);
        centralwidget = new QWidget(OptionsWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(30, 510, 61, 16));
        applybutton = new QPushButton(centralwidget);
        applybutton->setObjectName(QString::fromUtf8("applybutton"));
        applybutton->setGeometry(QRect(540, 540, 82, 26));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 390, 91, 16));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 121, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 110, 71, 16));
        overlaybutton = new QPushButton(centralwidget);
        overlaybutton->setObjectName(QString::fromUtf8("overlaybutton"));
        overlaybutton->setGeometry(QRect(140, 210, 41, 26));
        imagepathbox = new QLineEdit(centralwidget);
        imagepathbox->setObjectName(QString::fromUtf8("imagepathbox"));
        imagepathbox->setGeometry(QRect(150, 40, 421, 25));
        fullscreenkeybox = new QLineEdit(centralwidget);
        fullscreenkeybox->setObjectName(QString::fromUtf8("fullscreenkeybox"));
        fullscreenkeybox->setGeometry(QRect(150, 510, 113, 25));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 101, 16));
        hddkeybox = new QLineEdit(centralwidget);
        hddkeybox->setObjectName(QString::fromUtf8("hddkeybox"));
        hddkeybox->setGeometry(QRect(150, 420, 113, 25));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 480, 91, 16));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(30, 210, 91, 20));
        imgurbutton = new QRadioButton(centralwidget);
        imgurbutton->setObjectName(QString::fromUtf8("imgurbutton"));
        imgurbutton->setGeometry(QRect(20, 170, 101, 21));
        imgurbutton->setChecked(true);
        askcheckbox = new QCheckBox(centralwidget);
        askcheckbox->setObjectName(QString::fromUtf8("askcheckbox"));
        askcheckbox->setGeometry(QRect(20, 80, 301, 21));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 450, 71, 16));
        serverurlbox = new QLineEdit(centralwidget);
        serverurlbox->setObjectName(QString::fromUtf8("serverurlbox"));
        serverurlbox->setGeometry(QRect(150, 10, 421, 25));
        screendirpath = new QLineEdit(centralwidget);
        screendirpath->setObjectName(QString::fromUtf8("screendirpath"));
        screendirpath->setGeometry(QRect(150, 110, 421, 25));
        closebutton = new QPushButton(centralwidget);
        closebutton->setObjectName(QString::fromUtf8("closebutton"));
        closebutton->setGeometry(QRect(640, 540, 82, 26));
        custumkeybox = new QLineEdit(centralwidget);
        custumkeybox->setObjectName(QString::fromUtf8("custumkeybox"));
        custumkeybox->setGeometry(QRect(150, 390, 113, 25));
        clipkeybox = new QLineEdit(centralwidget);
        clipkeybox->setObjectName(QString::fromUtf8("clipkeybox"));
        clipkeybox->setGeometry(QRect(150, 450, 113, 25));
        publickeybox = new QLineEdit(centralwidget);
        publickeybox->setObjectName(QString::fromUtf8("publickeybox"));
        publickeybox->setGeometry(QRect(150, 480, 113, 25));
        fillbutton = new QPushButton(centralwidget);
        fillbutton->setObjectName(QString::fromUtf8("fillbutton"));
        fillbutton->setGeometry(QRect(140, 250, 41, 26));
        okbutton = new QPushButton(centralwidget);
        okbutton->setObjectName(QString::fromUtf8("okbutton"));
        okbutton->setGeometry(QRect(430, 540, 82, 26));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(30, 250, 59, 15));
        imgshackbutton = new QRadioButton(centralwidget);
        imgshackbutton->setObjectName(QString::fromUtf8("imgshackbutton"));
        imgshackbutton->setGeometry(QRect(20, 150, 101, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 420, 81, 16));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(30, 310, 46, 13));
        quality = new QSlider(centralwidget);
        quality->setObjectName(QString::fromUtf8("quality"));
        quality->setGeometry(QRect(100, 290, 160, 19));
        quality->setMaximum(2);
        quality->setSingleStep(1);
        quality->setPageStep(10);
        quality->setValue(1);
        quality->setSliderPosition(1);
        quality->setOrientation(Qt::Horizontal);
        quality->setInvertedAppearance(false);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(160, 320, 46, 13));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(90, 320, 46, 13));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(250, 320, 46, 13));
        prntscrn_checkbox = new QCheckBox(centralwidget);
        prntscrn_checkbox->setObjectName(QString::fromUtf8("prntscrn_checkbox"));
        prntscrn_checkbox->setGeometry(QRect(430, 290, 121, 17));
        prntscrn_comboBox = new QComboBox(centralwidget);
        prntscrn_comboBox->setObjectName(QString::fromUtf8("prntscrn_comboBox"));
        prntscrn_comboBox->setEnabled(false);
        prntscrn_comboBox->setGeometry(QRect(430, 320, 151, 22));
        prntkeybox = new QLineEdit(centralwidget);
        prntkeybox->setObjectName(QString::fromUtf8("prntkeybox"));
        prntkeybox->setGeometry(QRect(620, 290, 91, 20));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(30, 360, 101, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_17->setFont(font);
        OptionsWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(OptionsWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        OptionsWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(OptionsWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        OptionsWindow->setStatusBar(statusbar);

        retranslateUi(OptionsWindow);

        QMetaObject::connectSlotsByName(OptionsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *OptionsWindow)
    {
        OptionsWindow->setWindowTitle(QApplication::translate("OptionsWindow", "Options", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("OptionsWindow", "Fullscreen", 0, QApplication::UnicodeUTF8));
        applybutton->setText(QApplication::translate("OptionsWindow", "Apply", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("OptionsWindow", "To custom server", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OptionsWindow", "Custom Page url", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("OptionsWindow", "ScreenDir", 0, QApplication::UnicodeUTF8));
        overlaybutton->setText(QString());
        label_2->setText(QApplication::translate("OptionsWindow", "Images path", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("OptionsWindow", "To imgur/imgshack", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("OptionsWindow", "Overlay color", 0, QApplication::UnicodeUTF8));
        imgurbutton->setText(QApplication::translate("OptionsWindow", "ImGur", 0, QApplication::UnicodeUTF8));
        askcheckbox->setText(QApplication::translate("OptionsWindow", "Always ask where to save screenshots?", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("OptionsWindow", "To clipboard", 0, QApplication::UnicodeUTF8));
        closebutton->setText(QApplication::translate("OptionsWindow", "Close", 0, QApplication::UnicodeUTF8));
        fillbutton->setText(QString());
        okbutton->setText(QApplication::translate("OptionsWindow", "Ok", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("OptionsWindow", "Fill color", 0, QApplication::UnicodeUTF8));
        imgshackbutton->setText(QApplication::translate("OptionsWindow", "ImageShack", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("OptionsWindow", "To hard disk ", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("OptionsWindow", "Quality", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("OptionsWindow", "Default", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("OptionsWindow", "Low", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("OptionsWindow", "Good", 0, QApplication::UnicodeUTF8));
        prntscrn_checkbox->setText(QApplication::translate("OptionsWindow", "Whole screen enabled?", 0, QApplication::UnicodeUTF8));
        prntscrn_comboBox->clear();
        prntscrn_comboBox->insertItems(0, QStringList()
         << QApplication::translate("OptionsWindow", "Harddisk", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionsWindow", "Custom server", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionsWindow", "Clipboard", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionsWindow", "Public", 0, QApplication::UnicodeUTF8)
        );
        label_17->setText(QApplication::translate("OptionsWindow", "Keyboard hotkeys", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OptionsWindow: public Ui_OptionsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSWINDOW_H
