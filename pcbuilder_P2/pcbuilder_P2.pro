TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        case.cpp \
        componente.cpp \
        cpu.cpp \
        gpu.cpp \
        item.cpp \
        main.cpp \
        memoria.cpp \
        psu.cpp \
        ram.cpp \
        rom.cpp \
        sconto.cpp

HEADERS += \
    case.h \
    componente.h \
    cpu.h \
    gpu.h \
    item.h \
    memoria.h \
    psu.h \
    ram.h \
    rom.h \
    sconto.h
