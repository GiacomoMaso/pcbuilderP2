TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Magazzino.cpp \
        case.cpp \
        componente.cpp \
        contenitore.cpp \
        cpu.cpp \
        gpu.cpp \
        item.cpp \
        main.cpp \
        memoria.cpp \
        psu.cpp \
        ram.cpp \
        rom.cpp \
        sconto.cpp \
        scontrino.cpp \
        smartptr.cpp

HEADERS += \
    Magazzino.h \
    case.h \
    componente.h \
    contenitore.h \
    cpu.h \
    gpu.h \
    item.h \
    memoria.h \
    psu.h \
    ram.h \
    rom.h \
    sconto.h \
    scontrino.h \
    smartptr.h
