/*
Elabore un programa que permita determinar combinaciones de fecha y día de la semana entre el 01 de enero de 2022 y 31 de diciembre de 2099.

El programa deberá recibir como datos de entrada:

1.- El día de la semana de forma numérica: (1=domingo 2=lunes 3=martes 4=miércoles 5=jueves 6=viernes 7=sábado)

2.- La fecha a buscar 

Por ejemplo

Ingresamos día (2) lunes 

fecha = 14

El programa deberá indicarte cuantos lunes 14 hay entre el 1ro de enero de 2022 y el 31 de diciembre de 2099. (El programa debe considerar los años bisiestos)

Condiciones

El programa deberá validar que no se ingrese un día menor que 1 ni mayor a 31. también deberá validar que se ingrese un día de la semana en el rango de 1 a 7 (domingo a sábado).
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
    // Input: a number and a cap for that number
    // Output: the number increased by 1 until it reaches the cap, then it starts again from the start
    if(number < cap){
        return number + 1;
    }
    else return start;
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
    // Variables, first day of 2022 is 6 = saturday
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
    for(int yearLoop = 2022; yearLoop <= 2060; yearLoop++){
        // Month loop
        for(int monthLoop = 1; monthLoop <= 1; monthLoop++){
            int month_long = get_month_long(monthLoop, yearLoop);
            // Day loop
            for(int dayLoop = 1; dayLoop <= month_long; dayLoop++){
                // Check if the date is coincident
                if((dayLoop == day_user) && (day_of_week == day_of_week_user)){
                    // Print coincident dates
                    print_two_digit_number(dayLoop); cout << "/";
                    print_two_digit_number(monthLoop); cout << "/";
                    cout << yearLoop << " ";


                    dateFrecuency++; yearDisplayedRow++;

                    if(yearDisplayedRow == 5){
                        cout << endl;
                        yearDisplayedRow = 0;
                    }
                }
                // cout << "Day of week: " << day_of_week << " Day: " << dayLoop << " Month: " << monthLoop << " Year: " << yearLoop << endl;
                day_of_week = increase_number_until_cap(day_of_week, 7);
            }
        }
    }

    cout << endl << "La combinación de fecha y día de la semana se presenta " << dateFrecuency << " veces." << endl;
}

// 31/7/24