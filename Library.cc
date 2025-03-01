#include "Library.h"
#include "Reservation.h"

// no-arguement constructor
Library:: Library(){
    students = new Student*[MAX_ARRAY]();
    reservations = new Reservation*[MAX_ARRAY]();
    quantityRoom = 0;
    quantityRes = 0;
    quantityStu = 0;

    //set room array pointers to nullptr, no need to use destructor because its static
    for (int i = 0; i < MAX_ARRAY; ++i){
        room[i] = nullptr;
    }
}

//destructor
Library::~Library(){
    //delete dynamically allocated student objects
    for (int i = 0; i < quantityStu; ++i){
        delete students[i];
    }
    delete[] students; //deallocate the students array

    for (int i = 0; i < quantityRes; ++i){
        delete reservations[i];
    }
    delete[] reservations;
}

bool Library:: addStudent(const string& name, const string& number){
    //Check if there is space in the array
    if (quantityStu >= MAX_ARRAY){
        return false;
    }
    //create a new student object
    Student* newStudent = new Student(name, number);
    int i = quantityStu - 1; // Start from the last element
    while (i >= 0 && students[i]->lessThan(*newStudent)) {
        // Shift elements to the right to make space for the new student
        students[i + 1] = students[i];
        --i;
    }
    // Insert the new student at the correct position
    students[i + 1] = newStudent;
    ++quantityStu;

    return true;// student added successfully
}

bool Library::addRoom(string name, int capacity = 1, int computers = 0, bool whiteboard = false) {
    // Check if the room array is full
    if (quantityRoom >= MAX_ARRAY) {
        return false; // No more space to add a room
    }

    // Create a new Room object
    Room* newRoom = new Room(name, capacity, computers, whiteboard);

    // Find the correct position to insert the new room (sorted order)
    int i = quantityRoom - 1; // Start from the last element
    while (i >= 0 && room[i]->lessThan(*newRoom)) {
        room[i + 1] = room[i]; // Shift elements to the right
        --i;
    }

    // Insert the new room at the correct position
    room[i + 1] = newRoom;

    // Increment the room count
    ++quantityRoom;

    return true; // Room added successfully
}

bool Library :: getStudent(const string& name, Student** student){
    for (int i = 0; i < quantityStu; ++i) {
        if (students[i]->getName() == name) {
            // If student is found, store the pointer in the provided student pointer and return true
            *student = students[i];
            return true;
        }
    }
    return false;
}

bool Library :: getRoom(const string& roomName, Room** room){
    for(int i = 0; i < quantityRoom; ++i){
        if(room[i]->getName() == roomName){
            *room = room[i];
            return true;
        }
    }
    return false;
}

bool Library :: isFree(const string& room, Date& date){
    Room* r = nullptr;
    //check if the room exists in the library
    if(!getRoom(room, &r)){
        return false;
    }
    //checks if any reservations overlaps with the given date
    for (int i = 0; i < quantityRes; ++i){
        if (reservations[i]->overlaps(room, date)){
            return false; // room is booked at the given time.
        }
    }
    return true;
}

bool Library :: makeReservation(const string& student, const string& room, Date& date){
    //check if the student exists
    Student* s = nullptr;
    if(!getStudent(student, &s)){ return false;}
    //check if the room exists
    Room* r = nullptr;
    if(!getRoom(room, &r)){ return false;}
    //check if the room is free at the given date
    if(!isFree(room, date)){
        return false;
    }
    if(quantityRes >= MAX_ARRAY){
        return false;
    }
    reservations[quantityRes] = new Reservation(student, room, date);
    quantityRes++;
    return true;
}
