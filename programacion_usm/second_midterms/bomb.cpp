/*
This program emulates the disable of the bomb of Cars 2, the movie. 

This bomb explodes in 5 minutes. To disable it, the user need enter two correct
characters; these characters only shown with * in the screen. If the user enter
a wrong character, the explosion time is reduced in 1 minutes.

Beeps every seconds and explosion sound in beeps

Author: Cristian Hernández (06/05/2023) (USM)
*/

#include <iostream>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

using namespace std;

char getRandomLetter(){
    /*
    Input: none
    Output: a random letter [A-Z] of the english alphabet

    This function have a string with the english alphabet and generate a 
    random number between the lenght of the alphabet (26) and search the 
    letter in the position of the array, then return it.
    */

    string alphabet_letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char letter = alphabet_letter[rand() % alphabet_letter.length()];

    return letter;
}

string getRandomBombDesactivationCode(int codeLength = 2){
    /*
    Input: none
    Output: a random code of codeLength letters [A-Z] of the english alphabet

    This function return a random code of codeLength letters between A and Z 
    using the function getRandomLetter() to get each letters. The code is 
    generated concateneting each generated letter.
    */

    string code;
    for(int i = 1; i <= codeLength; i++){
        code += getRandomLetter();
    }

    return code;
}

void explosionSound(){
    /*
    Input: none
    Output: none

    This function play the sound of the bomb explosion
    For that, play a serie of beeps with composes the sound of the explosion
    */

    int beeps_frequency[] = {1000, 800, 600, 400, 200};
    int beeps_duration[] =  {100 , 200, 300, 400, 500};

    for(int i = 0; i < 5; i++){
        Beep(beeps_frequency[i], beeps_duration[i]);
    }
}

int main () {
    // Bomb variables
    int bomb_time_explosion_seconds = 300;
    string bomb_desactivation_code = getRandomBombDesactivationCode();
    string user_bomb_desactivation_code;
    bool bomb_working = true;


    while( (bomb_time_explosion_seconds > 0) ){
        // clear the screen
        system("cls");

        // print the ui for bomb desactivation
        cout << "Bomb desactivation code: " << bomb_desactivation_code << endl;
        cout << "Time to explosion: " << bomb_time_explosion_seconds 
            << " seconds" << endl;

        cout << "Enter the code: ";

        // cout * for each letter of the code guessed for the user
        for(int i = 0; i < user_bomb_desactivation_code.size(); i++){
            cout << "*";
        }

        // if the user guessed the code, the bomb is desactivated
        if(user_bomb_desactivation_code == bomb_desactivation_code){
            bomb_working = false;
            break;
        }

        // Clock and sound of the bomb explosion every second
        Beep(500, 980);
        bomb_time_explosion_seconds--;

        // if the user press a key, check if the input is part of the code
        if(kbhit() != 0){
            char user_letter_try = tolower( getch() );
            int index_actual_char_code = user_bomb_desactivation_code.size();

            // if the user letter is part of the code, add it to the code 
            // guessed by the user, else, reduce 1 minute to time explosion
            if(user_letter_try == bomb_desactivation_code[index_actual_char_code]){
                user_bomb_desactivation_code += user_letter_try;
            }
            else{
                bomb_time_explosion_seconds -= 60;
            }
        }
    }

    // if the bomb is not desactivated, the bomb explodes
    if(bomb_working){
        cout << endl << "Bomb exploded!!!!!!!!!!" << endl;
        explosionSound();
    }
    else{
        cout << "Bomb desactivated!" << endl;
        cout << "Congratulations!" << endl;
    }

    return 0;
}
