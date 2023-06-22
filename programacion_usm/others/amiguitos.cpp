#include <iostream>
using namespace std;

int main () {
    double user_salary;
    double increment;
    string running = "si";

    cout << "Programa que calcula el incremento de un sueldo" << endl;

    while(running == "si"){
        cout << "Ingrese el sueldo: ";
        cin >> user_salary;
        cin.clear();
        cin.ignore();

        if(user_salary >= 1 && user_salary <= 500){
            increment = 0.2;
        }
        else if(user_salary >= 501 && user_salary <= 1000){
            increment = 0.1;
        }
        else if(user_salary >= 1001 && user_salary <= 5000){
            increment = 0.05;
        }
        else if(user_salary > 5000){
            increment = 0;
        }
        else{
            cout << "El sueldo ingresado no es valido" << endl;
            running = false;
        }
        user_salary = user_salary * (1 + increment);

        cout << "El sueldo con el aumento es: " << user_salary <<
                 " con un aumento del: " << (increment * 100) << "% \n";
        cout << "\n";

        cout << "Desea aplicar otro aumento? (si/no): ";
        cin >> running;
        cin.clear();
        cin.ignore();
        cout << "\n";
    }
}

