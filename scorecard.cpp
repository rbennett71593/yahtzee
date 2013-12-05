#include "scorecard.h"

Scorecard::Scorecard(){
  for(int i = 0; i <= 13; i++)
    scores.push_back(0);
}

void Scorecard::clear(){
  for(int& i : scores)
    i = 0;
  resetRolls();
}

int Scorecard::getScore(int category){
  return scores[category];
}

int Scorecard::getTotalScore(){
  int total = 0;
  for(int& i : scores)
    total += i;
  return total;
}

int Scorecard::sum(vector<int>& dice){
  int total = 0;
  for(int& i : dice)
    total += i;
  return total;
}

int Scorecard::count(int value, vector<int>&dice){
  int total = 0;
  for (int die : dice)
    if (die == value)
      total += die;
  return total;
}

int Scorecard::getRolls(){
  return rolls;
}
void Scorecard::incRoll(){
  rolls++;
}
void Scorecard::resetRolls(){
  rolls = 0;
}

void Scorecard::validate(int &category, vector<int> dice){
  switch (category){
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
    scores[category] = (category * count(category,dice));
    break; 
  case 7: //3 of a kind
    for (int trial = 1; trial <= 6; trial++){
      if (count(trial, dice) <= 3){
	scores[category] = sum(dice);
      }
    }
    break;
  case 8: //4 of a kind
    for (int trial = 1; trial <=6; trial++){
      if (count(trial, dice) <= 4){
	scores[category] = sum(dice);
      }
    }
    break;
  case 9: //full house
    bool two, three;
    for (int trial = 1; trial <= 6; trial++){
      if (count(trial, dice) == 3){
	three = true;
      }
      if (count(trial, dice) == 2){
	two = true;
      }
    }
    if (two && three) {
      scores[category] = 25;
    }
    break;
  case 10://Small straight
    scores[category] = 25;   
    break;
  case 11://Large straight
    scores[category] = 35;
    break;
  case 12: {//Yahtzee
    const int check = dice[0];
    bool good = true;
    for (auto &die : dice)
      if (check != die)
	good = false;
    if (good)
      if (scores[category] = 50)
	scores[category] += 100;
      else
	scores[category] = 50;
    break;
  }
  case 13://Chance
    scores[category] = sum(dice);
    break;
  }
  resetRolls();
}

string Scorecard::printScore(){
  string output;
  const string newline = "\n";
  const string tab = "#     ";
  output = "########################";
  output += newline;
  output += "# A-Upper Part" + newline;

    for (int i = 1; i <=6; i++){
      output += tab + to_string(i) + "-";
      if (getScore(i) == 0)
	output += "sum " + to_string(i) +"'s" + newline;
      else
	output += "score: " + to_string(getScore(i)) + newline;
    }
    int subtotal = 0;
    for (int i = 1; i <= 6; i++){
      subtotal += getScore(i);
    }
    output += "#SubTotal: " + to_string(subtotal);

    output += newline + "# B-Lower Part" + newline;
    if (getScore(7) == 0)
      output += tab + "7-3 of a kind" + newline;
    else
      output += tab + "7-score: " + to_string(getScore(7)) + newline;

    if (getScore(8) == 0)
      output += tab + "8-4 of a kind" + newline;
    else
      output += tab + "8-score: " + to_string(getScore(8)) + newline;

    if (getScore(9) == 0)
      output += tab + "9-Full House" + newline;
    else
      output += tab + "9-score: " + to_string(getScore(9)) + newline;

    if (getScore(10) == 0)
      output += tab + "10-Small Straight" + newline;
    else
      output += tab + "10-score: " + to_string(getScore(10)) + newline;

    if (getScore(11) == 0)
      output += tab + "11-Large Straight" + newline;
    else
      output += tab + "11-score: " + to_string(getScore(11)) + newline;

    if (getScore(12) == 0)
      output += tab + "12-Yahtzee" + newline;
    else
      output += tab + "12-score: " + to_string(getScore(12)) + newline;

    if (getScore(13) == 0)
      output += tab + "13-Chance" + newline;
    else
      output += tab + "13-score: " + to_string(getScore(13)) + newline;

    
    output += "#Total: " + to_string(getTotalScore()) + newline;


  return output;
}

