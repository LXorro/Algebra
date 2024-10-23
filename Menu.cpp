#include <iostream>
#include "math.h"
#include "Functions.h"
#include "stdio.h"

using namespace std;

int main() {

  int Sys[26][26];
  int T;
  int Method;

  cout << "Ingrese el tamaño del sistema: ";
  cin >> T;

  // Verificación básica de entrada
  if (T <= 0 || T > 26) {
      cout << "Tamaño del sistema inválido. Debe estar entre 1 y 26.\n";
      return 1;
  }

  // Ingresar los coeficientes y variables independientes
  for (size_t i = 0; i < T; i++) {
      for (size_t j = 0; j <= T; j++) {
          if (j < T) {
              cout << "Ingrese el coeficiente " << char(j + 97) << " de la ecuación " << i + 1 << ": ";
              cin >> Sys[i][j];
          } else {
              cout << "Ingrese la variable independiente de la ecuación " << i + 1 << ": ";
              cin >> Sys[i][j];
          }
      }
  }

  // Mostrar menú para seleccionar el método
  cout << "\n Ingrese el método a usar";
  cout << "\n 1. Reducción" << "\n 2. Igualación" << "\n 3. Sustitución";
  cout << "\n 4. Gauss" << "\n 5. Gauss-Jordan" << "\n 6. Cramer" << "\n 7. Cofactores \n";
  cin >> Method;

  switch (Method) {
    case 1:
        // Implementar Reducción
        break;

    case 2:
        // Implementar Igualación
        break;

    case 3:
        // Implementar Sustitución
        break;

    case 4:
        // Implementar Gauss
        break;

    case 5:
        // Implementar Gauss-Jordan
        break;

    case 6:
        // cout << "\nLa determinante del sistema es: " << determinanteSistema(Sys);
        // cout << "\nLa determinante de X es: " << determinanteX(Sys);
        // cout << "\nLa determinante de Y es: " << determinanteY(Sys);
        // cout << "\nLa determinante de Z es: " << determinanteZ(Sys);

        // cout << "\nX = " << static_cast<double>(determinanteX(Sys)) / determinanteSistema(Sys);
        // cout << "\nY = " << static_cast<double>(determinanteY(Sys)) / determinanteSistema(Sys);
        // cout << "\nZ = " << static_cast<double>(determinanteZ(Sys)) / determinanteSistema(Sys);
        break;

    case 7:
        // Implementar Cofactores
        break;

    default:
        cout << "Opción inválida.\n";
        break;
  }

  system("pause");
  return 0;
}
