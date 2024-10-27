#include <iostream>
#include "math.h"
#include "Functions.h"
#include "stdio.h"
#include "Functions4.h"
#include <complex>

using namespace std;
using Complex = complex<double>;

int main() {
  double Sys[26][26];
  Complex CSys[26][26];
  int Type;
  int T;
  int Method;
  double A[25];
  
  
do {
        cout << "Ingrese el tamanio del sistema 3/4: ";
        cin >> T;
        cout << "1. Numeros normales \n2. Numeros complejos: ";
        cin >> Type;

        if ((T != 3 && T != 4) || (Type != 1 && Type != 2)) {
          
          system("cls");
            cout << "Valores incorrectos. Intente de nuevo." << endl;
        }
    } while ((T != 3 && T != 4) || (Type != 1 && Type != 2));


  switch (Type) {
    case 1:  // Numeros normales

      cout << "Ingrese el sistema de ecuaciones\n";
      inSys(Sys, T);
      cout << "\nSistema de ecuaciones ingresado:\n";
      printEq(Sys, T);
      cout << "\nLa matriz es:\n";
      printMat(Sys, T);
      cout << "\nIngrese el metodo a usar:";
      cout << "\n 1. Reduccion\n 2. Igualacion\n 3. Sustitucion";
      cout << "\n 4. Gauss\n 5. Gauss-Jordan\n 6. Cramer\n 7. Cofactores \n";
      cin >> Method;

      switch (T) {
        case 3:
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

              determinanteCramer(Sys,T);
              cramer(Sys, A, T);


              for (size_t i = 0; i < T-1; i++){
                cout << char('a'+i) << " = " << A[i+1] << "\n";
              }
              cout << char('a'+T) << " = " << A[0] << "\n";
              break;
            case 7:
              // COFACTORES
              break;
            default:
              cout << "Metodo invalido\n";
              break;
          }
          break;

        case 4:
          switch (Method) {
            case 1:
              // REDUCCION4
              break;
            case 2:
              // IGUALACION4
              break;
            case 3:
              // SUSTITUCION4
              break;
            case 4:
              // GAUSS4
              break;
            case 5:
              // GAUSS-JORDAN4
              break;
            case 6:
              // CRAMER4
                            determinanteCramer(Sys,T);
              cramer(Sys, A, T);


              for (size_t i = 0; i < T-1; i++){
                cout << char('a'+i) << " = " << A[i+1] << "\n";
              }
              cout << char('a'+T) << " = " << A[0] << "\n";
              break;
              break;
            case 7:
              // COFACTORES4
              break;
            default:
              cout << "Metodo invalido\n";
              break;
          }
          break;

        default:
          cout << "Tamano de sistema invalido\n";
          break;
      }
      break;
/*-------------------------------------------COMPLEJOS-------------------------------------------------*/
    case 2:
      cout << "Ingrese el sistema de ecuaciones\n";
      inCSys(CSys, T);
      cout << "\nSistema de ecuaciones ingresado:\n";
      printCEq(CSys, T);
      cout << "\nLa matriz es:\n";
      printMatC(CSys, T);
      cout << "\nIngrese el metodo a usar:";
      cout << "\n 1. Reduccion\n 2. Igualacion\n 3. Sustitucion";
      cout << "\n 4. Gauss\n 5. Gauss-Jordan\n 6. Cramer\n 7. Cofactores \n";
      cin >> Method;

      switch (T) {
        case 3:
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
              break;
            case 7:
              // COFACTORES
              break;
            default:
              cout << "Metodo invalido\n";
              break;
          }
          break;

        case 4:
          switch (Method) {
            case 1:
              // REDUCCION4
              break;
            case 2:
              // IGUALACION4
              break;
            case 3:
              // SUSTITUCION4
              break;
            case 4:
              // GAUSS4
              break;
            case 5:
              // GAUSS-JORDAN4
              break;
            case 6:
              // CRAMER4
              break;
            case 7:
              // COFACTORES4
              break;
            default:
              cout << "Metodo invalido\n";
              break;
          }
          break;

        default:
          cout << "Tamano de sistema invalido\n";
          break;
      }
      break;

    default:
      cout << "Tipo de sistema invalido\n";
      break;
  }

  system("pause");
  return 0;
}
