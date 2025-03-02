#include "Student.h"


// Default constructor initializing default values
Student::Student() {
    name = "ABCD";
    number = "000";
}

// Constructor with parameters
Student::Student(string name, string number) {
    this->name = name;
    this->number = number;
}

// Copy constructor (use const reference)
Student::Student(Student& s) {
    name = s.name;
    number = s.number;
}

// Getters (marked as const)
string Student::getName()  {
    return name;
}

string Student::getNumber()  {
    return number;
}

// Setters
void Student::setName(string n) {
    name = n;
}

void Student::setNumber(string u) {
    number = u;
}

// Less than function (marked as const and using < for comparison)
bool Student::lessThan( Student& s){
    return this->number < s.number;
}

// Print function (marked as const)
void Student::print(){
    cout << name << ", " << number << endl;
}