#include<iostream>
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

int increase_number_until_cap(int number, int capNumber, int startNumber = 1){
    number++;
    if(number >= capNumber + 1){ 
        number = startNumber;
    }
    return number;
};

int main(){
    int userDay; int userMonth; int userYear;
    int fiveDaysCycle = 0;
    bool userDayIncorrect = true; bool userMonthIncorrect = true; bool userYearIncorrect = true;

    cout << "Inserte una fecha y se le indicara si en ese día la panadería prestará servicio" << endl;
    // user range >
    while(userYearIncorrect){
        cout << "Ingrese el año (mayor a 1995): ";
        cin >> userYear;

        if(userYear >= 1995){
            userYearIncorrect = false;
        }
        else cout << "Año incorrecto. ";
    };
    while(userMonthIncorrect){
        cout << "Ingrese el mes: ";
        cin >> userMonth;

        if((userMonth >= 1) || (userMonth <= 12)){
            userMonthIncorrect = false;
        }
        else cout << "Mes incorrecto. ";
    };
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
    int everyFiveDays = 1; // 1 to 6
    for(int year = 1995; year <= userYear; year++){
        if(year == userYear) yearEqual = true;

        // month range
        for(int month = 1; month <= 12; month++){
            if(month == userMonth) monthEqual = true;
            int monthLong = get_month_long(userMonth, userYear);

            // day range
            for(int day = 1; day <= monthLong; day++){
                if(day == userDay) 
                    dayEqual = true;

                // stop condition: 
                if(dayEqual & monthEqual & yearEqual){
                    if(everyFiveDays == 1){
                        cout << "Se prestará servicio el " << userDay << "/" << userMonth << "/" << userYear << endl;
                    }
                    else {
                        cout << "No se prestará servicio el " << userDay << "/" << userMonth << "/" << userYear << endl;
                    }
                    break;
                }

                everyFiveDays = increase_number_until_cap(everyFiveDays, 5);
            };
            if(dayEqual & monthEqual & yearEqual) break;
        }; 
        if(dayEqual & monthEqual & yearEqual) break;
    };
};