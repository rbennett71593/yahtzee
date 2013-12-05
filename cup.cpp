#include "cup.h"

Cup::Cup() {
    numDice = 0;
}

Cup::Cup(int numDice)  {
    this->numDice = numDice;
    for (int i = 0; i < numDice; i++) {
        FreezableDie d(6);
        this->add(d);
    }
}

void Cup::shake() {
    for(auto &i : dieList) {
        i.roll();
    }
}

void Cup::freeze(int dieID) {
  dieList[dieID].freeze();
}
void Cup::unfreeze(int dieID){
  dieList[dieID].unfreeze();
}

bool Cup::isFrozen(int dieID){
  return dieList[dieID].isFrozen();
}

void Cup::unfreezeAll(){
  for(auto &d : dieList){
    d.unfreeze();
  }
}

void Cup::add(FreezableDie& newDie) {
    dieList.push_back(newDie);
}


vector<int> Cup::getValues() {
    vector<int> res;
    for(auto &d : dieList) {
        res.push_back(d.getValue());
    }
    return res;
}

int Cup::getValue(int dieID){
  vector<int> dice = this->getValues();
  return dice[dieID];
}
