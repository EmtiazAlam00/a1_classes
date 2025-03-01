#include "Date.h"

const std::string red("\033[0;31m");
const std::string def("\033[0m");
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


int main() {
	// 1. Test Date Overlaps
	Date d1(2020,1,24,11,3);
	Date d2(2020,1,23,11,3);
	testDate(d1, d2, false);  // Different days, should NOT overlap

	Date d3(2021,5,10,9,3);
	Date d4(2021,5,10,12,3);
	testDate(d3, d4, false);  // Same day, 3-hour difference, should NOT overlap

	Date d5(2021,5,10,9,1);
	Date d6(2021,5,10,10,3);
	testDate(d5, d6, false);  // 1-hour difference, non-overlapping durations

	Date d7(2021,5,10,9,2);
	Date d8(2021,5,10,10,2);
	testDate(d7, d8, true);   // 1-hour difference, overlapping durations

	Date d9(2021,5,10,9,2);
	Date d10(2021,5,10,9,2);
	testDate(d9, d10, true);  // Same start time, should overlap

	return 0;
}
