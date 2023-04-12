/*
Este programa presenta en pantalla los primeros veinte (20) números que al 
sacarle la raíz cuadrada el resultado sea un número: entero, primo y termina en 7

Pasos:
1. Inicializar las variables de inicio y contador.
2. Mostrar el encabezado de la tabla.
3. Inicializar el iterador.
4. Ir comprobando de número en número hasta obtener los 20 números que cumplan las condiciones.
5. Las condiciones son que la raíz sea: entera, primo y termine en 7.
6. Mostrar el número y su raíz cuadrada.
*/
// Autor: Cristian Hernández, 28481734 (12/04/2024) (Programación 1)

#include<iostream>
#include<math.h>
using namespace std;

bool number_is_int(float number){
    // Comprueba si un número es un entero.
    // Input: un número float
    // Output: true si es un entero, false si no lo es.

    // Funcionamiento: Convierte el número a un entero y lo compara con el número original
    // Si la diferencia entre el número y el entero es igual a 0, el número es un entero.

    int numberINT = number;
    if((number - numberINT) == 0){
        return true;
    }
    else return false;
}

bool int_is_prime(int number){
    // Comprueba si un número es primo.
    // Input: un número entero
    // Output: true si es primo, false si no lo es.

    // Funcionamiento: Comprueba si el número es menor o igual a 1, si lo es devuelve false.
    // Si no lo es, comprueba si el número es divisible entre cualquier número entre 2 y la raíz cuadrada del número.
    // Si el número es divisible entre alguno de estos números, devuelve false.
    // (significa que existe un número menor que la raíz cuadrada del número que lo divide)
    // Si el número no es divisible entre ninguno de estos números, devuelve true.

    if((number <= 1)){
        return false;
    }

    for (int i = 2; i <= sqrt(number); i++){
        if (number % i == 0){
            return false;
        };
    };

    return true;
};

bool int_end_in_N(int integer, int endNumber){
    // Comprueba si un número entero termina en un número determinado.
    // Input: un número entero y un número entero que representa el último dígito del número.
    // Output: true si el número entero termina en el número dado, false si no lo hace.

    // Funcionamiento: Obtiene el último dígito del número entero y lo compara con el número dado.
    // Obtiene el último dígito del número entero al hacer la operación mod 10.

    int integerLastDigit = integer % 10;

    if(integerLastDigit == endNumber){
        return true;
    }
    else return false;
};

int main(){
    // Inicializa las variables de inicio y contador.
    int startNumber = 100000;
    int numbersFinded = 0;

    // Muestra el encabezado de la tabla.
    cout << "Número - Raíz Cuadrada (Primo que termina en siete)" << endl;

    // Inicializa el iterador en el número de inicio.
    double itinerator = startNumber;

    // Se ejecutará hasta obtener 20 números.
    while(numbersFinded < 20){
        double itineratorSqrt = sqrt(itinerator);

        // Chequea si la raíz del número es entera, prima y termina en 7
        if(number_is_int(itineratorSqrt)){
            if(int_is_prime(itineratorSqrt) & int_end_in_N(itineratorSqrt, 7)){
                // Si lo es, muestra el número y su raíz separado por un guión.
                // Aumenta el contador de números encontrados.
                cout << itinerator << " - " << itineratorSqrt << endl;
                numbersFinded++;
            };
        };

        // Aumenta el número a revisar, para revisar el siguiente.
        itinerator++;
    };

    return 0;
};