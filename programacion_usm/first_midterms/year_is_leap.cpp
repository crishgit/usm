/* 
This program determines if a year is leap or not.

Steps:
1-  Get the year from the user.
2- Check if the year is valid.
3- If the year is not valid, print an error message.
4- If the year is valid, determine if the year is leap and print the result. 
*/
// Author: Cristian Hernández (12/04/2023) (USM Student)

#include <iostream>
using namespace std;

int get_user_input_basic(string messageCout){
    // Get the user input and return it
    int userInput;
    cout << messageCout;
    cin >> userInput;
    return userInput;
}

bool year_is_leap(int year){ 
	// leap year are divisible by 4
	// if are divisible by 100, they also need be divisible by 400 to be leap 
	if(year % 100 == 0){
		if(year % 400 == 0){
			return true;
		}
		else return false;
	};

	if( (year % 4) == 0){
		return true;
	}
	else return false;
};

int main(){
    // Get the year from the user.
    int startUserYear;
    startUserYear = get_user_input_basic("Enter the year: ");
    
    // Check if the year is valid.
    if(startUserYear < 1400){
        cout << "The year is not valid. The minimum year is 1400." << endl;
        return 0;
    }
    
    // Determine if the year is leap and print the result.
    if(year_is_leap(startUserYear)){
        cout << "The year " << startUserYear << " is leap." << endl;
    }
    else{
        cout << "The year " << startUserYear << " is not leap." << endl;
    }
    return 0;
}