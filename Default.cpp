#include <iostream>
#include <iomanip>
#include <cmath>
#include "Functions.h"
#include <complex>
#include <string>
#include <sstream>

using namespace std;
using Complex = complex<double>;



// Funcion para ngresar los coeficientes y variables independientes
void inSys(double Sys[26][26], int T) {
    for (size_t i = 0; i < T; i++) {
        for (size_t j = 0; j <= T; j++) {
            string input;
            cout << "Ingrese el ";
            if (j < T) {
                cout << "coeficiente " << char(j + 97) << " de la ecuacion " << i + 1 << ": ";
            } else {
                cout << "variable independiente de la ecuacion " << i + 1 << ": ";
            }
            cin >> input;

            // Procesar entrada para detectar y convertir fracción
            size_t pos = input.find('/');
            if (pos != string::npos) {
                // Si encuentra '/', asume que es una fracción
                double numerador = stod(input.substr(0, pos));
                double denominador = stod(input.substr(pos + 1));
                Sys[i][j] = numerador / denominador;
            } else {
                // Si no hay '/', convierte el número directamente
                Sys[i][j] = stod(input);
            }
        }
    }
}

//Imprime la ecuacion
void printEq(double Sys[26][26], int T) {
    for (size_t i = 0; i < T; i++) { 
        for (size_t j = 0; j < T; j++) {
            if (Sys[i][j] >= 0) {  // Si el número es positivo
                if (j == 0) {  // Si es el primer coeficiente no se imprime con signo
                    cout << " " << Sys[i][j] << char(j + 'a');
                } else {  // Si no es el primero, se imprime con un +
                    cout << " +" << Sys[i][j] << char(j + 'a');
                }
            } else {  // Si el número no es positivo
                if (j == 0) {  // Si es el primer coeficiente, se imprime sin signo a la izquierda
                    cout << " " << Sys[i][j] << char(j + 'a');
                } else {  // Si no es el primero, se imprime el valor tal cual (con su signo)
                    cout << " " << Sys[i][j] << char(j + 'a');
                }
            }
        }
        // Imprime el término independiente en ultima columna (T)
        cout << " = " << Sys[i][T];
        cout << endl;
    }
}


//Imrpimir matriz
void printMat(double Sys[26][26], int T) {
    for (size_t i = 0; i < T; i++) {
        for (size_t j = 0; j < T; j++) { // Se fija un ancho de 8 caracteres para cada número con setw
            cout << setw(8) << Sys[i][j] << " ";
        }
        cout << "| " << setw(8) << Sys[i][T];
        cout << endl;
    }
}

/*---------------------------------------------------------------------------Complejos---------------------------------------------------------------------------*/

// Funcion para ingresar los coeficientes y variables independientes como números complejos
void inCSys(Complex Sys[26][26], int T) {
    for (size_t i = 0; i < T; i++) {
        for (size_t j = 0; j <= T; j++) {
            string inputReal, inputImag;
            double real, imag;

            if (j < T) {
                // Entrada de la parte real del coeficiente
                cout << "Ingrese la parte real del coeficiente " << char(j + 97) << " de la ecuacion " << i + 1 << ": ";
                cin >> inputReal;
                real = (inputReal.find('/') != string::npos) ? 
                    stod(inputReal.substr(0, inputReal.find('/'))) / stod(inputReal.substr(inputReal.find('/') + 1)) : stod(inputReal);

                // Entrada de la parte imaginaria del coeficiente
                cout << "Ingrese la parte imaginaria del coeficiente " << char(j + 97) << " de la ecuacion " << i + 1 << ": ";
                cin >> inputImag;
                imag = (inputImag.find('/') != string::npos) ? 
                    stod(inputImag.substr(0, inputImag.find('/'))) / stod(inputImag.substr(inputImag.find('/') + 1)) : stod(inputImag);

                Sys[i][j] = Complex(real, imag);
            } else {
                // Entrada de la parte real de la variable independiente
                cout << "Ingrese la parte real de la variable independiente de la ecuacion " << i + 1 << ": ";
                cin >> inputReal;
                real = (inputReal.find('/') != string::npos) ? 
                    stod(inputReal.substr(0, inputReal.find('/'))) / stod(inputReal.substr(inputReal.find('/') + 1)) : stod(inputReal);

                // Entrada de la parte imaginaria de la variable independiente
                cout << "Ingrese la parte imaginaria de la variable independiente de la ecuacion " << i + 1 << ": ";
                cin >> inputImag;
                imag = (inputImag.find('/') != string::npos) ? 
                    stod(inputImag.substr(0, inputImag.find('/'))) / stod(inputImag.substr(inputImag.find('/') + 1)) : stod(inputImag);

                Sys[i][j] = Complex(real, imag);
            }
        }
    }
}

// Función para imprimir el sistema de ecuaciones con números complejos
void printCEq(Complex Sys[26][26], int T) {
    for (size_t i = 0; i < T; i++) { 
        for (size_t j = 0; j < T; j++) {
            if (j != 0) {
                cout << " + ";
            }
            cout << "(" << Sys[i][j].real() << ", " << Sys[i][j].imag() << "i)" << char(j + 'a');
        }
        // Imprime el término independiente (última columna)
        cout << " = (" << Sys[i][T].real() << ", " << Sys[i][T].imag() << "i)";
        cout << endl;
    }
}

// Función para imprimir la matriz del sistema con números complejos
void printMatC(Complex Sys[26][26], int T) {
    for (size_t i = 0; i < T; i++) {
        for (size_t j = 0; j < T; j++) {
            cout << setw(12) << "(" << Sys[i][j].real() << ", " << Sys[i][j].imag() << "i) ";
        }
        cout << "| " << setw(12) << "(" << Sys[i][T].real() << ", " << Sys[i][T].imag() << "i)";
        cout << endl;
    }
}