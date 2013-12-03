#include<iostream>
#include "die.h"
#include "cup.h"

using namespace std;

int main(int argc, char *argv[])
{

    Cup myCup(5);
    
    for (int i = 0; i<10; ++i) {
        myCup.shake();
        for(auto d : myCup.getValues()) {
            cout << d << "  ";
        }
        cout << endl;
    }
    return 0;
}
