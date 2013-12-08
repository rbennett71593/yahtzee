ARCH = $(shell uname)

ifeq ($(ARCH),Darwin)
	CXX	 = g++
	LINK     = g++
else
	CXX	 = g++-4.8
	LINK     = g++-4.8
endif

DEBUG    = -g
CXXFLAGS = $(shell fltk-config --cxxflags ) -std=c++11 -I.
LDFLAGS  = $(shell fltk-config --ldflags )
LDSTATIC = $(shell fltk-config --ldstaticflags )

OBJS = cup.o die.o freezableDie.o scorecard.o dieButton.o

.o:	$@.cpp $@.h
	$(CXX) $(CXXFLAGS) $(DEBUG) -c $@.cpp

dieButton.o:	dieButton.h
	$(CXX) $(CXXFLAGS) $(DEBUG) -c dieButton.cpp


yahtzee: 	yahtzee.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) yahtzee.cpp $(OBJS) $(LDFLAGS) -o yahtzee


clean: 
	rm -f *.o 2> /dev/null
	rm -f yahtzee