// functions.h
#ifndef FUNCTIONS4_H
#define FUNCTIONS4_H
#include <complex>
using Complex = std::complex<double>;

double cramer4Sistema(double Sys[5][5]);
double cramer4W(double Sys[5][5]);
double cramer4X(double Sys[5][5]);
double cramer4Y(double Sys[5][5]);
double cramer4Z(double Sys[5][5]);

#endif // FUNCTIONS4_H