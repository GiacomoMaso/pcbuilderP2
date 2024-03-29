QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#TEMPLATE = app
#CONFIG += console c++11
#CONFIG -= app_bundle
#CONFIG -= qt
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x050800



SOURCES += \
        Magazzino.cpp \
        case.cpp \
        componente.cpp \
        contenitore.cpp \
        controller.cpp \
        cpu.cpp \
        formview.cpp \
        gpu.cpp \
        item.cpp \
        listamagazzinoview.cpp \
        main.cpp \
        mainwindow.cpp \
        memoria.cpp \
        psu.cpp \
        ram.cpp \
        rom.cpp \
        schedamadre.cpp \
        selectaddobjectview.cpp \
        smartptr.cpp \
        viewsingleitem.cpp

HEADERS += \
    Magazzino.h \
    case.h \
    componente.h \
    contenitore.h \
    controller.h \
    cpu.h \
    formview.h \
    gpu.h \
    item.h \
    listamagazzinoview.h \
    mainwindow.h \
    memoria.h \
    psu.h \
    ram.h \
    rom.h \
    schedamadre.h \
    selectaddobjectview.h \
    smartptr.h \
    viewsingleitem.h

RESOURCES += \
    Resource.qrc
