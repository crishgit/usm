/*
Este programa muesta los números de placa para una fecha dada por el usuario.
Se itinera hasta la fecha dada por el usuario mientras se ajusta la placa, 
llegada la fecha, muestra las placas de ese día.

Cristian Hernández
*/

#include<iostream>
using namespace std;

bool year_is_leap(int year){
    if (year % 100){
        if (year % 400){
            return true;
        };
        return false;
    };

    if(year % 4){
        return true;
    };
    return false;

    /* Un año es bisiesto si es divisible entre 4. En el caso de que sea 
    divisible entre 100, también tendrá que ser divisible entre 400 */
};

int get_month_long(int month, int year){
    if ( (month == 4) OR (month == 6) OR (month == 9) OR (month == 11) ){
        return 30;
    }
    else if (month == 2){
        if (year_is_leap(year)){
            return 29;
        }
        else return 28;
    }
    else return 31;

    /* Los meses 4, 6, 9, 11 tienen 30 días. Febrero tiene 29 si es bisiesto,
    28 si es normal. El resto de meses tienen 31 días */
}

int main(){
    cout << "Ingrese una fecha y se le indicará las placas" << endl;
    int userYear, userMonth, userDay;
    int counterPlaca = 4;
    /* contador del 1 al 5. El 1 es para las placas 1 y 2, el 2 es para las placas
    3 y 4, así hasta el 5 que es para las placas 9 y 10. */
    
    // inputs del usuario
    cout << "Ingrese el año (min: 2023, max: 2059): ";
    cin >> userYear;
    cout << "Ingrese el mes: ";
    cin >> userMonth;
    cout << "Ingrese el día: ";
    cin >> userDay;

    // obtener la placa para la fecha del usuario
    bool sameDay = false;
    for(int year = 2023; year <= userYear; year++){
        for(int month = 1; month <= 12; month++){
            int monthLong = get_month_long(month, year);

            for(int day = 1; day <= monthLong; day++){
                if( (year == userYear) AND (month == userMonth) AND (day == userDay) ){
                    int placa = 2*counterPlaca - 1;
                    cout << "Las placas son: " << placa << " y " << (placa + 1) << endl;
                };

                if(counterPlaca < 5){
                    counterPlaca++;
                }
                else counterPlaca = 1;
            };
        };
    };
    /* Se itinera por todos los días hasta alcanzar la fecha del usuario mientras 
    se suma 1 al contador hasta llegar al 5, reiniciando el contador a 1. Con 
    el valor del contador se colocan los números de placa */

    return 0;
};
