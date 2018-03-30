//
// Created by YuXiao on 3/29/18.
//

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Person;

class Teacher;

class Student;

class AwardCheck {
public:
    virtual void visit(Teacher *t) = 0;

    virtual void visit(Student *t) = 0;

};

class Person {
public:
    virtual void accept(AwardCheck *award_check)=0;


};

class Teacher : public Person {
private:
    string teacher_name_;
    int paper_amount_;
public:
    const string &getTeacher_name_() const {
        return teacher_name_;
    }

    void setTeacher_name_(const string &teacher_name_) {
        Teacher::teacher_name_ = teacher_name_;
    }

    int getPaper_amount_() const {
        return paper_amount_;
    }

    void setPaper_amount_(int paper_amount_) {
        Teacher::paper_amount_ = paper_amount_;
    }

    void accept(AwardCheck *award_check) override {
        award_check->visit(this);
    }
};

class Student : public Person {
private:
    string stu_name_;
    int paper_amount_;
    int score_;
public:
    const string &getStu_name_() const {
        return stu_name_;
    }

    void setStu_name_(const string &stu_name_) {
        Student::stu_name_ = stu_name_;
    }

    int getPaper_amount_() const {
        return paper_amount_;
    }

    void setPaper_amount_(int paper_amount_) {
        Student::paper_amount_ = paper_amount_;
    }

    const int &getScore_() const {
        return score_;
    }

    void setScore_(const int &score_) {
        Student::score_ = score_;
    }

    void accept(AwardCheck *award_check) override {
        award_check->visit(this);
    }
};

class ExcellentAwardCheck : public AwardCheck {

public:
    void visit(Teacher *t) override {
        if (t->getPaper_amount_() > 4) {
            cout << "Teacher " << t->getTeacher_name_() << " excellent!" << endl;
        }
    }

    void visit(Student *t) override {
        if (t->getScore_() > 90) {
            cout << "Student  " << t->getStu_name_() << "  excellent!" << endl;

        }
    }
};

int main() {
    vector<Person *> candidates;
    Student *stu = new Student();
    stu->setScore_(100);
    string str = "lele";
    stu->setStu_name_(str);

    Teacher *te = new Teacher();
    te->setPaper_amount_(10);
    string t_name = "ert";
    te->setTeacher_name_(t_name);

    ExcellentAwardCheck* awardCheck = new ExcellentAwardCheck();
    candidates.push_back((Person *&&) stu);
    candidates.push_back((Person *&&) te);
    for(vector<Person*>::iterator iter = candidates.begin();iter!=candidates.end();iter++){
        (*iter)->accept(awardCheck);
    }

    return 0;
}