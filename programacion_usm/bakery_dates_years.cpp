/*
This program display the dates of a year when the bakery will deliver bread.

Steps:
1. The user enters a date.
2. The program checks if the date is valid.
3. The program check, for every day of the year, if the bakery will deliver the bread
4. The program displays the result.

The program checks if the date is valid:
- The year is greater than 1995.

The program checks if the date is a day when the bakery will deliver the bread:
Every 5 days from 01/01/1995. So the program pass for all days and have
a counter for know if 5 days has passed or not.

The program displays the result:
- Date in the format: dd/mm/yyyy. Example: 01/01/1995 - 02/03/1995.
- And set a new line after 5 prints

Author: Cristian Hernández, 10/04/23 (USM) 
Version: 3 (21/04/23)
*/

#include<iostream>
using namespace std;

int floor(int number){
    int numberNoDecimal = number;
    return numberNoDecimal; 
}


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

int increase_number_until_cap(int number, int capNumber, int startNumber = 1){ 
    // function that increases a number until it reaches a cap, then it resets to the start number
    number++;
    if(number > capNumber){ 
        number = startNumber;
    }
    return number;
};

void print_two_digit_number(int number){
    // Input: a integer between 0 and 99
    // Output: print the integer with two digits
    if(number < 10){
        cout << "0" << number;
    }
    else cout << number;
};

void display_date(int day, int month, int year, int datesPrintAmounts, int printCaps = 5){
    // Input: a date
    // Output: print the date in the format: dd/mm/yyyy. Example: 01/01/1995.
    // And set a new line after 5 prints
    print_two_digit_number(day);
    cout << "/";
    print_two_digit_number(month);
    cout << "/";
    cout << year;

    if( (datesPrintAmounts + 1) % printCaps == 0){
        cout << "\n";
    }
    else cout << " - ";;
};

int days_diff_to_1995(int year){
    // calculate the days that have passed between 1995 and a year.
    // For that, calculate the amount of year leaps and normal years
    // between 1995 and the year.
    // For the leaps year, it's every 4 years between the first leap year passed
    // the first leap year passed in 1997, so 2 years between 1995. 

    int yearsDiff = year - 1995;
    int yearLeap = floor( (yearsDiff + 2) / 4 ); 
    int yearNoLeap = yearsDiff - yearLeap;
    
    int daysDiff = yearNoLeap*365 + yearLeap*366;
    return daysDiff;
}

int carry_fiveDaysCycle_to(int year, int fiveDaysCycle){
    int daysDiff = days_diff_to_1995(year);
    // daysPassed mod 5, because the cycles are in 5. 
    int dayOfTheCycle = ((daysDiff + fiveDaysCycle) % 5);

    return dayOfTheCycle;
}

int main(){
    int userYear;
    int fiveDaysCycle = 1; // 1 to 5; 1 is a day when the bakery will deliver the bread
    bool userYearIncorrect = true;

    cout << "Inserte un año y se le mostraran todas las fechas laborables para ese año" << endl;
    // user range >
    // issues: if the user input is a string, the program will crash
    // how to fix it?
    // fix function:
    // https://stackoverflow.com/questions/18728754/how-to-check-if-input-is-a-number-or-string-in-c
    
    // Input year
    while(userYearIncorrect){
        cout << "Ingrese el año (mayor a 1995): ";
        cin >> userYear;

        if(userYear >= 1995){
            userYearIncorrect = false;
        }
        else cout << "Año incorrecto. ";
    };
    // user range <

    // 1 de enero de 1995
    // year range
    bool dayFinded = false;
    int datesPrintAmounts = 0;
    // Add a function to get the fiveDaysCycle to userYear
    fiveDaysCycle = carry_fiveDaysCycle_to(userYear, fiveDaysCycle);

    for(int year = userYear; year <= userYear; year++){
        // month range
        for(int month = 1; month <= 12; month++){
            // day range
            for(int day = 1; day <= get_month_long(month, year); day++){
                // check if the date is a day when the bakery will deliver the bread
                if(fiveDaysCycle == 1){
                    display_date(day, month, year, datesPrintAmounts);
                    datesPrintAmounts++;
                }
                fiveDaysCycle = increase_number_until_cap(fiveDaysCycle, 5);
            };
        };
    };
};
