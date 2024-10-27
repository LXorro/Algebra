#include <iostream>
#include "Functions.h"
#include <complex>

using namespace std;
using Complex = complex<double>;


double determinanteCramer(double Sys[26][26], int T) {
    double det = 0;

    if (T == 1) {
        return Sys[0][0];
    } else if (T == 2) {
        return Sys[0][0] * Sys[1][1] - Sys[0][1] * Sys[1][0];
    } else {
        double minor[26][26];
        for (int i = 0; i < T; i++) {
            int minor_row = 0;
            for (int j = 1; j < T; j++) {
                int minor_col = 0;
                for (int k = 0; k < T; k++) {
                    if (k == i) continue;
                    minor[minor_row][minor_col] = Sys[j][k];
                    minor_col++;
                }
                minor_row++;
            }
            det += (i % 2 == 0 ? 1 : -1) * Sys[0][i] * determinanteCramer(minor, T - 1);
        }
    }
    return det;
}

void cramer(double Sys[26][26], double solutions[25], int T) {
    double det_main = determinanteCramer(Sys, T);

    for (int i = 0; i < T; i++) {
        double temp_Sys[26][26];

        // Copiamos la matriz y reemplazamos la columna `i` con los resultados
        for (int row = 0; row < T; row++) {
            for (int col = 0; col < T; col++) {
                temp_Sys[row][col] = Sys[row][col];
            }
            temp_Sys[row][i] = Sys[row][T];
        }

        solutions[i] = determinanteCramer(temp_Sys, T) / det_main;
    }
}

/*-------------------------------Complejos--------------------------------*/

