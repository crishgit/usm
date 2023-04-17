/* 
This program searches for the first 10 integers that are the square root of a prime number and that end in 7.

The above code does the following:
1. Ask for the range of numbers to be used, the range must be between 10k and 200kk.
2. Search for the first 10 integers (in user range) that are the square root of a prime number and that end in 7.
3. Print the 10 integers. 
*/
// Made by Cristian Hernández (05/04/2023) (USM Student)

#include<iostream>
#include<math.h>
using namespace std;

bool number_is_int(float number){
    /*
    * This function checks if a number is an integer.
    * It takes a float as parameter, converts it to an int and compares it to the original number.
    * If the difference between the number and the int is equal to 0, the number is an integer.
    * It returns true if the number is an integer, false if not.
    */
    int numberINT = number;
    if((number - numberINT) == 0){
        return true;
    }
    else return false;
}

bool int_is_prime(int number){
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

bool int_finish_in_seven(int integer){
    int integrerLastDigit = integer % 10;

    if(integrerLastDigit == 7){
        return true;
    }
    else return false;
};

int main(){
    int firstValue; int lastValue; bool firstValueIncorrect = true; bool lastValueIncorrect = true;
    int minValue = 10000;
    int maxValue = 200000000;
    int sqrtPrimeSevenValues[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int indexCounter = 0;

    // user range 
    // input first value
    while(firstValueIncorrect){
        cout << "Ingrese el valor inicial (mínimo 10k): ";
        cin >> firstValue;
        if (firstValue >= minValue & firstValue <= maxValue){
            firstValueIncorrect = false;
        }
        else {
            cout << "Número invalido" << endl;
        };
    };

    // input last value
    while(lastValueIncorrect){
        cout << "Ingrese el valor final (máximo 200kk): ";
        cin >> lastValue;
        if (lastValue > firstValue & lastValue <= maxValue){
            lastValueIncorrect = false;
        }
        else {
            cout << "Número invalido" << endl;
        };
    };
    // user range ^

    // searching sqrt who finish in seven and are primes in the user range
    for (int i = firstValue; i <= lastValue; i++){
        float iSqrt = sqrt(i);

        // checking if sqrt is int and is prime and finish in seven, if so, add to array and increase index counter
        if (number_is_int(iSqrt) & int_is_prime(iSqrt) & int_finish_in_seven(iSqrt) ){
            sqrtPrimeSevenValues[indexCounter] = i;
            indexCounter++;
        };

        // checking if we have 10 values already, if so, break the loop
        if (indexCounter == 10){
            break;
        };
    };

    // printing results
    for (int value : sqrtPrimeSevenValues){
        cout << value << " ";
    };
    cout << endl;


    return 0;
};
