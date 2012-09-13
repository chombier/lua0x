

TEMPLATE = app

INCLUDEPATH += ..

contains(TEMPLATE, lib) {
    TARGET = lib/lua0x
}

contains(TEMPLATE, app) {
    TARGET = bin/test
    SOURCES += main.cpp
}

QMAKE_CXXFLAGS += -std=c++11

CONFIG += link_pkgconfig

SOURCES += module.cpp state.cpp
PKGCONFIG += luabind lua5.1
