QT += widgets

SOURCES += \
    TekMonitor.cpp \
    main.cpp \
    ../../src/Core.cpp \
    ../../src/ModuleCPU.cpp \
    ../../src/ModuleRAM.cpp \
    ../../src/ModuleTime.cpp \
    ../../src/ModuleUserHost.cpp \
    ../../src/ModuleKernel.cpp \
    ../../src/ModuleNetwork.cpp \
    ../../src/Parser.cpp

INCLUDEPATH += ../../include

HEADERS += \
    TekMonitor.h
