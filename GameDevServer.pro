TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++14 -pthread
LIBS += -pthread

CONFIG -= app_bundle
CONFIG -= qt

include(sfml.pri)

SOURCES += \
        main.cpp \
    sources/server.cpp \
    sources/connexion/gateway.cpp \
    sources/connexion/player.cpp \
    sources/connexion/packet.cpp \
    sources/instance.cpp \
    sources/waitinginstance.cpp

HEADERS += \
    headers/server.hpp \
    headers/connexion/gateway.hpp \
    headers/connexion/player.hpp \
    headers/connexion/packet.hpp \
    headers/instance.hpp \
    headers/waitinginstance.hpp \
    headers/utilities/smartptr/smartptr.hpp \
    headers/utilities/smartptr/policies/deleter.hpp \
    headers/utilities/smartptr/policies/ownership.hpp \
    headers/utilities/smartptr/policies/storage.hpp \
    headers/utilities/smartptr/policies/deleter.hpp \
    headers/utilities/smartptr/policies/ownership.hpp \
    headers/utilities/smartptr/policies/storage.hpp
