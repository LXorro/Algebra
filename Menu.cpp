#include <iostream>
#include "math.h"
#include "Functions.h"
#include "stdio.h"

using namespace std;

int main() {

  int Sys [3][4];

  int T;
  int Method;

  cout << "Ingrese el tamaño del sistema 3/4 ";
  cin >> T;

  switch (T) {

    case 3:
    for (size_t i = 0; i < 3; i++) {
    
      cout << "\n Ingresa el coeficiente x de la "<< i+1 << " ecuacion: ";
      cin >> Sys [i][0];

      cout << "\n Ingresa el coeficiente y de la "<< i+1 << " ecuacion: ";
      cin >> Sys [i][1];

      cout << "\n Ingresa el coeficiente z de la "<< i+1 << " ecuacion: ";
      cin >> Sys [i][2];

      cout << "\n Ingresa el coeficiente resultado de la "<< i+1 << " ecuacion: ";
      cin >> Sys [i][3];
      system("cls");
      }
      
      cout << "\nSistema de ecuaciones ingresado:\n";
      mostrarEcuacion(Sys);

      cout<<"\nLa matriz es \n";
      imprimirMatriz(Sys);

      cout << "\n Ingrese el metodo a usar" ;
      cout << "\n 1.Reduccion" << "\n 2.Igualacion" << "\n 3.Sustitucion";
      cout << "\n 4.Gauss" << "\n 5.Gauss-Jordan" << "\n 6.Cramer" << "\n 7.Cofactores \n ";

      cin >> Method ; 

      switch (Method)
      {
      case 1:
        //REDUCCION
        break;

      case 2:
      //IGUALACION
        break;

      case 3:
      //SUSTITUCION
        break;

      case 4:
      //GAUSS
        break;

      case 5:
      //GAUSS-JORDAN
        break;
      
      case 6:
      cout<<"\nLa determinante del sistema es \n" << determinanteSistema(Sys);

      //Cramer
      cout<<"\n La determinante de X es \n" << determinanteX(Sys);

      cout<<"\n La determinante de Y es \n" << determinanteY(Sys);

      cout<<"\n La determinante de Z es \n" << determinanteZ(Sys) << '\n' ;

      cout << "\nX= " << static_cast<double>(determinanteX(Sys)) / determinanteSistema(Sys);
      cout << "\nY= " << static_cast<double>(determinanteY(Sys)) / determinanteSistema(Sys);
      cout << "\nZ= " << static_cast<double>(determinanteZ(Sys)) / determinanteSistema(Sys);

        break;

      case 7:
      //COFACTORES
        break;

      default:
        break;
      }

      break;//TERMINA 3x3

      case 4:
      cout << "\n Ingrese el metodo a usar" ;
      cout << "\n 1.Reduccion" << "\n 2.Igualacion" << "\n 3.Sustitucion";
      cout << "\n 4.Gauss" << "\n 5.Gauss-Jordan" << "\n 6.Cramer" << "\n 7.Cofactores";

      switch (Method)
      {
      case 1:
        //REDUCCION4
        break;

      case 2:
      //IGUALACION4
        break;

      case 3:
      //SUSTITUCION4
        break;

      case 4:
      //GAUSS4
        break;

      case 5:
      //GAUSS-JORDAN4
        break;
      
      case 6:
      //CRAMER4
        break;

      case 7:
      //COFACTORES4
        break;

      default:
        break;
      }
        break;
  

    default:
      break;
  }

system("pause");


}