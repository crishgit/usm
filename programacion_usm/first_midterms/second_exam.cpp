// Fast done, just for fun
/*
1.- Elabore un programa que presente en pantalla los primeros veinte 20 números que:
a.- Que finalicen en uno (1). 
b.- Que sean divisibles exactamente entre veintiuno (21). 
c.- Que el resultado de su división entre veintiuno (21) al sacarle la raíz cuadrada de un numero entero que termine en uno (1).
El rango a revisar es desde 50000 hasta que consiga los veinte (20) números.
En la pantalla deberá presentarse el número, su división entre veintiuno (21) y la raíz cuadrada de ese resultado que termina en uno (1): 
Numero terminado en uno – División entre 21 – Raíz Cuadrada que termina en uno
54621 – 2601 - 51

*/

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int number = 50000; // Inicializamos el número
    int counter = 0; // Inicializamos el contador

    int endNumber = 1; // Inicializamos el último dígito que queremos que tenga el número
    int divisor = 21; // Inicializamos el divisor

    while(counter < 20){ // Mientras el contador sea menor que 20
        int ultimoDigitoNumero = number % 10; // Obtenemos el último dígito del número
        if(ultimoDigitoNumero == endNumber){ // Si el último dígito del número es igual al último dígito que queremos que tenga el número

            if(number % divisor == 0){ // Si el número es divisible por el divisor
                double division = number / divisor; // Obtenemos el resultado de la división
                double divisionSquareRoot = sqrt(division); // Obtenemos la raíz cuadrada del resultado de la división
                int divisionSquareRootINT = divisionSquareRoot; // Obtenemos el valor entero de la raíz cuadrada del resultado de la división

                if(divisionSquareRoot == divisionSquareRootINT){ // Si la raíz cuadrada del resultado de la división es igual al valor entero de la raíz cuadrada del resultado de la división
                    int ultimoDigitoDivisionRaiz = divisionSquareRootINT % 10; // Obtenemos el último dígito del valor entero de la raíz cuadrada del resultado de la división
                    if(ultimoDigitoDivisionRaiz == endNumber){ // Si el último dígito del valor entero de la raíz cuadrada del resultado de la división es igual al último dígito que queremos que tenga el número
                        cout << number << " - " << division << " - " << divisionSquareRoot << endl; // Mostramos el número, el resultado de la división y la raíz cuadrada del resultado de la división
                        counter++; // Incrementamos el contador
                    }
                }
            }
        }
        number++; // Incrementamos el número
    }
}