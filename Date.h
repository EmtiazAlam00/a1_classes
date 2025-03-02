#ifndef DATE_H
#define DATE_H

#define MAX_DURATION 3
#include <iostream>
#include <string>

using namespace std;

class Date {
		
	public:
		//constructor
		Date();
		Date(int y, int m, int d, int h = 12, int u = 2); // Default values for h and u
	
				
		//setters
		void setDay( int);
		void setMonth(int);
		void setYear(int);
		void setDate(int y, int m, int d, int h, int u);
		void setDate(Date&);
		void setHour(int);
		void setDuration(int);
		
		//getters
		int getDay();
		int getMonth();
		int getYear();
		const string& getMonthName();
		int getHour();
		int getDuration();
		
		//other
		bool lessThan(Date& d);
		void print();
		bool overlaps(Date& d);
	
	private:
		//functions
		int getMaxDay();
	
	
		//variables
		int day;
		int month;
		int year;
		int hour;
		int duration;
		
		const string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		const string smonths[12]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul","Aug", "Sep", "Oct", "Nov", "Dec"};
	
};
#endif
