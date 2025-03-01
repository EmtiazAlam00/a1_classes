#include "Reservation.h"

Reservation:: Reservation(Student* s, Room* r, Date& d){
    student = s;
    room = r;
    date.setDate(d);
}

//getters
Student* Reservation::getStudent(){ return student;}
Room* Reservation::getRoom(){ return room;}
Date Reservation::getDate(){ return date;}

//functions
bool Reservation :: lessThan(Reservation& res){
    return date.lessThan(res.date);
}

bool Reservation :: overlaps(const string& r, Date& d){
    return (room->getName() == r) && date.overlaps(d);
}

void Reservation :: print(){
    cout<< "Reservation Detail:\n";
    cout << "Student: ";
    student->print();
    cout << "Room: ";
    cout << room->getName() << endl;
    cout << "Date: ";
    date.print();
    cout << "---------------------------" << endl;
}