#include "freezableDie.h"
#include <cstdlib>
#include <iostream>

FreezableDie::FreezableDie(int numSides){
  this->numSides = 6;
  frozen = false;
  srand(time(NULL));
}

void FreezableDie::roll(){
  if (!frozen){
    currentValue = (rand() % numSides) + 1;
  } 
}

void FreezableDie::freeze(){
  frozen = true;
}

void FreezableDie::unfreeze(){
  frozen = false;
}

bool FreezableDie::isFrozen(){
  return frozen;
}
