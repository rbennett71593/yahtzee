#include "die.h"
#include<cstdlib>
#include<iostream>

Die::Die() : numSides(6) {
}

Die::Die(int numSides) {
    this->numSides = numSides;
    srand(time(NULL));
}

void Die::roll() {
  if (active){
      currentValue = (rand() % numSides) + 1;
  }
}


int Die::getValue() {
    return currentValue;
}

std::ostream& operator<< (std::ostream& os, const Die& d) {
    os << d.currentValue;
    // note you do not need to use getValue() because of friend
    return os;
}

int operator +(const Die& d1, const Die& d2) {
  return d1.currentValue + d2.currentValue;
}

int operator -(const Die& d1, const Die& d2) {
  return d1.currentValue - d2.currentValue;
}
