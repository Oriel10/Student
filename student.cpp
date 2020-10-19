#include "students.h"
#include <assert.h>
#include <utility>
#include <iostream>
using namespace std;


void Student::addGrade(std::string grade_name,int grade){
    assert(grade_name != "");
    if(grade < 0 || grade > 100){
        throw gradeNotInRange();
    }
    grades.insert(pair<string,int>(grade_name,grade));
}

void Student::setGrade(std::string grade_name,int grade){
    assert(grade_name != "");
    if(grade < 0 || grade > 100){
        throw gradeNotInRange();
    }
    auto it = grades.find(grade_name);
    if(it == grades.end()){
        addGrade(grade_name,grade);
    }
    it->second = grade;
}

void Student::deleteGrade(std::string grade_name){
    auto it = grades.find(grade_name);
    if(it == grades.end()){
        return;
    }
    grades.erase(it);
}

int Student::getGrade(std::string grade_name) const{
    auto it = grades.find(grade_name);
    if(it == grades.end()){
        throw gradeNotExist();
    }
    return it->second;
}

void Student::printStudentData() const{
    int average = 0;
    for(pair<string,int> p : grades){
        average += p.second;
    }
    cout<<"student name: "<<student_name<<endl<<
        "student age: "<<student_age<<endl<<
        "student semester: "<<student_semester<<endl<<
        "student_faculty: "<<student_faculty<<endl<<
        "student gender: "<<gender<<endl<<    
        "student average: "<<average;
}