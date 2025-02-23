#include <iostream>
#include "Date.h"
#include "Library.h"

using namespace std;

const string red("\033[0;31m");
const string def("\033[0m");

void testDate(Date& d1, Date& d2, bool shouldOverlap) {
    bool doesOverlap = false;
    
    cout << endl << "d1: ";
    d1.print();
    cout << endl << "d2: ";
    d2.print();
    cout << endl;
    
    if (d1.overlaps(d2)) {
        cout << "d1 overlaps d2" << endl;
        doesOverlap = true;
    } else {
        cout << "d1 does not overlap d2" << endl;
        doesOverlap = false;
    }

    if (doesOverlap == shouldOverlap) {
        cout << "Success!" << endl;
    } else {
        cout << red << "*****Failure!*****" << def << endl;
    }

    if (d2.overlaps(d1)) {
        cout << "d2 overlaps d1" << endl;
        doesOverlap = true;
    } else {
        cout << "d2 does not overlap d1" << endl;
        doesOverlap = false;
    }

    if (doesOverlap == shouldOverlap) {
        cout << "Success!" << endl;
    } else {
        cout << red << "*****Failure!*****" << def << endl;
    }
}

int main() {
    cout << "print"<<endl;

    return 0;
}

