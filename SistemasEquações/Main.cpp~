#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include "./Matriz.h"


/*
  A = 20  7  9    d = 16
      7  30  8        38
      9  8   30       38
*/


int main(int argc,char **argv){

  matriz *m;
  m = (matriz*)malloc(sizeof(matriz));
  m->rows = 3;
  m->columns = 3;

  Matriz matriz(m); // instanciando...
  /*
  Matrizes Dadas pelo user
  matriz.getValues();
  matriz.getVectorD();
  */

  /* Sistema Default*/
  matriz.getValues_Default();
  matriz.getVectorD_Default();
  matriz.showSystem();
  matriz.gauss();
  cout<<"\n";
  matriz.showSystem();
  return EXIT_SUCCESS;
}