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

int main() {
    // Create rooms using the constructor
    Room room1("Conference Room", 20, 5, true);
    Room room2("Classroom A", 30, 10, false);
    Room room3("Library", 50, 20, true);

    // Display room details using the print function
    cout << "Room details:" << endl;
    room1.print();
    room2.print();
    room3.print();

    // Test the setter functions
    cout << "\nUpdating Room 1 details..." << endl;
    room1.setName("New Conference Room");
    room1.setCaptacity(25);
    room1.setComputers(8);
    room1.setWhiteboard(false);

    // Display updated room details
    room1.print();

    // Test the getter functions
    cout << "\nGetting Room 2 details using getters..." << endl;
    cout << "Name: " << room2.getName() << endl;
    cout << "Capacity: " << room2.getCapacity() << endl;
    cout << "Computers: " << room2.getComputers() << endl;
    cout << "Has Whiteboard: " << room2.hasWhiteboard() << endl;

    // Test the meetsCriteria function
    cout << "\nChecking if Room 3 meets the criteria (capacity >= 40, computers >= 10, whiteboard = true)..." << endl;
    if (room3.meetsCriteria(40, 10, true)) {
        cout << "Room 3 meets the criteria." << endl;
    } else {
        cout << "Room 3 does not meet the criteria." << endl;
    }

    // Test the lessThan function
    cout << "\nComparing Room 1 and Room 2 (using lessThan)..." << endl;
    if (room1.lessThan(room2)) {
        cout << "Room 1 comes before Room 2 alphabetically." << endl;
    } else {
        cout << "Room 1 does not come before Room 2 alphabetically." << endl;
    }

    return 0;
}