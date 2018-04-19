TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11 -pthread
LIBS += -pthread

CONFIG -= app_bundle
CONFIG -= qt

include(sfml.pri)

SOURCES += \
        main.cpp \
    sources/server.cpp \
    sources/connexion/gateway.cpp

HEADERS += \
    headers/server.hpp \
    headers/connexion/gateway.hpp
