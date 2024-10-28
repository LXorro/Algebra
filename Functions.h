// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <complex>
using Complex = std::complex<double>;

//Default
void inSys (double Sys [26][26], int T);
void printEq(double Sys[26][26], int T);
void printMat(double Sys[26][26], int T);

//Cramer 
double determinanteCramer(double Sys[26][26], int T);;
void cramer(double Sys[26][26], double solutions[25], int T);


/*----------------------Complejos-----------------------*/

//Defaulti
void inCSys (Complex CSys[26][26],int T);
void printCEq (Complex CSys[26][26],int T);
void printMatC(Complex Sys[26][26], int T);




//Cramer 3i
Complex determinanteCCramer(Complex matrix[26][26], int n);
void cramerC(Complex Sys[26][26], Complex solutions[25], int n);




#endif // FUNCTIONS_H
