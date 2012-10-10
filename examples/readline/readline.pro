
ROOT = ../..

TEMPLATE = lib
TARGET = $ROOT/lib/readline

INCLUDEPATH += $$ROOT/..
DEPENDPATH += $$ROOT/..

SOURCES = readline.cpp

LIBS += -lreadline -L$$ROOT/lib -llua0x
