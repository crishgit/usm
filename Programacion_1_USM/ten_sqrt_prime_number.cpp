#include<iostream>
#include<math.h>
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
    int integrerLastDigit = integer % 10;

    if(integrerLastDigit == 7){
        return true;
    }
    else return false;
};

int main(){
    // user range 
    int firstValue; int lastValue; bool firstValueIncorrect = true; bool lastValueIncorrect = true;
    int minValue = 10000;
    int maxValue = 200000000;
    int sqrtPrimeSevenValues[9];
    int indexCounter = 0;

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

    // searching sqrt who finish in seven and are primers in the user range
    for (int i = firstValue; i <= lastValue; i++){
        float iSqrt = sqrt(i);
        int iSqrtINT = iSqrt;
        if((iSqrt-iSqrtINT) != 0){
            continue;
        }

        if(int_is_prime(iSqrt) & int_finish_in_seven(iSqrt) ){
            sqrtPrimeSevenValues[indexCounter] = i;
            indexCounter++;
        };
        if (indexCounter == 10){
            break;
        };
    };

    // impress the sqrtPrimeSevenValues
    for (int i = 0; i <= 9; i++){
        cout << sqrtPrimeSevenValues[i] << " ";
    }

    system ("pause");
    return 0;
};
