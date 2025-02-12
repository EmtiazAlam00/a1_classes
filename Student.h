#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student {

public:
    // Default constructor
    Student();
    
    // Constructor with parameters
    Student(string name, string number);
    
    // Copy constructor
    Student(Student& s);
    
    // Getters
    string getName() ;
    string getNumber() ;
    
    // Setters
    void setName(string n);
    void setNumber(string u);
    
    // Less than function
    bool lessThan(Student& s) ;
    
    // Print function
    void print() ;

    private:
    string name;
    string number;
};
#endif // STUDENT_H