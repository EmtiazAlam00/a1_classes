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
    
}
