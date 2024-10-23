// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//Default
void mostrarEcuacion(int Sys[26][26]);
void imprimirMatriz(int Sys[26][26]);
int determinanteSistema (int Sys[26][26]);

//Cramer XYZ
int determinanteX (int Sys[26][26]);
int determinanteY (int Sys[26][26]);
int determinanteZ (int Sys[26][26]);



#endif // FUNCTIONS_H
