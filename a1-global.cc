#include <iostream>
#include <string>
#include "Room.h"
#include "Student.h"
#include "Date.h"
#include "Library.h"
#include "Reservation.h"

const std::string red("\033[0;31m");
const std::string def("\033[0m");

void testDate(Date& d1, Date& d2, bool shouldOverlap){

    bool doesOverlap = false;
    cout<<endl<<"d1: ";
    d1.print();
    cout<<endl<<"d2: ";
	d2.print();
    cout<<endl;
    if (d1.overlaps(d2)){	
		cout<<"d1 overlaps d2"<<endl;
        doesOverlap = true;
	}else{
		cout<<"d1 does not overlap d2"<<endl;
        doesOverlap = false;
	}

    if (doesOverlap==shouldOverlap){
        cout<<"Success!"<<endl;
    }else{
        cout<<red<<"*****Failure!*****"<<def<<endl;
    }

    if (d2.overlaps(d1)){	
		cout<<"d2 overlaps d1"<<endl;
        doesOverlap = true;
	}else{
		cout<<"d2 does not overlap d1"<<endl;
        doesOverlap = false;
	}

    if (doesOverlap==shouldOverlap){
        cout<<"Success!"<<endl;
    }else{
        cout<<red<<"*****Failure!*****"<<def<<endl;
    }
}

string students[5] = {"Bob", "Alice", "Nolan","Garrett", "Maddie"};
string numbers[5] = {"000000000", "111111111", "222222222","333333333", "444444444"};
string rooms[5] = {"Square", "Rectangle", "Circle","Triangle", "Ellipse"};

void populate(Library& lib){
    
    // add some Students
    for (int i = 0; i <5; ++i){
        lib.addStudent(students[i],numbers[i]);
    }

    // add some rooms
    lib.addRoom("Square");
    lib.addRoom("Circle", 2);
    lib.addRoom("Triangle", 3, 3);
    lib.addRoom("Ellipse",4,0,true);
    lib.addRoom("Rectangle",3,1,true);
}

void line(){
    cout<<endl<<endl;
}



void testReservations(Library& lib){
    //first make some dates that we can make overlap
    Date d1(2021,9,25,10,2);
    Date d2(2021,9,25,11,1);
    Date d3(2021,9,25,12,2);
    Date d4(2021,9,26,12,2);

    cout<<"Reserving "<<rooms[0]<<" for "<<students[0]<<" on "<<endl;
    d1.print();

    if (lib.isFree(rooms[0],d1)){
        cout << "It's free"<<endl<<endl;
    }else{
        cout <<red<<"Error** It's not free"<<def<<endl<<endl;
    }
    lib.makeReservation(students[0],rooms[0],d1);
    
    cout<<"Reserving "<<rooms[1]<<" for "<<students[1]<<" on "<<endl;
    d2.print();

    if (lib.isFree(rooms[1],d2)){
        cout << "It's free"<<endl<<endl;
    }else{
        cout <<red<<"Error** It's not free"<<def<<endl<<endl;
    }
    lib.makeReservation(students[1],rooms[1],d2);

    cout<<"Reserving "<<rooms[1]<<" for "<<students[2]<<" on "<<endl;
    d2.print();

    if (lib.isFree(rooms[1],d2)){
        cout << red<< "Error** It's free"<<def<<endl<<endl;
    }else{
        cout <<"It's not free"<<endl<<endl;
    }
    lib.makeReservation(students[2],rooms[1],d2);

    cout<<"Print reservations (should be 2)"<<endl<<endl;
    //lib.printReservations();

    cout<<"Reserving "<<rooms[1]<<" for "<<students[2]<<" on "<<endl;
    d1.print();

    if (lib.isFree(rooms[1],d1)){
        cout << red << "Error** It's free"<<def<<endl<<endl;
    }else{
        cout <<"It's not free"<<endl<<endl;
    }
    lib.makeReservation(students[2],rooms[1],d1);

    cout<<"Print reservations (should be 2)"<<endl<<endl;
    //lib.printReservations();

    cout<<"Reserving "<<rooms[1]<<" for "<<students[2]<<" on "<<endl;
    d3.print();

    if (lib.isFree(rooms[1],d3)){
        cout << "It's free"<<endl<<endl;
    }else{
        cout <<red<<"Error** It's not free"<<def<<endl<<endl;
    }
    lib.makeReservation(students[2],rooms[1],d3);

    cout<<"Print reservations (should be 3)"<<endl<<endl;
    //lib.printReservations();

    cout<<"Reserving "<<rooms[0]<<" for "<<students[3]<<" on "<<endl;
    d4.print();

    if (lib.isFree(rooms[0],d4)){
        cout << "It's free"<<endl<<endl;
    }else{
        cout <<red<<"Error** It's not free"<<def<<endl<<endl;
    }
    lib.makeReservation(students[3],rooms[0],d4);

    cout<<"Print reservations (should be 4)"<<endl<<endl;
    //lib.printReservations();

}



int main(){
    // Test case (a): Different days, should not overlap
    Date d1(2020, 1, 24, 11, 3);  // January 24, 2020, 11:00 AM, Duration 3
    Date d2(2020, 1, 23, 11, 3);  // January 23, 2020, 11:00 AM, Duration 3
    testDate(d1, d2, false);  // Should not overlap

    // Test case (b): Same year, month, day, but 3-hour difference, should not overlap
    Date d3(2020, 1, 24, 10, 3);  // January 24, 2020, 10:00 AM, Duration 3
    Date d4(2020, 1, 24, 13, 3);  // January 24, 2020, 1:00 PM, Duration 3
    testDate(d3, d4, false);  // Should not overlap

    // Test case (c): Same day, 1-hour difference, durations 1 and 3, should not overlap
    Date d5(2020, 1, 24, 10, 1);  // January 24, 2020, 10:00 AM, Duration 1
    Date d6(2020, 1, 24, 11, 3);  // January 24, 2020, 11:00 AM, Duration 3
    testDate(d5, d6, false);  // Should not overlap

    // Test case (d): Same day, 1-2 hours apart, durations cause overlap, should overlap
    Date d7(2020, 1, 24, 10, 2);  // January 24, 2020, 10:00 AM, Duration 2
    Date d8(2020, 1, 24, 11, 2);  // January 24, 2020, 11:00 AM, Duration 2
    testDate(d7, d8, true);  // Should overlap

    // Test case (e): Same day, same hour, should overlap
    Date d9(2020, 1, 24, 11, 3);  // January 24, 2020, 11:00 AM, Duration 3
    Date d10(2020, 1, 24, 11, 3); // January 24, 2020, 11:00 AM, Duration 3
    testDate(d9, d10, true);  // Should overlap

    Library lib;
    populate(lib);
    testReservations(lib);

    return 0;
}