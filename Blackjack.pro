TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++11

SOURCES += main.cpp \
    blackjack.cpp \
    deck.cpp \
    player.cpp \
    croupier.cpp \
    playerneverbust.cpp \
    card.cpp \
    cardlistreader.cpp \
    playermaximizewins.cpp

HEADERS += \
    blackjack.hpp \
    deck.hpp \
    player.hpp \
    croupier.hpp \
    playerneverbust.hpp \
    card.hpp \
    cardlistreader.hpp \
    playermaximizewins.hpp

QMAKE_CXXFLAGS += -Wall
QMAKE_CXXFLAGS += -Wextra
QMAKE_CXXFLAGS += -pedantic
QMAKE_CXXFLAGS += -Weffc++
