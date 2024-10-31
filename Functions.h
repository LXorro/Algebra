// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <complex>
#include <string>
#include <sstream>
using Complex = std::complex<double>;
using namespace std;

//Default
void inSys (double Sys [26][26], string SysStr[26][26], int T);
void printEq(double Sys[26][26], string SysStr[26][26], int T);
void printMat(string SysStr[26][26], int T);

//Cramer 
double determinanteCramer(double Sys[26][26], int T);;
void cramer(double Sys[26][26], double solutions[25], int T);


//Cofactores


/*----------------------Complejos-----------------------*/

//Defaulti
void inCSys (Complex Sys[26][26], string SysCStr[26][26], int T);
void printCEq (Complex Sys[26][26], string SysCStr[26][26], int T);
void printMatC(string SysStrC[26][26], int T);




//Cramer 3i
Complex determinanteCCramer(Complex matrix[26][26], int n);
void cramerC(Complex Sys[26][26], Complex solutions[25], int n);




#endif // FUNCTIONS_H
