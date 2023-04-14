/*
Este programa presenta en pantalla los primeros veinte (20) números que al 
sacarle la raíz cuadrada el resultado sea un número: entero, primo y termina en 7

*/
// Autor: Cristian Hernández, 28481734 (12/04/2024) (Programación 1)

#include<iostream>
#include<math.h>
using namespace std;

bool number_is_int(float number){
    // Input: a float number
    // Output: true if the number is an integer, false if not

    int numberINT = number;
    if((number - numberINT) == 0){
        return true;
    }
    else return false;
}

bool int_is_prime(int number){
    // Input: a integer number
    // Output: true if the number is prime, false if not

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

bool int_end_in_N(int integer, int endNumber){
    // Input: a integer number and a integer number to check if the integer ends in it
    // Output: true if the integer ends in the number, false if not

    int integerLastDigit = integer % 10;

    if(integerLastDigit == endNumber){
        return true;
    }
    else return false;
};

int closest_greater_sqrt(int number){
    // Input: a integer number
    // Output: the closest greater integer square root of the number

    float sqrtNumber = sqrt(number);
    if(number_is_int(sqrtNumber)){
        return sqrtNumber;
    }
    else return ceil(sqrtNumber);
}

int closest_greater_endN(int number, int endNumber){
    // Input: a integer number and a integer number to check if the integer ends in it
    // Output: the closest greater integer that ends in the number

    int closestGreater = number;
    while(!int_end_in_N(closestGreater, endNumber)){
        closestGreater++;
    };
    return closestGreater;
}

int main(){
    int startNumber = 100000;
    
    // Table header
    cout << "Número - Raíz Cuadrada (Primo que termina en siete)" << endl;

    /* 
    Find the 20 numbers that meet the conditions
    This algorithm is based on the fact that the we search numbers who
    square root are integer, are prime and ends in 7

    Numbers whose square root are integer are the numbers who follow N = (integer)^2
    so the desired numbers are those who ends in 7 and are prime
    starting for the integer who square power are greater than the startNumber

    The loop start searching for that number, next it
    search for the closest greater integer to that number who ends in 7
    And the loop increases the number 10 by 10 to preserve the "ends in 7" condition
    */
    int numbersFinded = 0;
    int closestGreaterSqrtEnd7 = closest_greater_endN(closest_greater_sqrt(startNumber), 7);

    for(int i = closestGreaterSqrtEnd7; numbersFinded < 20; i+=10){
        if(int_is_prime(i)){
            // Print the number who squareroot are integer, is prime and ends in 7
            // with its square root
            cout << pow(i, 2) << " - " << i << endl;
            numbersFinded++;
        }
    }

    return 0;
};