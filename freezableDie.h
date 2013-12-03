#include "die.h"

#ifndef FREEZABLEDIE
class FreezableDie : public Die {

protected:
  bool frozen;

public:
  FreezableDie(int);
  void freeze();
  void unfreeze();
  void roll();
  bool isFrozen();

};
#define FREEZABLEDIE
#endif
