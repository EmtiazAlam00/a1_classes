_**Room Booking System**_

This project is a Room Booking System implemented using C++. The system allows students (users) to book rooms based on availability and
specific criteria, such as capacity, computers, and whiteboards. The project demonstrates fundamental OOP concepts, including class design, constructors, destructors, dynamic memory allocation, and sorting.

_**Learning Outcomes**_
- The basics of Classes in C++.
- How to define and use constructors and member functions effectively.
- Implementation of sorting and searching algorithms within class methods.
- Memory management using dynamic allocation and deallocation.
- Handling user input and validation
- Class interactions and relationships
- Efficient data storage and retrieval

**Files**

**Student.h / Student.cpp**: Contains the Student class with member variables for student name and number. Includes constructors, getters, setters, and a function to compare students alphabetically.

**Room.h / Room.cpp**: Contains the Room class with attributes like room name, capacity, number of computers, and whether the room has a whiteboard. Includes methods to check room availability based on user criteria.

**Date.h / Date.cpp**: Contains the Date class, which tracks the year, month, day, hour, and duration for a reservation. Also includes a function to check if two dates overlap.

**Reservation.h / Reservation.cpp**: Contains the Reservation class that links a Student, a Room, and a Date together. Includes methods to compare reservations and check for overlaps.

**Library.h / Library.cpp**: Contains the Library class that manages collections of students, rooms, and reservations. Includes functions for adding, searching, and booking rooms.

**a1-global.cc**: Contains helper functions for testing date overlaps and reservations.


**Features**

**Student**: Represents a student with a name and number, with sorting functionality based on student number.

**Room**: Represents a library room, with attributes for capacity, computers, and a whiteboard. Allows room search based on user criteria.

**Date**: Tracks a date for reservations, including the hour and duration. Checks for overlaps with other reservations.
Reservation: Links a student, room, and date. Provides functionality to check if the reservation overlaps with another.

**Library**: Manages a collection of students, rooms, and reservations. Includes functions to add students and rooms, check room availability, and make reservations

--
--
