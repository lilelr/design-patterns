//
// Created by YuXiao on 3/29/18.
//

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Command{
public:
    virtual void execute() = 0;

};

class MenuItem{
private:
    string name_;
    Command* command_;

public:
    explicit MenuItem(string n):name_(n){

    }

    Command* get_command(){
        return command_;
    }
    void set_command(Command* co){
        command_ = co;
    }
    void click(){
        command_->execute();
    }
};

class Menu{
public:
    vector<MenuItem*> items;
    void add_menu_item(MenuItem* item){
        items.push_back(item);
    }
};

class BoardScreen{
private:
    Menu* menu_;
    MenuItem* open_item_;
public:
    BoardScreen(){
        menu_ = new Menu();
        string open_s = "打开";
        open_item_ = new MenuItem(open_s);
        menu_->add_menu_item(open_item_);
    }

    void open(){
        cout<<"打开窗口"<<endl;
    }
    Menu* get_menu(){
        return menu_;
    }
};

class OpenCommand:public Command{
private:
    BoardScreen* screen_;
public:
    explicit OpenCommand(BoardScreen* s):screen_(s){

    }

    void execute() override {
        screen_->open();
    }
};

int main(){
    BoardScreen* screen = new BoardScreen();
    Menu* menu = screen->get_menu();
    MenuItem* open_item = menu->items[0];
    Command* open_command = new OpenCommand(screen);
    open_item->set_command(open_command);
    open_item->click();
}