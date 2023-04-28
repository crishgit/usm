/*
This program find the 20 numbers, from 100k, that meet the following conditions:
1. The square root of the number is an integer
2. The square root is prime
3. The square root end in 7

Steps:
1. Start with a number, let's say 100000
2. Find the closest greater integer to the square root of that number
3. Find the closest greater integer to that number that ends in 7
4. Check if that number is prime, if it is then print it and its square root
5. Increase the number by 10 and go to step 4
6. Repeat step 4 and 5 until you find 20 numbers that meet the conditions
7. Print the numbers and their square root (the numbers that is itineriting the loop)

Autor: Cristian Hernández (12/04/2024) (Programación 1)
*/


#include<iostream>
#include<math.h>
using namespace std;

bool number_is_int(float number){
    /*
    Input: a float number
    Output: true if the number is an integer, false if not

    Explanation: takes the number and subtracts it by its integer part
    if the result is 0, then the number is an integer, if not, it is not
    */

    int numberINT = number;
    if((number - numberINT) == 0){
        return true;
    }
    else return false;
}

bool int_is_prime(int number){
    /*
    Input: a integer number
    Output: true if the number is prime, false if not

    Explanation: takes the number and divides it by all the numbers
    from 2 to the square root of the number, if the number is divisible
    by any of those numbers, then it is not prime, if not, it is prime
    */

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
    /* 
    Input: a integer number and a integer number to check if the integer ends in it
    Output: true if the integer ends in the number, false if not
    
    Explanation: takes the last digit of the integer and compares it with the endNumber
    */
    int integerLastDigit = integer % 10;

    if(integerLastDigit == endNumber){
        return true;
    }
    else return false;
};

int closest_greater_sqrt(int number){
    /*
    Input: a integer number
    Output: the closest greater integer square root of the number

    Explanation: takes the square root of the number and if it is an integer
    returns it, if not, that means that the square root is not perfect and
    the closest greater integer square root is the ceiling of that number
    (because the floor is smaller, and with decimals are not perfect square roots)
    */

    float sqrtNumber = sqrt(number);
    if(number_is_int(sqrtNumber)){
        return sqrtNumber;
    }
    else return ceil(sqrtNumber);
}

int closest_greater_endN(int number, int endNumber){
    /* 
    Input: a integer number and a integer number to check if the integer ends in it
    Output: the closest greater integer that ends in the number
    
    Explanation: takes the number and increases it by one until it ends in the number
    */
   
    int closestGreater = number;
    while(!int_end_in_N(closestGreater, endNumber)){
        closestGreater++;
    };
    return closestGreater;
}

int main(){
    int startNumber = 100000;
    int sqrtEndsIn = 7;
    
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
    int closestGreaterSqrtEnd7 = closest_greater_endN(closest_greater_sqrt(startNumber), sqrtEndsIn);

    for(int i = closestGreaterSqrtEnd7; numbersFinded < 20; i+=10){
        if(int_is_prime(i)){
            // Print the number who squareroot are integer, are prime and ends in "sqrtEndsIn"
            // with its square root
            cout << pow(i, 2) << " - " << i << endl;
            numbersFinded++;
        }
    }

    return 0;
};