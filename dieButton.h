#include <FL/Fl_Button.H>
#include <string>

class dieButton : public Fl_Button {

private: 
  int value;

public:
 dieCounterButton(int x, int y, int w, int h, char *label, int dieID) 
 : Fl_Button(x,y,w,h,label) {
   this->count = init;
   this->copy_label(std::to_string(dieID).c_str());
 }
 
    int getValue() { return  ; }

     static void clicked(Fl_Widget *w, void *) {
         dieButton *myButton = (dieButton *)w;
         myButton->increment();
         int value = myButton->getValue();
         myButton->copy_label(std::to_string(value).c_str());
     }

};
