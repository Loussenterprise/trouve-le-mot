QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dbmanager.cpp \
    eppisode.cpp \
    home.cpp \
    main.cpp \
    mainwindow.cpp \
    scores.cpp

HEADERS += \
    dbmanager.h \
    eppisode.h \
    home.h \
    mainwindow.h \
    scores.h

FORMS += \
    eppisode.ui \
    home.ui \
    mainwindow.ui \
    scores.ui

TRANSLATIONS += \
    trouve-le-mot_fr_FR.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

STATECHARTS +=
