
MAKEFILE      = Makefile

####### Compiler, tools and options

CXX           = g++
LINK          = $(CXX)
CXXFLAGS      = -Wall -Wextra -pedantic -Weffc++ -O2 -std=c++11 -Wall -W
LFLAGS        = $(CXXFLAGS)
INCPATH       = -I.

DEL_FILE      = rm -f

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		blackjack.cpp \
		deck.cpp \
		player.cpp \
		croupier.cpp \
		playerneverbust.cpp \
		card.cpp \
		playermaximizewins.cpp \
		cardlistdeserializer.cpp \
		round.cpp \
		playerfactory.cpp 
OBJECTS       = main.o \
		blackjack.o \
		deck.o \
		player.o \
		croupier.o \
		playerneverbust.o \
		card.o \
		playermaximizewins.o \
		cardlistdeserializer.o \
		round.o \
		playerfactory.o
TARGET        = Blackjack


first: all
####### Implicit rules

.SUFFIXES: .o .cpp

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS)

clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

####### Compile

main.o: main.cpp blackjack.hpp \
		deck.hpp \
		card.hpp \
		const.hpp \
		player.hpp \
		cardlistdeserializer.hpp \
		playerfactory.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

blackjack.o: blackjack.cpp blackjack.hpp \
		deck.hpp \
		card.hpp \
		const.hpp \
		player.hpp \
		croupier.hpp \
		playerneverbust.hpp \
		round.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o blackjack.o blackjack.cpp

deck.o: deck.cpp deck.hpp \
		card.hpp \
		const.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o deck.o deck.cpp

player.o: player.cpp player.hpp \
		card.hpp \
		const.hpp \
		deck.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o player.o player.cpp

croupier.o: croupier.cpp croupier.hpp \
		player.hpp \
		card.hpp \
		const.hpp \
		deck.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o croupier.o croupier.cpp

playerneverbust.o: playerneverbust.cpp playerneverbust.hpp \
		player.hpp \
		card.hpp \
		const.hpp \
		deck.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o playerneverbust.o playerneverbust.cpp

card.o: card.cpp card.hpp \
		const.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o card.o card.cpp

playermaximizewins.o: playermaximizewins.cpp playermaximizewins.hpp \
		player.hpp \
		card.hpp \
		const.hpp \
		deck.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o playermaximizewins.o playermaximizewins.cpp

cardlistdeserializer.o: cardlistdeserializer.cpp cardlistdeserializer.hpp \
		card.hpp \
		const.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o cardlistdeserializer.o cardlistdeserializer.cpp

round.o: round.cpp round.hpp \
		player.hpp \
		card.hpp \
		const.hpp \
		deck.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o round.o round.cpp

playerfactory.o: playerfactory.cpp playerfactory.hpp \
		player.hpp \
		card.hpp \
		const.hpp \
		deck.hpp \
		croupier.hpp \
		playerneverbust.hpp \
		playermaximizewins.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o playerfactory.o playerfactory.cpp


