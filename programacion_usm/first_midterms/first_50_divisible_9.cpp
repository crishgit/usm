/* 
This program print the first 50 values in the user range (going 2 by 2) that are divisible by 9.

Steps:
1. Create an array that will hold 50 values
2. Ask the user for the start and end of the range
3. Search the first 50 values in the range (going 2 by 2) that are divisible by 9
4. Print the first 50 values 
*/
// Done by: Cristian Hernández (11/04/2023) (USM student)

#include <iostream>
#include<array>
using namespace std;

int get_user_input_basic(string messageCout){
    // Get the user input and return it
    int userInput;
    cout << messageCout;
    cin >> userInput;
    return userInput;
}

bool validate_user_input_basic(int lower, int upper, int userInputFirst, int userInputLast){
    // Validate the user input and return a boolean
    bool validFirst = userInputFirst >= lower && userInputFirst < upper;
    bool validLast = userInputLast >= userInputFirst && userInputLast <= upper;

    if(validFirst && validLast){
        return true;
    }
    else{
        return false;
    }
}

void print_array(int array[], int length){
    // Print out each element in the array until length
    for(int i = 0; i < length; i++){
        // Print out the element
        cout << array[i] << endl;
    }
}

void end_status_program(int valueCounter){
    // Based on the numbers finded, print a status message at the end of the program
    if(valueCounter == 0){
        cout << "There are no values divisible by 9 in the range" << endl;
    }
    else if(valueCounter < 50){
        cout << "There are only " << valueCounter << " values divisible by 9 in the range" << endl;
    }
    else if(valueCounter == 50){
        cout << "There are 50 values divisible by 9 in the range" << endl;
    };
}

void print_values(int numberArray[], int valueCounter){
    cout << endl << "The first 50 values divisible by 9 in the range are: " << endl;
    print_array(numberArray, valueCounter - 1);
    end_status_program(valueCounter - 1);
}

int main(){
    int fiftyValuesDivisibleBy9[50];
    int startUserInput, endUserInput;

    // user range >
    // string messageStartInput = "Enter the start of the range: ";
    // string messageEndInput = "Enter the end of the range: ";
    startUserInput = get_user_input_basic("Enter the start of the range: ");
    endUserInput = get_user_input_basic("Enter the end of the range: ");
    if(!validate_user_input_basic(1, 1000, startUserInput, endUserInput)){
        cout << "Invalid range. Stop running." << endl;
        return 0;
    }
    // user range <

    // search the first 50 values in the range that are divisible by 9
    int valueCounter = 1;

    /*
        (efficent algorithm)
        Algorithm based on the fact that an even starting number 
        will have number divisible by 9 when 9 is multiplied by an even number
        an odd starting number will have number divisible by 9 when 9 is multiplied by an odd number

        So search the number firstMultiplier that is the before number to the start of the range 
        when 9 is multiplied by that number. We add +1 to that number to achieve the first multiplier
        that get a multiple of 9 greater than the start of the range.

        After, we adjust that multiplier based on the parity of the start of the range 
        (even start have even multiplier and odd start have odd multiplier)

        Then we search the last multiplier that is the before number to the end of the range 
        when 9 is multiplied by that number.

        Finally, we iterate from the first multiplier to the last multiplier and we add 2 to the multiplier
        (to maintain the parity of the multiplier)
    */  
    int firstMultiplier = (startUserInput / 9) + 1;
    if ((firstMultiplier % 2) != (startUserInput % 2)){
        firstMultiplier++;
    }
    int lastMultiplier = (endUserInput / 9);

    for(int i = firstMultiplier; i <= lastMultiplier; i+= 2){
        if(valueCounter <= 50){
            fiftyValuesDivisibleBy9[valueCounter - 1] = i * 9;
            valueCounter++;
        }
        else{
            break;
        }
    }
    
    // print the first 50 values
    print_values(fiftyValuesDivisibleBy9, valueCounter);
    return 0;
}

