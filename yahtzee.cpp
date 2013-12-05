#include<iostream>
#include "cup.h"
#include "scorecard.h"
#include <vector>
#include <sstream>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/fl_ask.H>
#include "dieButton.h"

using namespace std;

Scorecard sc;
Cup cup(5);
Fl_DieButton *d0;
Fl_DieButton *d1;
Fl_DieButton *d2;
Fl_DieButton *d3;
Fl_DieButton *d4;

void newGame(){
  sc.clear();
  cup.unfreezeAll();
}
void newGameCB(Fl_Widget *, void*){
  newGame();
}

void exitcb(Fl_Widget *, void *) {
  exit(0);
}

void score(int category){
  sc.validate(category, cup.getValues());
  cout << sc.printScore() << endl;
}

void roll(){
  if(sc.getRolls() <= 2){
    cup.shake();
    d0->update(cup);
    d1->update(cup);
    d2->update(cup);
    d3->update(cup);
    d4->update(cup);
  }
  sc.incRoll();
}

void rollCB(Fl_Widget *, void *){
  roll();
}

int main(int argc, char *argv[])
{
  //create window
  Fl_Window *window = new Fl_Window(600,400);


  //cout << "Welcome!" << endl;
  newGame();
  Fl_Box *title = new Fl_Box(5,5,200,60,"Yahtzee!");
  title->box(FL_UP_BOX);
  title->labelfont(FL_BOLD+FL_ITALIC);
  title->labelsize(20);
  title->labeltype(FL_SHADOW_LABEL);

  Fl_Button *newgameB = new Fl_Button(5,370,100,25, "New Game");
  newgameB->callback(newGameCB,0);
  Fl_Button *rollB = new Fl_Button(110,370,100,25, "Roll");
  rollB->callback(rollCB,0);
  Fl_Button *quitB = new Fl_Button(495,370,100,25, "Quit");
  quitB->callback(exitcb,0);

  d0 = new Fl_DieButton(20,100,100,100,0);
  d0->callback(Fl_DieButton::clicked);
  d1 = new Fl_DieButton(125,100,100,100,1);
  d1->callback(Fl_DieButton::clicked);
  d2 = new Fl_DieButton(230,100,100,100,2);
  d2->callback(Fl_DieButton::clicked);
  d3 = new Fl_DieButton(335,100,100,100,3);
  d3->callback(Fl_DieButton::clicked);
  d4 = new Fl_DieButton(440,100,100,100,4);
  d4->callback(Fl_DieButton::clicked);
  
  /*  
    else if (op == "K"){ //freeze dice
	string id;
	for(int i = 1; i < commands.size(); i++){
	  id = commands[i];
	  ycup.freeze(stoi(id)-1);
	}
	cout << displayDice(ycup);
    }
    else if (op == "X"){ //unfreeze
	string id;
	for(int i = 1; i < commands.size(); i++){
	  id = commands[i];
	  ycup.unfreeze(stoi(id)-1);
	}
	cout << displayDice(ycup);
    }
    else if(op == "S"){
      score(p1, stoi(commands[1]), ycup);
      ycup.unfreezeAll();
    }
  */

  window->end();
  window->show(argc,argv);
  return Fl::run();
}
