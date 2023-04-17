/* 
This program print the calender of 2023

Steps:
1. First it creates a loop that goes through each month of the year 2023.
2. It then calls the function get_month_long to find out how many days are in the current month.
3. It then creates a loop that goes through each day of the current month.
4. It then prints out the day and the day of the week.
5. The day of the week is incremented each time by one, and when it reaches 7 it is reset to 1.
*/

#include<iostream>
using namespace std;

bool year_is_leap(int year){ 
    // A year is a leap year if it is divisible by 4 
    // and not by 100, or if it is divisible by 400.
	return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
};

int get_month_long(int month, int year){
	int month_long;
	int is_leap_year;
	// april, july, september and november have 30 days
	if((month == 4) || (month == 6) || (month == 9) || (month == 11)){
		month_long = 30;
	}
	// february have 29 days if year is leap, otherwise have 28 days
	else if(month == 2){
		is_leap_year = year_is_leap(year);
		if(is_leap_year){
			month_long = 29;
		}
		else month_long = 28;
	}
	// the rest have 31 days
	else month_long = 31;

	return month_long;
};

int main(){
	int monthCounter, dayCounter, monthLong; int weekDay = 1;
	cout << "Calendario Año 2023" << endl;
	for (monthCounter = 1; monthCounter <= 12; monthCounter++){
		monthLong = get_month_long(monthCounter, 2023);

		cout << endl << "mes: " << monthCounter << endl;

		for(dayCounter = 1; dayCounter <= monthLong; dayCounter++){
			cout << dayCounter << ":" << weekDay << " ";
			if(weekDay < 7){weekDay++;}
			else weekDay = 1;
		};
	};
};


