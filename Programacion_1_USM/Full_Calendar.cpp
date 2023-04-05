#include<iostream>
#include<string>
using namespace std;

int get_user_input(string consoleMsg, /* checksConditions*/, string errorMsg){
	// get_user_input("Coloca el monto", yearLast >= yearFirst, "monto incorrecto");
	/*
	Los while usan: 
	1) mensaje de pedido (argumento)
	2) comprobación de que el valor es correcto (argumento)
	3) mensaje de error (argumento y un default)
	4) return del valor correcto
	4.1) ciclo continuado hasta el valor correcto
	*/
	return 0;
};

int first_week_day_year(int year){
	// base: 1922 Sunday-07
	// Calculate the year difference to the base, get the leap years and no leap years based in formules
	// Calculate the days difference multiplying leap years by 366, not leap years by 365
	// get the first day adjusting base day by -1 (cus the range varies between 0-6, not 1-7), adds de days difference
	// and after get the module of base 7 (week durations)
	// add +1 to that cus extend the range from 0-6 to 1-7
	int baseYear = 1922; int baseDay = 7;
	bool baseYearSmaller = year >= baseYear;
	int yearDiff;
	if(baseYearSmaller){yearDiff = year - baseYear;}
	else yearDiff = baseYear - year;
	int yearLeap = (yearDiff + 1) / 4;
	int yearNotLeap = yearDiff - yearLeap;

	int daysDiff = (365*yearNotLeap) + (366*yearLeap);
	int firstDay;
	if(baseYearSmaller){ firstDay = (( (baseDay-1) + daysDiff) % 7) + 1;}
	else firstDay = (( (baseDay-1) - daysDiff) % 7) + 1;

	return firstDay;
};

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

void cout_n_spaces(int spacesAmount){
	// cout n spaces in blank
	for(int i = 1; i <= spacesAmount; i++){
		cout << " ";
	};
};

void cout_two_digit_int(int number){
	// cout number between 0 and 99 in the form of two digit 
	if((number < 0) || (number > 99) ) {return;};

	if(number <= 9){
		cout << "0" << number;
	}
	else cout << number;
};

void print_days(int day, int weekDay){
	// the first day of the week, cout the adecuate spaces in blank, after cout the day number
	// else, check if need a new line or only 1 space in blank for the next day number
	if(day == 1){
		int blankSpaces = (weekDay - 1) * 3; 
		cout_n_spaces(blankSpaces);
		cout_two_digit_int(day);
	}
	else{
		if(weekDay == 1){
			cout << endl;
			cout_two_digit_int(day);
		}
		else {
			cout_n_spaces(1);
			cout_two_digit_int(day);
		};
	};
};

int increase_weekDay(int weekDay){
	// weekday varies between 1/Monday-7/Sunday, if pass Sunday, go back to Monday. 
	weekDay++;
	if(weekDay > 7){
		weekDay = 1;
	};
	return weekDay;
};

void pause_clear_program(){
	system("pause");
	system("cls");
}

int main(){
	int yearFirst, yearLast, dayNumber, monthNumber, yearNumber;
	int weekDay; // start in Monday-1 and finish in Sunday-8
	string monthName[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
	bool yearFirstIncorrect = true;
	bool yearLastIncorrect = true;

	cout << "Este programa crea el calendario para un rango de años dado por el usuario. El primer año debe ser mayor a 0." << endl << endl ;
	//user range >>
	while(yearFirstIncorrect){
		cout << "Introduzca el primer año (no puede ser menor al 1922): ";
		cin >> yearFirst;
		if (yearFirst >= 1922){
			yearFirstIncorrect = false;
		}
		else cout << "Año incorrecto. ";
	};

	while(yearLastIncorrect){
		cout << "Introduzca el último año. Debe ser mayor o igual que el anterior: ";
		cin >> yearLast;
		if (yearLast >= yearFirst){
			yearLastIncorrect = false;
		}
		else cout << "Año incorrecto. ";
	};
	//user range <<
	
	// year range
	weekDay = first_week_day_year(yearFirst);
	for(yearNumber = yearFirst; yearNumber <= yearLast; yearNumber++){
		if(year_is_leap(yearNumber)){cout << "Año " << yearNumber << " (Bisiesto)" << endl;}
		else cout << "Año " << yearNumber << endl;

		// month range
		for(monthNumber = 1; monthNumber <= 12; monthNumber++){
			int monthLong = get_month_long(monthNumber, yearNumber);

			cout << monthName[monthNumber - 1] << " del " << yearNumber << endl;
			cout << "Lu Ma Mi Ju Vi Sa Do" << endl;

			// day range
			for(dayNumber = 1; dayNumber <= monthLong; dayNumber++){
				print_days(dayNumber, weekDay);
				weekDay = increase_weekDay(weekDay);
			};
			cout << endl << endl;
		};
		pause_clear_program();
	};

	return 0;
};
