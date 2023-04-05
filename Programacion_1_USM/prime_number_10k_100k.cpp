#include<iostream>
using namespace std;

bool int_is_prime(int integrer){
	for (int i = 2; i <= integrer/2; i++){
		if (integrer % i == 0){
			return false;
		};
	};

	return true;
};

bool int_finish_in_seven(int integrer){
	int integrerLastDigit = integrer % 10;

	if(integrerLastDigit == 7){
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