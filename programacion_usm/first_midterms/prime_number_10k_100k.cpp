/* 
This program prints all the prime numbers that end in 7 between 10000 and 100000.

Steps:
1. For loop from 10000 to 100000
2. Checks if the number is prime using a function
3. Checks if the number ends in 7 using a function
4. If both are true, then print the number. 
*/
// Created by: Cristian Hernández (05/04/2023) (USM Student)

#include<iostream>
using namespace std;

bool int_is_prime(int integer){
	for (int i = 2; i <= integer/2; i++){
		if (integer % i == 0){
			return false;
		};
	};

	return true;
};

bool int_finish_in_seven(int integer){
	int integerLastDigit = integer % 10;

	if(integerLastDigit == 7){
		return true;
	}
	else return false;
};

int main(){
	for (int i = 10000; i <= 100000; i++){
		if( int_is_prime(i) & int_finish_in_seven(i) ){
			cout << i << " ";
		};
	};
};