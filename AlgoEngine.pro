#-------------------------------------------------
#
# Project created by QtCreator 2017-11-30T19:28:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AlgoEngine
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


SOURCES += \
    Algorithms/algorithm.cpp \
    Blocks/block.cpp \
    Blocks/dfsblock.cpp \
    additionqt.cpp \
    main.cpp \
    mainwindow.cpp \
    availableblocklist.cpp \
    globalvararea.cpp \
    Vars/var.cpp \
    Blocks/dfssettingsdialog.cpp \
    Algorithms/dfsalgorithm.cpp \
    blockmanager.cpp \
    blockviewer.cpp \
    viewarea.cpp \
    globalvarareaviewer.cpp \
    Vars/integervar.cpp \
    addvardialog.cpp \
    delvardialog.cpp \
    showvarsdialog.cpp \
    Vars/intarrayvar.cpp \
    Blocks/sortblock.cpp \
    Algorithms/sortalgorithm.cpp \
    Blocks/sortsettingsdialog.cpp

HEADERS += \
    Algorithms/algorithm.h \
    Blocks/block.h \
    Blocks/dfsblock.h \
    additionqt.h \
    mainwindow.h \
    availableblocklist.h \
    globalvararea.h \
    Vars/var.h \
    Blocks/dfssettingsdialog.h \
    Algorithms/dfsalgorithm.h \
    blockmanager.h \
    blockviewer.h \
    viewarea.h \
    globalvarareaviewer.h \
    Vars/integervar.h \
    addvardialog.h \
    delvardialog.h \
    showvarsdialog.h \
    Vars/intarrayvar.h \
    Blocks/sortblock.h \
    Algorithms/sortalgorithm.h \
    Blocks/sortsettingsdialog.h

FORMS += \
        mainwindow.ui \
    Blocks/dfssettingsdialog.ui \
    addvardialog.ui \
    delvardialog.ui \
    showvarsdialog.ui \
    Blocks/sortsettingsdialog.ui
