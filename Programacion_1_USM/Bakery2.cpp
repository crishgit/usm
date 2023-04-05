#include<iostream>
using namespace std;

int main(){
    int userDay; int userMonth; int userYear;
    int fiveDaysCycle = 0;
    bool userDayIncorrect = false; bool userMonthIncorrect = false; bool userYearIncorrect = false;

    cout << "Inserte una fecha y se le indicara si en ese día la panadería prestará servicio" << endl;
    // user range >
    while(userYearIncorrect){
        cout << "Ingrese el año: ";
        cin >> userYear;

        if(userYear >= 1995){
            userYearIncorrect = false;
        }
        else cout << "Año incorrecto. ";
    };
    while(userMonthIncorrect){
        cout << "Ingrese el mes: "
        cin >> userMonth;

        if((userMonth >= 1) || (userMonth <= 12)){
            userMonthIncorrect = false;
        }
        else cout << "Mes incorrecto. ";
    };
    while(userDayIncorrect){
        cout << "Ingrese el día";
        cin >> userDay;

        int monthLong = get_month_long(userMonth, userYear);
        if((userDay >= 1) & (userDay <= monthLong)){
            userDayIncorrect = false;
        };
        else cout << "Día incorrecto. ";
    };
    // user range <

    // 1 de enero de 1995
    // year range
    for(int year = 1995; year <= userYear; year++){
        // month range
        for(int month = 1; month <= 12; month++){
            // day range
            int monthLong = get_month_long(userMonth, userYear);
            for(int day = 1; day <= monthLong; day++){

            };
        };
        
    };

};