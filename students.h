#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <set>
#include <map>
typedef enum { Male, Female } Gender; 

class Student{
    std::map<,std::string,int> grades;
    std::string student_name;
    std::string student_faculty;
    int student_semester;
    int student_age;
    Gender gender;
    static int Average;
public:
    Student(std::string name,std::string faculty, int semester, int age,Gender gender,std::map<,std::string,int> grades = default) : 
    student_name(name),student_faculty(faculty),semester(student_semester),age(student_age),gender(gender),grades(grades){}
    Student(const Student& other) = default;
    Student& operator=(const Student& other) = default;
    virtual ~Student() = default;
    void addGrade(std::string grade_name,int grade);
    void setGrade(std::string grade_name,int grade);
    void deleteGrade(std::string grade_name);
    int getGrade(std::string grade_name);
    int printStudentData() const;
};

#ifndef