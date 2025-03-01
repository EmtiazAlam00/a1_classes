#include <iostream>
#include <string>
#include "Room.h"
#include "Student.h"
#include "Date.h"

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

    return 0;
}