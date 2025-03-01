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

// Main function to test the Student class
// int main() {
//     Student s1("Alice", "123");
//     Student s2("Bob", "456");
//     Student s3;

//     cout << "Student 1: "; s1.print();
//     cout << "Student 2: "; s2.print();
//     cout << "Default Student: "; s3.print();

//     cout << "Comparing Student 1 and Student 2: " << (s1.lessThan(s2) ? "Student 1 comes first" : "Student 2 comes first") << endl;
//     return 0;
// }
