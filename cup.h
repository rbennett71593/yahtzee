#include<vector>
#include "freezableDie.h"

using namespace std;

class Cup {

private:

    vector<FreezableDie> dieList;
    int numDice;

public:

    Cup();
    Cup(int);
    void shake();
    void freeze(int);
    void unfreeze(int);
    bool isFrozen(int);
    void unfreezeAll();
    void add(FreezableDie&);
    vector<int> getValues();
    int getValue(int);

};
