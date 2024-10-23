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

double determinantesistema(double Sys[26][26], int T) {
    double det = 0;

    if (T == 1) {
        return Sys[0][0];
    } else if (T == 2) {
        return Sys[0][0] * Sys[1][1] - Sys[0][1] * Sys[1][0];
    } else {
        double subSys[26][26];
        for (int p = 0; p < T; p++) {
            int subi = 0;  
            for (int i = 1; i < T; i++) {
                int subj = 0; 
                for (int j = 0; j < T; j++) {
                    if (j == p) continue;
                    subSys[subi][subj] = Sys[i][j];
                    subj++;
                }
                subi++;
            }
            det += Sys[0][p] * determinantesistema(subSys, T - 1) * (p % 2 == 0 ? 1 : -1);
        }
    }
    return det;
}
