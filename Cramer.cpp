#include <iostream>
#include "Functions.h"

using namespace std;

int determinanteX (int Sys[3][4]){

  int DetX = Sys[0][3] * ((Sys[1][1] * Sys[2][2]) - (Sys[1][2] * Sys[2][1])) -
         Sys[0][1] * ((Sys[1][3] * Sys[2][2]) - (Sys[1][2] * Sys[2][3])) +
         Sys[0][2] * ((Sys[1][3] * Sys[2][1]) - (Sys[1][1] * Sys[2][3]));
return DetX;
}


int determinanteY (int Sys[3][4]){
  int DetY;
  DetY = Sys[0][0] * ((Sys[1][3] * Sys[2][2]) - (Sys[1][2] * Sys[2][3])) -
           Sys[0][3] * ((Sys[1][0] * Sys[2][2]) - (Sys[1][2] * Sys[2][0])) +
           Sys[0][2] * ((Sys[1][0] * Sys[2][3]) - (Sys[1][3] * Sys[2][0]));;
return DetY;
}


int determinanteZ (int Sys[3][4]){
  int DetZ;
  DetZ = Sys[0][0] * ((Sys[1][1] * Sys[2][3]) - (Sys[1][3] * Sys[2][1])) -
           Sys[0][1] * ((Sys[1][0] * Sys[2][3]) - (Sys[1][3] * Sys[2][0])) +
           Sys[0][3] * ((Sys[1][0] * Sys[2][1]) - (Sys[1][1] * Sys[2][0]));
return DetZ;
}