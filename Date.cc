#include "Date.h"

Date::Date(){
	setDate(1901,1,1,12,2);
}

Date::Date(int y, int m, int d, int h, int u){
	setDate(y,m,d, h, u);
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

-- delete me

