/*
This program calculates the day of the week for a date given by the user.

Steps:
1- User inputs a date between 01/01/2021 and 31/12/2050.
2- The program checks if the date is valid, if not, it terminates.
3- The program calculates the day of the week for the input date.
4- The program prints the day of the week for the input date. 
*/
// Author: Cristian Hernández (12/04/2021) (USM Student)

#include <iostream>
using namespace std;

bool year_is_leap(int year){ 
	// leap year are divisible by 4
	// if are divisible by 100, they also need be divisible by 400 to be leap 
	if(year % 100 == 0){
		if(year % 400 == 0){
			return true;
		}
		else return false;
	};

	if( (year % 4) == 0){
		return true;
	}
	else return false;
};

int get_month_long(int month, int year){
	// april, july, september and november have 30 days
	// february have 29 days if year is leap, otherwise have 28 days
	// the rest have 31 days
	if((month == 4) || (month == 6) || (month == 9) || (month == 11)){
		return 30;
	}
	else if(month == 2){
		if(year_is_leap(year)){
			return 29;
		}
		else return 28;
	}
	else return 31;
};

int days_diff_for_year_2021(int year){
    int yearDiff = year - 2021;
    int yearLeap = (yearDiff + 1) / 4;
    int yearNotLeap = yearDiff - yearLeap;
    int daysDiffForYears = (365*yearNotLeap) + (366*yearLeap); 

    return daysDiffForYears;
};

int days_diff_for_month_2021(int month, int year){
    int daysDiffForMonths = 0;
    int fixedMonth = month - 1; // to avoid the current month
    for(int i = 1; i <= fixedMonth; i++){
        daysDiffForMonths += get_month_long(i, year);
    }
    return daysDiffForMonths;
};

int days_diff_for_day_2021(int day){
    return day - 1; // to avoid the current day
};

int days_diff_to_2021(int day, int month, int year){
    return (days_diff_for_year_2021(year) 
    + days_diff_for_month_2021(month, year) 
    + days_diff_for_day_2021(day));
};

int get_day_of_week_to_2021(int day, int month, int year){
    int daysDiff = days_diff_to_2021(day, month, year);
    int firstDay = 4; // 2021-01-01 was a Friday, so the first day of the week is 4
    int dayOfWeek = ((firstDay + daysDiff) % 7);
    return dayOfWeek;
};

int main(){
    int dayInput, monthInput, yearInput;
    // 0 is Monday, 6 is Sunday
    string dayOfWeekNames[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    // simple user input
    cout << "Enter a date between 01/01/2021 and 31/12/2050" << endl;
    cout << "Day: "; cin >> dayInput;
    cout << "Month: "; cin >> monthInput;
    cout << "Year: "; cin >> yearInput;

    // simple check of user input
    if((dayInput < 1) || (dayInput > get_month_long(monthInput, yearInput))){
        cout << "Invalid day" << endl;
        return 0;
    }
    if((monthInput < 1) || (monthInput > 12)){
        cout << "Invalid month" << endl;
        return 0;
    }
    if((yearInput < 2021) || (yearInput > 2050)){
        cout << "Invalid year" << endl;
        return 0;
    }

    int adjustDayOfWeek = get_day_of_week_to_2021(dayInput, monthInput, yearInput);
    cout << "The day of the week is: " << dayOfWeekNames[adjustDayOfWeek] << ", for the date: " << dayInput << "/" << monthInput << "/" << yearInput << endl;
    return 0;
}