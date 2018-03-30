//
// Created by YuXiao on 3/30/18.
//

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Window{
public:
    virtual void display() = 0;
};

class SimpleWindow: public Window{
public:
    void display() override {
        cout<<"show window"<<endl;
    }
};

class WindowDecorator : public Window{
private:
    Window* window_;
public:
    WindowDecorator(Window* window):window_(window){

    }

    void display() override {
        window_->display();
    }
};

class ScrollbarDecorator:public WindowDecorator{
public:
    explicit ScrollbarDecorator(Window* window1):WindowDecorator(window1){

    }
    void display() override {
        this->set_scroll_bar();
        WindowDecorator::display();
    }

    void set_scroll_bar(){
        cout<<"set bar"<<endl;
    }
};

int main(){
    Window* windowS = new SimpleWindow();
    Window* sb = new ScrollbarDecorator(windowS);
    sb->display();
}