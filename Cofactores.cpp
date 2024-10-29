#include <iostream>
#include <iomanip>
#include "Functions.h"
using namespace std;


double determinanteCofactores(double matrix[26][26], int n) {
    double det = 0;
    if (n == 1) {
        return matrix[0][0];
    } else if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        double minor[26][26];
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
            det += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determinanteCofactores(minor, n - 1);
        }
    }
    return det;
}

// Función para resolver sistemas de ecuaciones usando el método de cofactores
void cofactores(double Sys[26][26], double solutions[25], int n) {
    double det_main = determinanteCofactores(Sys, n);
    if (det_main == 0) {
        std::cerr << "La matriz no tiene inversa. El sistema no tiene solución única." << std::endl;
        return;
    }

    double cofactor_matrix[26][26];

    // Calcular la matriz de cofactores
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double minor[26][26];
            int minor_row = 0;

            // Crear menor
            for (int k = 0; k < n; k++) {
                if (k == i) continue;
                int minor_col = 0;
                for (int l = 0; l < n; l++) {
                    if (l == j) continue;
                    minor[minor_row][minor_col] = Sys[k][l];
                    minor_col++;
                }
                minor_row++;
            }
            // Cofactor con signo alternante
            cofactor_matrix[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * determinanteCofactores(minor, n - 1);
        }
    }

    // Transponer la matriz de cofactores (adjunta)
    double adjunta[26][26];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjunta[i][j] = cofactor_matrix[j][i];
        }
    }

    // Multiplicar la matriz adjunta por el término independiente y dividir entre el determinante principal
    for (int i = 0; i < n; i++) {
        solutions[i] = 0;
        for (int j = 0; j < n; j++) {
            solutions[i] += adjunta[i][j] * Sys[j][n];
        }
        solutions[i] /= det_main;
    }
}