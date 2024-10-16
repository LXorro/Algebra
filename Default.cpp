#include <iostream>
#include "Functions.h"

using namespace std;


void mostrarEcuacion(int Sys[3][4]) {
    for (size_t i = 0; i < 3; i++) {
        cout << Sys[i][0] << "x + " << Sys[i][1] << "y + " << Sys[i][2] << "z = " << Sys[i][3] << '\n';
    }
}

void imprimirMatriz(int Sys[3][4]) {
    for (size_t i = 0; i < 3; i++) {
        cout << Sys[i][0] << "  " << Sys[i][1] << "  " << Sys[i][2] << '\n';
    }
}

int determinanteSistema (int Sys[3][4]){
  int Det;
  Det = Sys[0][0]*((Sys[1][1] * Sys[2][2]) - (Sys[1][2] * Sys[2][1])) -
        Sys[0][1]*((Sys[1][0] * Sys[2][2]) - (Sys[1][2] * Sys[2][0])) +
        Sys[0][2]*((Sys[1][0] * Sys[2][1]) - (Sys[1][1] * Sys[2][0]));
return Det;
}