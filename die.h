// declaration of Die class
#include<iostream>

#ifndef DIE
#define DIE
class Die {

public:
    Die();
    Die(int);
    virtual void roll();
    int getValue();
    friend std::ostream& operator<< (std::ostream&,  const Die& );
    friend int operator+ (const Die&, const Die&);
    friend int operator- (const Die&, const Die&);

    //friend gives access to private stuff

protected:

    bool active;
    int numSides;
    int currentValue;

};
#endif

