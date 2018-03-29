//
// Created by YuXiao on 3/29/18.
//

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class SearchContext{
public:
    void set_successor(SearchContext* searchContext){
        this->successor = searchContext;
    }
    virtual void search(string& key_word) const = 0;
protected:
    SearchContext* successor;
};

class JavaSearchContext: public SearchContext{
public:
    void search(string& key_word) const{
        if(key_word == "java"){
            cout<<"search java"<<endl;
        }else{
            this->successor->search(key_word);
        }
    }
};

class CSearchContext: public SearchContext{
public:
    void search(string& key_word) const{
        if(key_word == "c"){
            cout<<"search c"<<endl;
        }else if(this->successor== nullptr){
           cout<<"no answer"<<endl;
        }
    }
};

int main(){
    SearchContext* java_context, *c_context;
    java_context = new JavaSearchContext();
    c_context = new CSearchContext();
    java_context->set_successor(c_context);
    c_context->set_successor(nullptr);
    string key_word = "java";
    java_context->search(key_word);
    key_word = "c";
    java_context->search(key_word);

}


