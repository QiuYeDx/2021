#-------------------------------------------------
#
# Project created by QtCreator 2021-04-05T15:29:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Coin
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainscene.cpp \
    mypushbutton.cpp \
    chooselevelscene.cpp \
    playscene.cpp \
    mycoin.cpp \
    dataconfig.cpp

HEADERS += \
        mainscene.h \
    mypushbutton.h \
    chooselevelscene.h \
    playscene.h \
    mycoin.h \
    dataconfig.h

FORMS += \
        mainscene.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    res/BackButtonSound.wav \
    res/ConFlipSound.wav \
    res/LevelWinSound.wav \
    res/TapButtonSound.wav \
    res/BackButton.png \
    res/BackButtonSelected.png \
    res/BoardNode.png \
    res/Coin0001.png \
    res/Coin0002.png \
    res/Coin0003.png \
    res/Coin0004.png \
    res/Coin0005.png \
    res/Coin0006.png \
    res/Coin0007.png \
    res/Coin0008.png \
    res/LevelCompletedDialogBg.png \
    res/LevelIcon.png \
    res/MenuSceneBg.png \
    res/MenuSceneStartButton.png \
    res/OtherSceneBg.png \
    res/PlayLevelSceneBg.png \
    res/Title.png \
    res/BackButtonSound.wav \
    res/ConFlipSound.wav \
    res/LevelWinSound.wav \
    res/TapButtonSound.wav \
    res/BackButton.png \
    res/BackButtonSelected.png \
    res/BoardNode.png \
    res/Coin0001.png \
    res/Coin0002.png \
    res/Coin0003.png \
    res/Coin0004.png \
    res/Coin0005.png \
    res/Coin0006.png \
    res/Coin0007.png \
    res/Coin0008.png \
    res/LevelCompletedDialogBg.png \
    res/LevelIcon.png \
    res/MenuSceneBg.png \
    res/MenuSceneStartButton.png \
    res/OtherSceneBg.png \
    res/PlayLevelSceneBg.png \
    res/Title.png

RESOURCES += \
    res.qrc
