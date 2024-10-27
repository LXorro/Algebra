#include <iostream>
#include <iomanip>
#include <cmath>
#include "Functions.h"
#include <complex>

using namespace std;
using Complex = complex<double>;




// Funcion para ngresar los coeficientes y variables independientes
void inSys (double Sys [26][26],int T){
        for (size_t i = 0; i < T; i++) {
        for (size_t j = 0; j <= T; j++) {
              if (j < T) {
                cout << "Ingrese el coeficiente " << char(j + 97) << " de la ecuacion " << i + 1 << ": ";
                cin >> Sys[i][j];
              } else {
                cout << "Ingrese la variable independiente de la ecuacion " << i + 1 << ": ";
                cin >> Sys[i][j];
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
                    cout << " " << Sys[i][j] << char(j + 'w');
                } else {  // Si no es el primero, se imprime con un +
                    cout << " +" << Sys[i][j] << char(j + 'w');
                }
            } else {  // Si el número no es positivo
                if (j == 0) {  // Si es el primer coeficiente, se imprime sin signo a la izquierda
                    cout << " " << Sys[i][j] << char(j + 'w');
                } else {  // Si no es el primero, se imprime el valor tal cual (con su signo)
                    cout << " " << Sys[i][j] << char(j + 'w');
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
            double real, imag;
            if (j < T) {
                cout << "Ingrese la parte real del coeficiente " << char(j + 97) << " de la ecuacion " << i + 1 << ": ";
                cin >> real;
                cout << "Ingrese la parte imaginaria del coeficiente " << char(j + 97) << " de la ecuacion " << i + 1 << ": ";
                cin >> imag;
                Sys[i][j] = Complex(real, imag);
            } else {
                cout << "Ingrese la parte real de la variable independiente de la ecuacion " << i + 1 << ": ";
                cin >> real;
                cout << "Ingrese la parte imaginaria de la variable independiente de la ecuacion " << i + 1 << ": ";
                cin >> imag;
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
            cout << "(" << Sys[i][j].real() << ", " << Sys[i][j].imag() << "i)" << char(j + 'w');
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