// Done fast, just for fun
/*
1.- Elabore un programa que presente en pantalla los primeros veinte (20) números que:
a.- Que finalicen en ocho (8). 
b.- Que sean divisibles exactamente entre siete (7). (sin parte decimal)
c.- Que el resultado de su división entre siete (7) al sacarle la raíz cuadrada de un numero entero que termine en dos (2).
El rango a revisar es desde 500000 hasta que consiga los veinte números.
En la pantalla deberá presentarse el número, su división entre siete (7) y la raíz cuadrada de ese resultado que termina en (2) dos: 
Numero – División entre 7 – Raíz Cuadrada terminada en dos
681408 – 97344 - 312
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

/*
a.- Que finalicen en ocho (8). 
b.- Que sean divisibles exactamente entre siete (7). (sin parte decimal)
c.- Que el <resultado de su división entre siete> (7) al 
<sacarle la raíz cuadrada> de un <numero entero> que <termine en dos (2)>.
*/

int main(){
    int number = 500000;
    int counter = 0;
    int divisor = 7;
    int endNumber = 8;

    while(counter < 20){
        if(int_end_in_N(number, endNumber) && int_is_divisibly_by(number, divisor)){
            float division = number / divisor;
            float divisionSquareRoot = sqrt(division);

            if(number_is_int(divisionSquareRoot) && int_end_in_N(divisionSquareRoot, 2)){
                cout << number << " - " << division << " - " << divisionSquareRoot << endl;
                counter++;
            }
        }
        number++;
    }
}