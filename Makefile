CPP = g++ 
CPPFLAGS = -std=c++0x -g
#LDLIBS = -framework OpenGL -framework GLUT -framework Foundation -L/usr/local/lib -ljpeg -lm

OBJS = die.o cup.o freezableDie.o scorecard.o

all:	dietest

.o:	$@.cpp $@.h
	$(CPP) $(CPPFLAGS) -c $@.cpp

dietest:	dietest.cpp $(OBJS)
	$(CPP) $(CPPFLAGS) dietest.cpp $(OBJS) -o dietest

yahtzee:	yahtzee.cpp $(OBJS)
	$(CPP) $(CPPFLAGS) yahtzee.cpp $(OBJS) -o yahtzee