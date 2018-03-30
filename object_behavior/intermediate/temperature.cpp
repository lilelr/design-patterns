//
// Created by YuXiao on 3/29/18.
//

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Dialog;

class Widget{
protected:
    Dialog* dialog_;
public:
    void set_dialog(Dialog* dialog){
        dialog_ = dialog;
    }
    virtual void changed() = 0;
};

class Dialog{
public:
     void show_dialog(){
        cout<<"main window"<<endl;
    }
    virtual void widget_changed(Widget* widget) =0 ;
};

class EditBox:public Widget{
private:
    double value  = 50;
public:
    void set_text(double& val){
        value = val;
    }
    void changed() override {
        this->dialog_->widget_changed(this);
    }

};
class TemperatureConvectorDialog: public Dialog{

public:
    explicit  TemperatureConvectorDialog(){

    }
    EditBox* editBox;

    void widget_changed(Widget* widget) override {
        cout<<"edit box changed"<<endl;
    }
};

int main(){
    TemperatureConvectorDialog* t_dialog;
    EditBox* editBox = new EditBox();
    t_dialog = new TemperatureConvectorDialog();
    editBox->set_dialog(t_dialog);

    t_dialog->editBox = editBox;
    editBox->changed();


}