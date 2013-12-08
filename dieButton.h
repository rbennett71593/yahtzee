#include <FL/Fl_Button.H>
#include "cup.h"
#include <string>

class Fl_DieButton : public Fl_Button {

private:
	int ID;
public:
 Fl_DieButton(int x, int y, int w, int h, int dieID) : Fl_Button(x,y,w,h,std::to_string(dieID).c_str()) {
	  this->ID = dieID;
	  this->copy_label(std::to_string(ID).c_str());
      }

 void clicked(Cup &cup) {
     if (cup.isFrozen(ID)){
         cup.unfreeze(ID);
     }else{
         cup.freeze(ID);
     }
     update(cup);
 }

 void update(Cup &cup){
   if (cup.isFrozen(ID)){
       string val;
       val = "x" + std::to_string(cup.getValue(ID)) + "x";
       this->copy_label(val.c_str());
  }else{
	this->copy_label(std::to_string(cup.getValue(ID)).c_str());
  }
 }
};
