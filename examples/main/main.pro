ROOT = ../..

TEMPLATE = app
TARGET = $$ROOT/bin/main

INCLUDEPATH += $$ROOT/..
LIBS += -L$$ROOT/lib -llua0x
SOURCES = main.cpp
