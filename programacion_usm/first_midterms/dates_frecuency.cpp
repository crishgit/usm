/*
This program calculates the frecuency of the combination of a date and a day of the week between 2022 and 2099.

Steps:
1- Input the day and day of the week.
2- Validate the day and day of the week.
3- Loop through the years from 2022 to 2099.
4- Loop through the months of the year.
5- Loop through the days of the month.
6- Check if the date is coincident with the date and day of the week that the user entered.
7- Print the coincident dates.
8- Count the coincident dates.
9- Print the number of coincident dates.

Author: Cristian Hernández (13/04/2023) (USM)
*/

#include <iostream>
using namespace std;

bool year_is_leap(int year){ 
    // Input: a year
    // Output: true if the year is leap, false otherwise
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
    // Input: a year and a month of the year
    // Output: the number of days of the month for that year
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

int increase_number_until_cap(int number, int cap, int start = 1){
    // Input: a number and a cap and start for the number
    // Output: the number increased by one until it reaches the cap, then it starts again from the start
	number++;
	if(number > cap){
		number = start;
	};
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

int main(){
    // Variables, first day of 2022 is 7 = saturday
    int day_of_week_user, day_user, dateFrecuency = 0;
    int day_of_week = 7; // 1 = sunday, 7 = saturday


    // Input
    cout << "Ingrese el día: ";
    cin >> day_user;
    cout << "Ingrese el día de la semana (1=domingo 2=lunes 3=martes 4=miércoles 5=jueves 6=viernes 7=sábado): ";
    cin >> day_of_week_user;

    // Validation
    if(day_of_week_user < 1 || day_of_week_user > 7){
        cout << "El día de la semana debe estar entre 1 y 7." << endl;
        return 0;
    }
    if(day_user < 1 || day_user > 31){
        cout << "El día debe estar entre 1 y 31." << endl;
        return 0;
    }

    // Processing
    cout << "La combinación de fecha y día de la semana se presenta en: " << endl;
    // Year loop
    int yearDisplayedRow = 0;
    for(int yearLoop = 2022; yearLoop <= 2099; yearLoop++){
        // Month loop
        for(int monthLoop = 1; monthLoop <= 12; monthLoop++){
            int month_long = get_month_long(monthLoop, yearLoop);
            // Day loop
            for(int dayLoop = 1; dayLoop <= month_long; dayLoop++){
                // Check if the date is coincident
                if((dayLoop == day_user) & (day_of_week == day_of_week_user)){
                    // Print coincident dates
                    print_two_digit_number(dayLoop); cout << "/";
                    print_two_digit_number(monthLoop); cout << "/";
                    cout << yearLoop << " ";

                    // Count coincident dates and print a new line every 5 dates
                    dateFrecuency++; yearDisplayedRow++;

                    if(yearDisplayedRow == 5){
                        cout << endl;
                        yearDisplayedRow = 0;
                    }
                }
                day_of_week = increase_number_until_cap(day_of_week, 7);
            }
        }
    }

    cout << endl << "La combinación de fecha y día de la semana se presenta " << dateFrecuency << " veces." << endl;
}