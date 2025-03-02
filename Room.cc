#include "Room.h"

//initialize member variables constructor
Room::Room(string name, int capacity, int computers, bool whiteboard){
  this->name = name;
  this->capacity = capacity;
  this->computers = computers;
  this->whiteboard = whiteboard;
}

//copy constructor
Room::Room(Room& r){
  name = r.name;
  capacity = r.capacity;
  computers = r.computers;
  whiteboard = r.whiteboard;
}

//setters
void Room::setName(string n){
  name = n;
}
void Room::setCaptacity(int c){
  capacity = c;
}
void Room::setComputers(int o){
  computers = o;
}
void Room::setWhiteboard(bool w){
  whiteboard = w;
}

//getters
string Room::getName(){
  return name;
}
int Room::getCapacity(){
  return capacity;
}
int Room::getComputers(){
  return computers;
}
bool Room::hasWhiteboard(){
  return whiteboard;
}

//functions
bool Room::meetsCriteria(int capacity, int computers, bool whiteboard){
  if(this->capacity >= capacity && this->computers >= computers && (this-> whiteboard == true || whiteboard == false)){
        return true;
    } else {
        return false;
        }
}

bool Room::lessThan(Room& r){
  if(this->name.compare(r.name) < 0)
        return true;
    else
        return false;
}

void Room::print(){
  cout<<getName()<<","<<getCapacity()<<","<<getComputers()<<","<<hasWhiteboard()<<endl;
}