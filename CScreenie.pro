# -------------------------------------------------
# Project created by QtCreator 2010-01-17T15:52:12
# -------------------------------------------------
TARGET = CScreenie
CONFIG -= app_bundle
TEMPLATE = app
win32:LIBS += -lcurl \
    -lssl \
    -lcrypto \
    -lws2_32 \
    -lgdi32 \
    -lcrypt32 \
    -lz \
    -lwsock32 \
    -lwinmm \
    -t


INCLUDEPATH += /usr/local/include/curl
INCLUDEPATH += C:/openssl_1.0.1c/include
SOURCES += main.cpp \
    mainwindow.cpp \
    RectangleWidget.cpp \
    globalshortcutmanager.cpp \
    globalshortcutmanager_x11.cpp \
    dialog.cpp \
    OptionsWindow.cpp \
    uploader.cpp \
    about.cpp
HEADERS += mainwindow.h \
    RectangleWidget.h \
    globalshortcutmanager.h \
    globalshortcuttrigger.h \
    dialog.h \
    OptionsWindow.h \
    uploader.h \
    about.h
FORMS += \
    dialog.ui \
    optionswindow.ui \
    about.ui
OTHER_FILES +=
win32 {
    SOURCES -= globalshortcutmanager_x11.cpp
    SOURCES += globalshortcutmanager_win.cpp
}
RESOURCES += cscreenie.qrc
 RC_FILE = icon.rc
