// Done fast, just for fun
/*
1.- Elabore un programa que presente en pantalla los primeros diez (10) números que:
a.- Que sean divisibles exactamente entre catorce (14).
b.- Que el resultado de su división entre catorce (14) al sacarle la raíz cuadrada de un numero entero (sin parte decimal).
c.- Que el resultado de la raíz sea un numero primo (Divisible de forma exacta solamente entre el mismo y entre 1) que termine en tres (3).
El rango a revisar es desde 500000 hasta que consiga los diez (10) números.
En la pantalla deberá presentarse el número, su división entre catorce (14) y la raíz cuadrada de ese resultado: 
Numero – División entre 14 – Raíz Cuadrada y numero Primo
521486 – 37249 - 193
*/
#include <iostream>
#include <math.h>
using namespace std;

bool number_is_int(float number){
    int numberINT = number;
    if((number - numberINT) == 0){
        return true;
    }
    else return false;
}

bool int_is_divisibly_by(int number, int divisor){
    if(number % divisor == 0){
        return true;
    }
    else return false;
};

bool int_end_in_N(int integer, int endNumber){
    int integerLastDigit = integer % 10;

    if(integerLastDigit == endNumber){
        return true;
    }
    else return false;
};

bool int_is_prime(int number){
    // Comprueba si un número es primo.
    // Input: un número entero
    // Output: true si es primo, false si no lo es.

    // Funcionamiento: Comprueba si el número es menor o igual a 1, si lo es devuelve false.
    // Si no lo es, comprueba si el número es divisible entre cualquier número entre 2 y la raíz cuadrada del número.
    // Si el número es divisible entre alguno de estos números, devuelve false.
    // (significa que existe un número menor que la raíz cuadrada del número que lo divide)
    // Si el número no es divisible entre ninguno de estos números, devuelve true.

    if((number <= 1)){
        return false;
    }

    for (int i = 2; i <= sqrt(number); i++){
        if (number % i == 0){
            return false;
        };
    };

    return true;
};

int main(){
    int number = 500000;
    int divisor = 14;
    int endNumber = 3;
    int counter = 0;
    int maxNumbers = 10;

    while(counter < maxNumbers){
        if(int_is_divisibly_by(number, divisor)){
            float division = number / divisor;
            float divisionSqrt = sqrt(division);

            if(number_is_int(divisionSqrt)){
                if(int_is_prime(divisionSqrt) & int_end_in_N(divisionSqrt, endNumber)){
                    cout << number << " - " << division << " - " << divisionSqrt << endl;
                    counter++;
                }
            }
        }
        number++;
    }
    return 0;
}