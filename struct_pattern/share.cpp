//
// Created by YuXiao on 3/30/18.
//

//

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Coordinates{
private:
    int x_;
    int y_;
public:
    Coordinates(int x,int y):x_(x),y_(y){

    }

    int getX_() const {
        return x_;
    }

    void setX_(int x_) {
        Coordinates::x_ = x_;
    }

    int getY_() const {
        return y_;
    }

    void setY_(int y_) {
        Coordinates::y_ = y_;
    }

};

class IgoChessman{
public:
    virtual string& get_color()=0;
    void locate(Coordinates* coord){
        cout<<this->get_color();
            cout<<"pos: "<<coord->getX_()<<" ";
               cout <<coord->getY_()<<endl;
    }

};


class BlackIgoChessman:public IgoChessman{
public:
    string &get_color()override{
        string c = "black";
        return c;
    }


};

