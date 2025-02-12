#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

using namespace std;

class Room{
  public:
  //constructor
  Room(string name = "room1", int capacity = 3, int computers = 5, bool whiteboard = true);
  
  //copy constructor
  Room(Room&);

  //getters
  string getName();
  int getCapacity();
  int getComputers();
  bool hasWhiteboard();

  //setters
  void setName(string);
  void setCaptacity(int);
  void setComputers(int);
  void setWhiteboard(bool);

  //functions
  bool meetsCriteria(int capacity = 3, int computers = 5 , bool whiteboard = true);
  bool lessThan(Room& r);
  void print();

  private:
    //variables
    string name;
    int capacity;
    int computers;
    bool whiteboard;
};
#endif