/*
This program calculates the factorial of a number and divides it by the last number of the ID

Steps:
1- Get user input
2- Validate the user input
3- Calculate the factorial of the number
4- Calculate the factorial divided by the last number of the ID
5- Print both results 
*/
// Author: Cristian Hernández (12/04/2023) (USM Student)

#include <iostream>
using namespace std;

int get_user_input_int_basic(string messageCout){
    // Get the user input and return it
    int userInput;
    cout << messageCout;
    cin >> userInput;
    return userInput;
};

int main(){
    int numberToFactorial; // User input
    int idNumber; // User input
    int lastNumberId; 
    // Get the user input
    numberToFactorial = get_user_input_int_basic("Ingrese el número para calcular su factorial: ");
    idNumber = get_user_input_int_basic("Ingrese su número de cédula de identidad: ");
    lastNumberId = idNumber % 10;
    
    // Validate inputs >
    if (numberToFactorial < 0){
        cout << "No existe el factorial de un número negativo." << endl;
        return 0;
    };
    if (lastNumberId == 0){
        cout << "No se puede dividir entre 0." << endl;
        return 0;
    };
    // Validate inputs <

    // Calculate the factorial
    // If the number is 0 or 1, the factorial is 1
    // In the rest, the factorial es 1 * 2 * 3 * ... * number;
    // i is the number to multiply: 1 -> 2 -> 3 -> ... -> number
    double long numberFactorial = 1;
    for(int i = 2; i <= numberToFactorial; i++){
        numberFactorial *= i;
    };

    // Calculate the factorial divided by the last number of the ID
    double long factorialDividedByID = numberFactorial / lastNumberId;

    // Print the results
    cout << "El factorial de " << numberToFactorial << " es: " << numberFactorial << endl;
    cout << "El factorial de " << numberToFactorial << " dividido entre el último número de su cédula de identidad es: " << factorialDividedByID << endl;
    
    return 0;
};