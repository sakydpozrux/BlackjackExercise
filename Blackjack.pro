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
    round.cpp \
    card.cpp \
    cardlistreader.cpp

HEADERS += \
    blackjack.hpp \
    deck.hpp \
    player.hpp \
    croupier.hpp \
    playerneverbust.hpp \
    round.hpp \
    card.hpp \
    cardlistreader.hpp

QMAKE_CXXFLAGS += -Wall
QMAKE_CXXFLAGS += -Wextra
QMAKE_CXXFLAGS += -pedantic
QMAKE_CXXFLAGS += -Weffc++
