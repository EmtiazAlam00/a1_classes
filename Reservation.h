#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include "Student.h"
#include "Room.h"
#include "Date.h"

using namespace std;

class Reservation{
    public:
    //3 argument constructor
    Reservation(Student* student, Room* room, Date& date);

    //getters
    Student* getStudent();
    Room* getRoom();
    Date getDate();

    //functions
    void print();
    bool lessThan(Reservation& res);

    private:
    Student* student;
    Room* room;
    Date date;
};
#endif
