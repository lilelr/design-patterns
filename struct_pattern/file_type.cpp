//
// Created by YuXiao on 3/30/18.
// 组合模式
//

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class AbstractFile{
public:
    virtual void add(AbstractFile* element) = 0;
    virtual void remove(AbstractFile* element) = 0;
    virtual void display() = 0;

};

class Folder :public AbstractFile{
private:
    list<AbstractFile*> files_v_;
    string file_name_;
public:
    explicit Folder(const string& n):file_name_(n){

    }

    void add(AbstractFile* e) override {
        files_v_.push_back(e);
    }

    void remove(AbstractFile* element){
        files_v_.remove(element);
    }

    void display() {
        for(AbstractFile* item:files_v_){
            item->display();
        }
    }


};

class TextFile : public AbstractFile{
private:
    string file_name_;

public:
    explicit TextFile(const string& n):file_name_(n){

    }
     void add(AbstractFile* element) override {
        cout<<"sorry add"<<endl;
    }
     void remove(AbstractFile* element) override {
        cout<<"sorry remove"<<endl;
    }
     void display() override {
         cout<<"read textfile "<<file_name_<<endl;
    }
};

int main(){
    AbstractFile *folder,*t_file1,*t_file2;
    string folder_n = "happy";
    folder = new Folder(folder_n);
    string t_file1_name = "day1.txt";
    string t_file2_name = "day2.txt";
    t_file1 = new TextFile(t_file1_name);
    t_file2 = new TextFile(t_file2_name);
    folder->add(t_file1);
    folder->add(t_file2);
    folder->display();
    return 0;
}