ROOT = ../..

TEMPLATE = lib
TARGET = $$ROOT/lib/test

INCLUDEPATH += $$ROOT/..
SOURCES = test.cpp

LIBS += -L$$ROOT/lib -llua0x 

