// fast done, just for fun
/*
1.- Elabore un programa que presente en pantalla los primeros veinte (20) números que:
a.- Que sean divisibles exactamente entre cuatro (4). (Sin parte decimal)
b.- Que sean divisibles exactamente entre seis (6). (Sin parte decimal)
c.- Que su raíz cuadrada de un numero entero (Sin parte decimal) y que ese número termine es cuatro (4).
El rango a revisar es desde 50000 hasta que consiga los veinte (20) números.
En la pantalla deberá presentarse el número, su división entre cuatro (4), su división entre seis (6) y la raíz cuadrada de ese resultado que termina en 4: 

Numero – División entre 4 – División entre 6 - Raíz Cuadrada terminada en 4
54756 – 13689 – 9126 - 234

*/

#include <iostream>
#include <math.h>
using namespace std;

bool number_is_int(float number){
    int numberINT = number;
    if((number - numberINT) == 0){
        return true;
    }
    else return false;
}

bool int_is_divisibly_by(int number, int divisor){
    if(number % divisor == 0){
        return true;
    }
    else return false;
};

bool int_end_in_N(int integer, int endNumber){
    int integerLastDigit = integer % 10;

    if(integerLastDigit == endNumber){
        return true;
    }
    else return false;
};

int main(){
    int number = 50000;
    int counter = 0;
    int divisor = 4;
    int divisor2 = 6;
    int endNumber = 4;
    int numberINT = 0;
    float numberSQRT = 0;

// c.- Que su raíz cuadrada de un numero entero (Sin parte decimal) y que ese número termine es cuatro (4).
    while(counter < 20){
        numberSQRT = sqrt(number);

        if(int_is_divisibly_by(number, divisor) && int_is_divisibly_by(number, divisor2) && number_is_int(numberSQRT) && int_end_in_N(numberSQRT, endNumber)){
            numberINT = number;
            numberSQRT = sqrt(number);
            cout << numberINT << " - " << numberINT / divisor << " - " << numberINT / divisor2 << " - " << numberSQRT << endl;
            counter++;
        }
        number++;
    }
    return 0;
}