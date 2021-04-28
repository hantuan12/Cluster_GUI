TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
        menu_options.c \
        shared_memory.c

HEADERS += \
    menu_options.h \
    shared_memory.h \
    types_definitions.h

