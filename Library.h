#include "Student.h"
#include "Room.h"
#include "Reservation.h"
#include "Date.h"
#define MAX_ARRAY 100
#include <iostream>
#include <string>

using namespace std;

class Library{
    public:
    //default constructor, initializes member variables
    Library();
    //destructor
    ~Library();

    bool addStudent(const string& name, const string& number);
    bool addRoom(string name, int capacity, int computers, bool whiteboard);
    bool getStudent(const string& name, Student** student);
    bool getRoom(const string& roomName, Room** room);
    bool isFree(const string& room, Date&);
    bool makeReservation(const string& student, const string& room, Date&);



    private:
    Student** students; //dynamically allocated array of student pointers
    Room* room[MAX_ARRAY]; //static allocated array of room pointers
    Reservation** reservations; //dynamically allocated array of reservation pointer
    int quantityRoom;
    int quantityStu;
    int quantityRes;
};