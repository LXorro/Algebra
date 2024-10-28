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

Complex determinanteCCramer(Complex matrix[26][26], int n) {
    Complex det = 0;

    if (n == 1) {
        return matrix[0][0];
    } else if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        Complex minor[26][26];
        for (int i = 0; i < n; i++) {
            int minor_row = 0;
            for (int j = 1; j < n; j++) {
                int minor_col = 0;
                for (int k = 0; k < n; k++) {
                    if (k == i) continue;
                    minor[minor_row][minor_col] = matrix[j][k];
                    minor_col++;
                }
                minor_row++;
            }
            det += (i % 2 == 0 ? Complex(1, 0) : Complex(-1, 0)) * matrix[0][i] * determinanteCCramer(minor, n - 1);
        }
    }
    return det;
}

void cramerC(Complex Sys[26][26], Complex solutions[25], int n) {
    Complex det_main = determinanteCCramer(Sys, n);

    for (int i = 0; i < n; i++) {
        Complex temp_matrix[26][26];

        // Copia de la matriz principal, reemplazando la columna `i` con los resultados independientes
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                temp_matrix[row][col] = Sys[row][col];
            }
            temp_matrix[row][i] = Sys[row][n];  // Reemplaza con términos independientes
        }

        solutions[i] = determinanteCCramer(temp_matrix, n) / det_main;
    }
}