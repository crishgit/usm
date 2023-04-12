/* 
This program finds the first 100 odd numbers in a range with a perfect cubic root

Steps:
The above code does the following in natural language:
1- Set the array to store the numbers
2- Get the user input
3- Check if the user input is valid
4- Find the first 100 odd numbers in the range with a perfect cubic root
5- Print the numbers 
*/
// Author: Cristian Hernández (12/04/2023) (USM Student)

#include <iostream>
#include <math.h>
using namespace std;

int get_user_input_basic(string messageCout){
    // Get the user input and return it
    int userInput;
    cout << messageCout;
    cin >> userInput;
    return userInput;
}

void end_status_program(int valueCounter){
    // Based on the numbers finded, print a status message at the end of the program
    if(valueCounter == 0){
        cout << "No se encontraron números en el rango ingresado." << endl;
    }
    else if(valueCounter < 50){
        cout << "Se encontraron " << valueCounter << " en el rango ingresado." << endl;
    }
    else if(valueCounter == 50){
        cout << "Se encontraron 50 números en el rango ingresado." << endl;
    };
}

int main(){
    int numbersCubicRoot[100]; // Array to store the numbers
    double long startUserNumber, endUserNumber; // User input
    int counter = 0; // Counter to store the numbers in the array

    // Get the user input
    startUserNumber = get_user_input_basic("Ingrese el número inicial: ");
    endUserNumber = get_user_input_basic("Ingrese el número final: ");

    // Check if the user input is valid
    if(startUserNumber < 0){
        cout << "No existen raíces reales para números negativos." << endl;
        return 0;
    };
    if (startUserNumber > endUserNumber){
        cout << "El número inicial debe ser menor al número final." << endl;
        return 0;
    };

    // Find the numbers
    // First, search the first cubic root in the range
    // and the last cubic root in the range
    // Then, search the odd numbers between the first and last cubic root
    // these numbers are cuadratic numbers
    // and a condition to ensure that only odd numbers are stored
    // that's because, only odd numbers have a odd cubic power
    // We are adding the number**3 to the array, because the number is the cubic root
    // Last, stop when the array is full
    double long startNumberSearch = ceil(pow(startUserNumber, 1.0/3.0));
    double long endNumberSearch = floor(pow(endUserNumber, 1.0/3.0));
    for(int i = startNumberSearch; i <= endNumberSearch; i++){
        if (i % 2 != 0){
            numbersCubicRoot[counter] = pow(i, 3);
            counter++;
        };
        if(counter == 100){
            break;
        };
    };

    // Print the numbers
    cout << endl << "Los primeros 100 números impares que tienen raíz cubica exacta son: " << endl;
    for(int i = 0; i < counter; i++){
        cout << numbersCubicRoot[i] << endl;
    };
    end_status_program(counter);

    return 0;
}