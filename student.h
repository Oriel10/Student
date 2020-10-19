#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <set>
#include <map>
#include <exception>
typedef enum { Male, Female } Gender; 

class Student{
    std::map<std::string,int> grades;
    std::string student_name;
    std::string student_faculty;
    int student_semester;
    int student_age;
    Gender gender;
    static int Average;
public:
    Student(std::string name,std::string faculty, int semester, int age,Gender gender,std::map<std::string,int> grades) : 
    student_name(name),student_faculty(faculty),student_semester(semester),student_age(age),gender(gender),grades(grades){}
    Student(const Student& other) = default;
    Student& operator=(const Student& other) = default;
    virtual ~Student() = default;
    void addGrade(std::string grade_name,int grade);
    void setGrade(std::string grade_name,int grade);
    void deleteGrade(std::string grade_name);
    int getGrade(std::string grade_name) const;
    void printStudentData() const;
    class gradeNotInRange: public std::exception{
        const char* what() const noexcept override {
            return "grade has to be between 0 to 100";
        }
    };
    class gradeNotExist: public std::exception{
        const char* what() const noexcept override {
            return "grade doesn't exist";
        }
    };
    void gurtTestFunc() const;
};

#endif
