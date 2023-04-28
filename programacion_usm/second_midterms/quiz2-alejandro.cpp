#include<iostream>
using namespace std;

int main(){
	string palabra = "";
	cout << "Ingrese el texto: " << endl; 
	getline(cin, palabra);
    int longitudPalabra = palabra.size() - 1;

    // imprimir la palabra al reves
	for (int i = longitudPalabra; i >= 0 ; i-- ){
		cout << palabra[i];
	}
	cout << endl;

    // Obtener la cantidad de vocales y consonantes
	int vocales = 0;
	int consonante = 0;
	for (int i = 0; i <= longitudPalabra; i++){
		switch (palabra[i]){
			case 'a': vocales++; break;
			case 'e': vocales++; break;
			case 'i': vocales++; break;
			case 'o': vocales++; break;
			case 'u': vocales++; break;
			
			case 'A': vocales++; break;
			case 'E': vocales++; break;
			case 'I': vocales++; break;
			case 'O': vocales++; break;
			case 'U': vocales++; break;

			case ' ': break;
			
			default: consonante++;
	    }
	}
    cout << "La cantidad de vocales es: " << vocales 
        << ", y la cantidad de consonantes es: " << consonante << endl;

    // Reemplazar las vocales por $
	for (int i = 0; i <= longitudPalabra; i++){
		switch (palabra[i]){
            case 'a': palabra[i] = '$'; break;
            case 'e': palabra[i] = '$'; break;
            case 'i': palabra[i] = '$'; break;
            case 'o': palabra[i] = '$'; break;
            case 'u': palabra[i] = '$'; break;

            case 'A': palabra[i] = '$'; break;
            case 'E': palabra[i] = '$'; break;
            case 'I': palabra[i] = '$'; break;
            case 'O': palabra[i] = '$'; break;
            case 'U': palabra[i] = '$'; break;
		}
	}
    cout << "La palabra con vocales reemplazadas es: " << endl << palabra << endl;

    return 0;
}
