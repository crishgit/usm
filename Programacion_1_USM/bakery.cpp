/*
This program checks if a date is a day when the bakery will deliver the bread.

Steps:
1. The user enters a date.
2. The program checks if the date is valid.
3. The program checks if the date is a day when the bakery will deliver the bread.
4. The program displays the result.

The program checks if the date is valid:
- The year is greater than 1995.
- The month is between 1 and 12.
- The day is between 1 and the month long.

The program checks if the date is a day when the bakery will deliver the bread:
- If the day passed from 1/1/95 is equal to: (multiple of 5) + 1; the bakery will deliver the bread.

The program displays the result:
- If the bakery will deliver the bread, the program displays: "The bakery will deliver the bread on the date".
- If the bakery will not deliver the bread, the program displays: "The bakery will not deliver the bread on the date".
*/

// Done by Cristian Hernández (10/04/2023) (USM Student)
// check the inputs with other print program (for a selected year)

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

int increase_number_until_cap(int number, int capNumber, int startNumber = 1){ 
    // function that increases a number until it reaches a cap, then it resets to the start number
    number++;
    if(number > capNumber){ 
        number = startNumber;
    }
    return number;
};

int main(){
    int userDay; int userMonth; int userYear;
    int fiveDaysCycle = 1; // 1 to 5
    bool userDayIncorrect = true; bool userMonthIncorrect = true; bool userYearIncorrect = true;

    cout << "Inserte una fecha y se le indicara si en ese día la panadería prestará servicio" << endl;
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

    // Input month
    while(userMonthIncorrect){
        cout << "Ingrese el mes: ";
        cin >> userMonth;

        if((userMonth >= 1) || (userMonth <= 12)){
            userMonthIncorrect = false;
        }
        else cout << "Mes incorrecto. ";
    };

    // Input day
    while(userDayIncorrect){
        cout << "Ingrese el día: ";
        cin >> userDay;

        int monthLong = get_month_long(userMonth, userYear);
        if((userDay >= 1) & (userDay <= monthLong)){
            userDayIncorrect = false;
        }
        else cout << "Día incorrecto. ";
    };
    // user range <

    // 1 de enero de 1995
    // year range
    bool dayEqual = false; bool monthEqual = false; bool yearEqual = false;
    for(int year = 1995; year <= userYear; year++){
        if(year == userYear) {yearEqual = true;};

        // month range
        for(int month = 1; month <= 12; month++){
            if(month == userMonth) {monthEqual = true;};
            int monthLong = get_month_long(userMonth, userYear);

            // day range
            for(int day = 1; day <= monthLong; day++){
                if(day == userDay) {dayEqual = true;};

                // stop condition: 
                if(dayEqual & monthEqual & yearEqual){
                    if(fiveDaysCycle == 1){
                        cout << "Se prestará servicio el " << userDay << "/" << userMonth << "/" << userYear << endl;
                    }
                    else {
                        cout << "No se prestará servicio el " << userDay << "/" << userMonth << "/" << userYear << endl;
                    }
                    break;
                }

                fiveDaysCycle = increase_number_until_cap(fiveDaysCycle, 5);
            };
            if(dayEqual & monthEqual & yearEqual) break;
        }; 
        if(dayEqual & monthEqual & yearEqual) break;
    };
};