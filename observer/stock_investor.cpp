//
// Created by YuXiao on 3/29/18.
//
#include <vector>
#include <string>
#include <iostream>
using namespace std;
// the target to be observed

class Stock;
class Investor{
public:
    virtual void response(Stock* stock) const  =0;
};

class Stock{
public:
    vector<Investor*> investors;
    string stock_name;
    double price;

    explicit Stock(string name,double pri):stock_name(name),price(pri){

    }

    void attach(Investor* investor){
        this->investors.push_back(investor);
    }
    void detach(Investor* investor){
//        for(vector<Investor*>::iterator iter = this->investors.begin();iter!=this->investors.end();iter++){
//            ConcreteInvestor* tp = static_cast<ConcreteInvestor*> (*iter);
//            ConcreteInvestor* ti = static_cast<ConcreteInvestor*> (investor);
//            if(tp->investor_name == ti->investor_name)    {
//                this->investors.erase(iter);
//            }
//        }
    }

    void set_price(double t_price){
        price = t_price;
        if(price>100){
            notify_investor();
        }
    }

    void notify_investor(){
        for(Investor* investor:this->investors){
            investor->response(this);
        }
    }
};

class ConcreteInvestor : public Investor{
public:
    string investor_name;
    explicit  ConcreteInvestor(string name):investor_name(name){
    }

     void response(Stock* stock) const override {
        cout<<"obsevering "<<stock->price<<endl;
    }
};

int main(){
    Investor* investor1,*investor2;
    string investor1_name="lele";
    string investor2_name="lin";
    investor1 = new ConcreteInvestor(investor1_name);
    investor2 = new ConcreteInvestor(investor2_name);
    string stock_name= "海尔";
    Stock stock(stock_name,10);
    stock.attach(investor1);
    stock.attach(investor2);
    stock.set_price(200);
    return 0;


}