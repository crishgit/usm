/*
Written for Linux
*/

#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <unistd.h>
#include <cstdio>
using namespace std;

void clearConsole(){
	cout << "\033[2J\033[1;1H";
}

vector<string> wordsOfString(string string_to_parse){
	vector<string> words_of_string = {};
	string actual_word = "";
	bool parsing_word = false;
	/*
	It's considered word the substring started 
	by [space,non space] and ended in [non space, space]
	*/

	for(i = 0; i < string_to_parse.size() ; i++) {
		char actual_char = string_to_parse[i];
		bool actual_char_is_letter = actual_char != " ";
		bool actual_char_is_space = actual_char == " ";

		bool exist_next_char = false;
		string next_char = "";
		bool next_char_is_letter = false;
		bool next_char_is_space = false;

		if( i+1 < string_to_parse.size() ){
			exist_next_char = true
			next_char = string_to_parse[i+1];
			next_char_is_letter = next_char != " ";
			next_char_is_space = next_char == " ";
		}

		if(exist_next_char){
			if( actual_char_is_space and next_char_is_letter){
				parsing_word = true;
			}
		}

		if(parsing_word){
			actual_word += actual_char;
		}

		if (exist_next_char){
			if( actual_char_is_letter and next_char_is_space){
				parsing_word = false;
				actual_word = "";
			}
		}
	}

	return words_of_string;
}

string isEvenOrOdd(double number){
	int number_int = floor(number);
	if(number != number_int){
		return "neither";
	}

	if(number_int % 2 == 0){
		return "even";
	}
	else{
		return "odd";
	}
}

double getRandomNumberOneDecimal(double initial_range, double final_range){
	int initial_range_fixed = initial_range * 10;
	int final_range_fixed = (final_range * 10 - initial_range_fixed + 1);
	/*
	the +1 it's to include exactly the last number cus the range of %
	it's [0, last number - 1]
	*/

	double random_number = static_cast<double>(initial_range_fixed + rand()%final_range_fixed) / 10;

	return random_number;
}

int main(){
	srand(time(NULL));

	string input_text = "";
	vector<string> input_words = {};

	while(input_words.size() < 4){
		cout << "Ingrese un texto de 4 palabras: " << "\n";
		getline(cin, input_text);
		input_words = wordsOfString(input_words);

		cin.ignore();
		clearConsole();
	}

	int number_words_input = input_words.size();

	if(isEvenOrOdd(number_words_input) == "even"){
		int ammount_of_numbers = 15;

		cout << "15 números aleatorios: \n";

		for (int i = 1; i <= ammount_of_numbers; ++i){
			cout << getRandomNumberOneDecimal(-60.5, 5.5) << " \a";
		}
	}
	else{
		cout << "Ingrese una opción";
		char user_option = getchar();

		while(user_option != 'S' or user_option != 's' or user_option != '#'){
			clearConsole();
			cout << "Ingrese una opción \a";
			user_option = getchar();
		}

		if (user_option == 'S' or user_option == 's'){
			for (int i = 0; i < input_words.size(); i++) {
				string actual_word = input_words[i];
				cout << "Palabra" << i << "=" << actual_word; 
				sleep(1);
			}
		}
		else if(user_option == '#'){
			cout << input_words[2];
		}
	}


	return 0;
}
