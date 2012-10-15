TEMPLATE = lib
TARGET = lib/lua0x

INCLUDEPATH += ..
SOURCES = module.cpp state.cpp lua0x.cpp

headers.path = $$PREFIX/include/lua0x
headers.files = *.h

target.path = $$PREFIX/lib

INSTALLS += target headers
