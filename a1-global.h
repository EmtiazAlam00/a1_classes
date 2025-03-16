// a1-global.h
#ifndef A1_GLOBAL_H
#define A1_GLOBAL_H

#include <string>
#include "Date.h"
#include "Library.h"

void testDate(Date& d1, Date& d2, bool shouldOverlap);
void populate(Library& lib);
void testReservations(Library& lib);

#endif // A1_GLOBAL_H
