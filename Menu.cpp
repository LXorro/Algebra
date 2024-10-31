#include <iostream>
#include "math.h"
#include "Functions.h"
#include "stdio.h"
#include <complex>
#include <string>
#include <sstream>

using namespace std;
using Complex = complex<double>;


int main() {
  system("Color 17");
  double Sys[26][26];
  Complex CSys[26][26];
  int Type;
  int T;
  int Method;
  double A[25];
  Complex AC[25];
  string SysStr [26][26];
  string SysCStr [26][26];

  
do {
        cout << "Ingrese el tamanio del sistema 3/4: ";
        cin >> T;
        cout << "1. Numeros normales \n2. Numeros complejos: ";
        cin >> Type;

        if (Type != 1 && Type != 2) {
          
          system("cls");
            cout << "Valores incorrectos. Intente de nuevo." << endl;
        }
    } while (Type != 1 && Type != 2);

switch (Type) {
  case 1:
    cout << "Ingrese el sistema de ecuaciones\n";
    inSys(Sys, SysStr, T);
    cout << "\nSistema de ecuaciones ingresado:\n";
    printEq(Sys, SysStr, T);
    cout << "\nLa matriz es:\n";
    printMat(SysStr, T);
    cout << "\nIngrese el metodo a usar:";
    cout << "\n 1. Reduccion\n 2. Igualacion\n 3. Sustitucion";
    cout << "\n 4. Gauss\n 5. Gauss-Jordan\n 6. Cramer\n 7. Cofactores \n";
    cin >> Method;

    switch (Method) {
      case 1:
        // REDUCCION
        break;
      case 2:
        // IGUALACION
        break;
      case 3:
        // SUSTITUCION
        break;
      case 4:
        // GAUSS
        break;
      case 5:
        // GAUSS-JORDAN
        break;
      case 6:
        // CRAMER
        determinanteCramer(Sys, T);
        cramer(Sys, A, T);
        cout << char('a') << " = " << A[0] << "\n";
        for (size_t i = 0; i < T - 1; i++) {
          cout << char('b' + i) << " = " << A[i + 1] << "\n";
        }
        break;
      case 7:
        // COFACTORES
        // determinanteCofactores(Sys,T);
        // cofactores(Sys,A,T);
        // cout << char('a') << " = " << A[0] << "\n";
        // for (size_t i = 0; i < T - 1; i++) {
        //   cout << char('b' + i) << " = " << A[i + 1] << "\n";
        // }
        break;
      default:
        cout << "Metodo Invalido";
        break;
    }
    break;

  case 2:
    cout << "Ingrese el sistema de ecuaciones complejos\n";
    inCSys(CSys, SysCStr, T);
    cout << "\nSistema de ecuaciones ingresado:\n";
    printCEq(CSys, SysCStr, T);
    cout << "\nLa matriz es:\n";
    printMatC(SysCStr, T);
    cout << "\nIngrese el metodo a usar:";
    cout << "\n 1. Reduccion\n 2. Igualacion\n 3. Sustitucion";
    cout << "\n 4. Gauss\n 5. Gauss-Jordan\n 6. Cramer\n 7. Cofactores \n";
    cin >> Method;

    switch (Method) {
      case 1:
        // REDUCCION COMPLEX
        break;
      case 2:
        // IGUALACION COMPLEX
        break;
      case 3:
        // SUSTITUCION
        break;
      case 4:
        // GAUSS
        break;
      case 5:
        // GAUSS-JORDAN
        break;
      case 6:
        // CRAMER
        determinanteCCramer(CSys, T);
        cramerC(CSys, AC, T);
        cout << char('a') << " = " << AC[0] << "\n";
        for (size_t i = 0; i < T - 1; i++) {
          cout << char('b' + i) << " = " << AC[i + 1] << "\n";
        }
        break;
      case 7:
        // COFACTORES
        break;
      default:
        cout << "Metodo Invalido";
        break;
    }
    break;

  default:
    cout << "Tipo invalido";
    break;
}

system("pause");
return 0;
}


