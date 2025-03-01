#include "Date.h"

Date::Date(){
	setDate(1901,1,1,12,2);
}

Date::Date(int y, int m, int d, int h, int u) {
    setDate(y, m, d, h, u);
}


//setters
void Date::setDay(int d){
	int max = getMaxDay();
	if (d>max) d=max;
	if (d<1) d=1;
	day = d;
}

void Date::setMonth(int m){
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}

void Date::setYear(int y){
	if (y < 1901) y = 1901;
	year = y;
}

void Date::setDate(int y, int m, int d, int h, int u){
	setMonth(m);
	setDay(d);
	setYear(y);
	setHour(h);
	setDuration(u);
}

void Date::setDate(Date& d){
	setDate(d.year, d.month, d.day, d.hour, d.duration);
}

void Date::setHour(int h){
	if (h > 23) h = 23;
	if (h < 0) h = 0;
	hour =h;
}

void Date::setDuration(int u){
	if(u < 1) u = 1;
	if(u > MAX_DURATION) u = 3;
	duration = u;
}


//getters
int Date::getDay(){ return day; }
int Date::getMonth(){ return month; }
int Date::getYear(){ return year; }
const string& Date::getMonthName(){return months[month-1];}
int Date::getHour(){ return hour;}
int Date::getDuration(){ return duration; }

//other

bool Date::lessThan(Date& d){
	if (year == d.year){
		if (month == d.month){
			if(day == d.day){
				return hour < d.hour;
			} else{
				return day < d.day;
			}
		} else{
			return month < d.month;
		}
	}else {
		return year < d.year;
	}
}

void Date::print(){
	cout << getMonthName()<<" "<<getDay()<<", "<<getYear() << ", Hour: " << getHour()<< ", duration: "<< getDuration() <<endl;
}

bool Date::overlaps(Date& d){
	if (year == d.year && month == d.month && day == d.day){
		int this_end = hour + duration; //End hour of this Date
		int d_end = d.hour + d.duration; //End hour of d Date
		//check if the two time ranges overlap
		if ((hour < d_end) && (d.hour <this_end)){
			return true;
		}
	} return false;
}

int Date::getMaxDay(){
	switch(getMonth()){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}

void Date::testDate(Date& d1, Date& d2, bool shouldOverlap) {
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
        cout << "*****Failure!*****" << endl;  // Removed 'red' and 'def'
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
        cout << "*****Failure!*****" << endl;  // Removed 'red' and 'def'
    }
}

const string Date::months[12] = {"January", "February", "March", "April", "May", "June",
	"July", "August", "September", "October", "November", "December"};

const string Date::smonths[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
	 "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

int main() {
    // Test case (a): Different days, should not overlap
    Date d1(2020, 1, 24, 11, 3);  // January 24, 2020, 11:00 AM, Duration 3
    Date d2(2020, 1, 23, 11, 3);  // January 23, 2020, 11:00 AM, Duration 3
    Date::testDate(d1, d2, false);  // Should not overlap

    // Test case (b): Same year, month, day, but 3-hour difference, should not overlap
    Date d3(2020, 1, 24, 10, 3);  // January 24, 2020, 10:00 AM, Duration 3
    Date d4(2020, 1, 24, 13, 3);  // January 24, 2020, 1:00 PM, Duration 3
	Date::testDate(d3, d4, false);  // Should not overlap

    // Test case (c): Same day, 1-hour difference, durations 1 and 3, should not overlap
    Date d5(2020, 1, 24, 10, 1);  // January 24, 2020, 10:00 AM, Duration 1
    Date d6(2020, 1, 24, 11, 3);  // January 24, 2020, 11:00 AM, Duration 3
	Date::testDate(d5, d6, false);  // Should not overlap

    // Test case (d): Same day, 1-2 hours apart, durations cause overlap, should overlap
    Date d7(2020, 1, 24, 10, 2);  // January 24, 2020, 10:00 AM, Duration 2
    Date d8(2020, 1, 24, 11, 2);  // January 24, 2020, 11:00 AM, Duration 2
	Date::testDate(d7, d8, true);  // Should overlap

    // Test case (e): Same day, same hour, should overlap
    Date d9(2020, 1, 24, 11, 3);  // January 24, 2020, 11:00 AM, Duration 3
    Date d10(2020, 1, 24, 11, 3); // January 24, 2020, 11:00 AM, Duration 3
	Date::testDate(d9, d10, true);  // Should overlap

	Date d11(2020, 1, 24, 10, 1);  // January 24, 2020, 10:00 AM, Duration 1
    Date d12(2020, 1, 24, 12, 1);  // January 24, 2020, 12:00 PM, Duration 1
    Date::testDate(d11, d12, true);

    return 0;
}