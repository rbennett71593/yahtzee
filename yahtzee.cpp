#include<iostream>
#include "cup.h"
#include "scorecard.h"
#include <vector>
#include <sstream>
#include <string>

using namespace std;


void newGame(Scorecard &sc, Cup &cup){
  sc.clear();

  cup.unfreezeAll();
}

string displayDice(Cup &cup){
  stringstream output;
  output << "Your Dice: ";
  vector<int> dice = cup.getValues();
  for (int i = 0; i < dice.size(); i++){
    output << dice.at(i);
    if (i < dice.size() - 1)
      output << " - ";
  }
  output << endl;

  string startTab = "           ";
  string tab = "   ";
  output << startTab;
  for (int j = 0; j < dice.size(); j++){
    if(cup.isFrozen(j))
      output << "^";
    else
      output << " ";
    if (j < dice.size() - 1)
      output << tab;
  }
  output << endl;
  return output.str();

}

vector<string> split(string& line){
  //split code derived from example by AusCBloke on StackOverflow
  vector<string> commands;
   typedef string::size_type string_size;
   string_size i = 0; 
   while (i != line.size()) {
      while (i != line.size() && isspace(line[i]))
         ++i;
      string_size j = i;
      while (j != line.size() && !isspace(line[j]))
         j++; 
      if (i != j) {
         commands.push_back(line.substr(i, j - i));
         i = j;
      }
   }
   return commands;
}

vector<string> input(istream& in){
  string line;
  getline(in, line);
  return split(line);
}

void score(Scorecard &sc, int category, Cup &cup){
  sc.validate(category, cup.getValues());
  cout << sc.printScore() << endl;
}


int main(int argc, const char *argv[])
{
  //Makes a cup with 5 dice
  Cup ycup(5);
  Scorecard p1;
  cout << "Welcome!" << endl;
  newGame(p1, ycup);
  
  vector<string> commands = input(cin);
  string op = commands[0];
  while (op != "Q"){
    if(op == "G"){
	newGame(p1, ycup);
	cout << "New Game" << endl;
    }
    else if(op == "R"){
	ycup.shake();
	cout << displayDice(ycup);
    }
      
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

  





    //next Command
    commands = input(cin);
    op = commands[0];
  }

  return 0;
}
