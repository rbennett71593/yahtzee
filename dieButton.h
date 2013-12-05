#include <FL/Fl_Button.H>
#include <string>

class Fl_DieButton : public Fl_Button {

private:
	int ID;
public:
 Fl_DieButton(int x, int y, int w, int h, int dieID) 
 : Fl_Button(x,y,w,h,std::to_string(dieID).c_str()) {
   this->ID = dieID;
   this->copy_label(std::to_string(ID).c_str());
 }
 


    static void clicked(Fl_Widget *w, void *) {
         Fl_DieButton *myButton = (Fl_DieButton *)w;
         myButton->copy_label(std::to_string(100).c_str());
     }
    void update(Cup &cup){
	this->copy_label(std::to_string(cup.getValue(ID)).c_str());
    }

};
