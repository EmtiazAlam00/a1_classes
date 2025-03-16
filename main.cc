// main.cc
#include <iostream>
#include "a1-global.h"
#include "Library.h"

int main() {
    // Test case (a): Different days, should not overlap
    Date d1(2020, 1, 24, 11, 3);
    Date d2(2020, 1, 23, 11, 3);
    testDate(d1, d2, false);

    // Test case (b): Same year, month, day, but 3-hour difference, should not overlap
    Date d3(2020, 1, 24, 10, 3);
    Date d4(2020, 1, 24, 13, 3);
    testDate(d3, d4, false);

    // Test case (c): Same day, 1-hour difference, durations 1 and 3, should not overlap
    Date d5(2020, 1, 24, 10, 1);
    Date d6(2020, 1, 24, 11, 3);
    testDate(d5, d6, false);

    // Test case (d): Same day, 1-2 hours apart, durations cause overlap, should overlap
    Date d7(2020, 1, 24, 10, 2);
    Date d8(2020, 1, 24, 11, 2);
    testDate(d7, d8, true);

    // Test case (e): Same day, same hour, should overlap
    Date d9(2020, 1, 24, 11, 3);
    Date d10(2020, 1, 24, 11, 3);
    testDate(d9, d10, true);

    Library lib;
    populate(lib);
    testReservations(lib);

    return 0;
}
