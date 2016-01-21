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

  metodologia:
  usa o pivotamento como primeiro passo
  gauss na primeira coluna, testa novamente o
  pivotamento, gauss.... e assim por diante


*/


int main(int argc,char **argv){

  matriz *m;
  m = (matriz*)malloc(sizeof(matriz));
  m->rows = 3;
  m->columns = 3;


  Matriz matriz(m); // instanciando...
  matriz.run();



  return EXIT_SUCCESS;
}

