#include <iostream>
#include "stdio.h"
#include <vector>
#include <iomanip>  // Para controlar la precisión de los resultados

using namespace std;

// Función para realizar la eliminación de Gauss-Jordan
void gaussJordan(vector<vector<double>>& A, int n) {
    for (int i = 0; i < n; i++) {
        // Encontrar el pivote y normalizar la fila
        if (A[i][i] == 0) {
            // Si el pivote es 0, buscar una fila con un valor no cero y hacer el intercambio
            for (int k = i + 1; k < n; k++) {
                if (A[k][i] != 0) {
                    swap(A[i], A[k]);
                    break;
                }
            }
        }

        // Dividir toda la fila por el valor del pivote
        double pivot = A[i][i];
        if (pivot != 0) {
            for (int j = 0; j <= n; j++) {
                A[i][j] /= pivot;
            }
        }

        // Eliminar los valores de las otras filas en la columna actual
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = A[k][i];
                for (int j = 0; j <= n; j++) {
                    A[k][j] -= factor * A[i][j];
                }
            }
        }
    }
}

int main() {
    int n;

    // Solicitar el número de ecuaciones y variables
    cout << "Ingrese el número de ecuaciones: ";
    cin >> n;

    // Matriz aumentada de tamaño n x (n+1)
    vector<vector<double>> A(n, vector<double>(n + 1));

    // Entrada de datos
    cout << "Ingrese la matriz aumentada del sistema (coeficientes y términos independientes):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    // Realizar el proceso de eliminación de Gauss-Jordan
    gaussJordan(A, n);

    // Imprimir la solución
    cout << "\nSolución:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(6) << A[i][n] << endl;
    }

    system("pause");

    return 0;
}
