#include <iostream>
using namespace std;

// Función para calcular el determinante de una matriz
double determinante(double mat[10][10], int n) {
    double det = 0;

    if (n == 1) {
        return mat[0][0];
    } else if (n == 2) {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    } else {
        double subMat[10][10];  // Submatriz auxiliar para el cofactor
        for (int p = 0; p < n; p++) {
            int subi = 0;  // Índice de fila para submatriz
            for (int i = 1; i < n; i++) {
                int subj = 0;  // Índice de columna para submatriz
                for (int j = 0; j < n; j++) {
                    if (j == p) continue;
                    subMat[subi][subj] = mat[i][j];
                    subj++;
                }
                subi++;
            }
            det += mat[0][p] * determinante(subMat, n - 1) * (p % 2 == 0 ? 1 : -1);
        }
    }
    return det;
}

// Función para reemplazar una columna en la matriz de coeficientes con el vector de términos independientes
void reemplazarColumna(double mat[10][10], double vec[10], double nuevaMat[10][10], int col, int n) {
    // Copiar la matriz original
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            nuevaMat[i][j] = mat[i][j];
        }
    }
    
    // Reemplazar la columna con el vector b
    for (int i = 0; i < n; i++) {
        nuevaMat[i][col] = vec[i];
    }
}

int main() {
    int n;
    double A[10][10];  // Matriz de coeficientes A (máximo 10x10)
    double b[10];      // Vector de términos independientes
    double Ai[10][10]; // Matriz modificada

    // Solicitar el número de ecuaciones y variables
    cout << "Ingrese el número de ecuaciones: ";
    cin >> n;

    // Entrada de los coeficientes de la matriz A
    cout << "Ingrese los coeficientes de la matriz (A):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // Entrada del vector de términos independientes b
    cout << "Ingrese los términos independientes (b):\n";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // Calcular el determinante de la matriz de coeficientes A
    double detA = determinante(A, n);

    // Verificar si el determinante es cero
    if (detA == 0) {
        cout << "El sistema no tiene solución única (determinante de A es 0)." << endl;
        return 1;
    }

    // Calcular los determinantes de las matrices modificadas
    double soluciones[10];  // Arreglo para almacenar las soluciones
    for (int i = 0; i < n; i++) {
        // Crear la matriz Ai reemplazando la columna i por el vector b
        reemplazarColumna(A, b, Ai, i, n);
        soluciones[i] = determinante(Ai, n) / detA;
    }

    // Imprimir la solución
    cout << "\nSolución:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << soluciones[i] << endl;
    }
    return 0;
}
