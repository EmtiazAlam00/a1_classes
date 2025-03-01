a1: a1-global.o Student.o Room.o Date.o Reservation.o Library.o
	g++ -o a1 a1-global.o Student.o Room.o Date.o Reservation.o Library.o

a1-global.o: a1-global.cc Student.h Room.h Date.h Reservation.h Library.h
	g++ -c a1-global.cc

Student.o: Student.cc Student.h
	g++ -c Student.cc
	
Room.o: Room.cc Room.h
	g++ -c Room.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

Reservation.o: Reservation.cc Reservation.h
	g++ -c Reservation.cc

Library.o: Library.cc Library.h
	g++ -c Library.cc

clean:
	rm -f *.o a1