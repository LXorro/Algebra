#include <iostream>
#include <iomanip>
#include <cmath>
#include "Functions.h"
#include <complex>
#include <string>
#include <sstream>

using namespace std;
using Complex = complex<double>;



void inSys(double Sys[26][26], string SysStr[26][26], int T) {
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
            
            // Guardar la entrada en SysStr para mantener el formato original
            SysStr[i][j] = input;

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

void printEq(double Sys[26][26], string SysStr[26][26], int T) {
    for (size_t i = 0; i < T; i++) { 
        for (size_t j = 0; j < T; j++) {
            if (Sys[i][j] >= 0) {
                if (j == 0) {  
                    cout << " " << SysStr[i][j] << char(j + 'a');
                } else {
                    cout << " +" << SysStr[i][j] << char(j + 'a');
                }
            } else {
                if (j == 0) {  
                    cout << " " << SysStr[i][j] << char(j + 'a');
                } else {
                    cout << " " << SysStr[i][j] << char(j + 'a');
                }
            }
        }
        // Imprimir el término independiente (última columna, T)
        cout << " = " << SysStr[i][T];
        cout << endl;
    }
}


void printMat(string SysStr[26][26], int T) {
    for (size_t i = 0; i < T; i++) {
        for (size_t j = 0; j < T; j++) {
            cout << setw(12) << SysStr[i][j] << " ";  // Ancho fijo de 12 para cada valor
        }
        cout << "| " << setw(12) << SysStr[i][T];
        cout << endl;
    }
}

/*---------------------------------------------------------------------------Complejos---------------------------------------------------------------------------*/

void inCSys(Complex Sys[26][26], string SysCStr[26][26], int T) {
    for (size_t i = 0; i < T; i++) {
        for (size_t j = 0; j <= T; j++) {
            string inputReal, inputImag;
            double real, imag;

            if (j < T) {
                // Entrada de la parte real del coeficiente
                cout << "Ingrese la parte real del coeficiente " << char(j + 97) << " de la ecuacion " << i + 1 << ": ";
                cin >> inputReal;
                SysCStr[i][j] = inputReal;  // Guardar en SysCStr

                real = (inputReal.find('/') != string::npos) ?
                    stod(inputReal.substr(0, inputReal.find('/'))) / stod(inputReal.substr(inputReal.find('/') + 1)) :
                    stod(inputReal);

                // Entrada de la parte imaginaria del coeficiente
                cout << "Ingrese la parte imaginaria del coeficiente " << char(j + 97) << " de la ecuacion " << i + 1 << ": ";
                cin >> inputImag;
                SysCStr[i][j] += " + " + inputImag + "i";  // Guardar en SysCStr

                imag = (inputImag.find('/') != string::npos) ?
                    stod(inputImag.substr(0, inputImag.find('/'))) / stod(inputImag.substr(inputImag.find('/') + 1)) :
                    stod(inputImag);

                Sys[i][j] = Complex(real, imag);  // Guardar como número complejo en Sys
            } else {
                // Entrada de la parte real de la variable independiente
                cout << "Ingrese la parte real de la variable independiente de la ecuacion " << i + 1 << ": ";
                cin >> inputReal;
                SysCStr[i][j] = inputReal;  // Guardar en SysCStr

                real = (inputReal.find('/') != string::npos) ?
                    stod(inputReal.substr(0, inputReal.find('/'))) / stod(inputReal.substr(inputReal.find('/') + 1)) :
                    stod(inputReal);

                // Entrada de la parte imaginaria de la variable independiente
                cout << "Ingrese la parte imaginaria de la variable independiente de la ecuacion " << i + 1 << ": ";
                cin >> inputImag;
                SysCStr[i][j] += " + " + inputImag + "i";  // Guardar en SysCStr

                imag = (inputImag.find('/') != string::npos) ?
                    stod(inputImag.substr(0, inputImag.find('/'))) / stod(inputImag.substr(inputImag.find('/') + 1)) :
                    stod(inputImag);

                Sys[i][j] = Complex(real, imag);  // Guardar como número complejo en Sys
            }
        }
    }
}

// Función para imprimir el sistema de ecuaciones con números complejos en el formato original
void printCEq(Complex Sys[26][26], string SysCStr[26][26], int T) {
    for (size_t i = 0; i < T; i++) { 
        for (size_t j = 0; j < T; j++) {
            if (j != 0) {
                cout << " + ";
            }
            cout << "(" << SysCStr[i][j] << ")" << char(j + 'a');
        }
        // Imprime el término independiente (última columna)
        cout << " = (" << SysCStr[i][T] << ")";
        cout << endl;
    }
}

// Imprimir matriz de números complejos en formato de fracciones almacenadas en SysStrC
void printMatC(string SysStrC[26][26], int T) {
    for (size_t i = 0; i < T; i++) {
        for (size_t j = 0; j < T; j++) {
            cout << setw(18) << "(" << SysStrC[i][j] << ") ";  // Ancho fijo de 18 para cada valor complejo
        }
        cout << "| " << setw(18) << "(" << SysStrC[i][T] << ")";
        cout << endl;
    }
}