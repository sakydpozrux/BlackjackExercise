TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++11

SOURCES += main.cpp \
    blackjack.cpp \
    deck.cpp \
    cardlist.cpp

HEADERS += \
    blackjack.hpp \
    deck.hpp \
    cardlist.hpp

QMAKE_CXXFLAGS += -Wall
QMAKE_CXXFLAGS += -Wextra
QMAKE_CXXFLAGS += -pedantic
QMAKE_CXXFLAGS += -Weffc++
