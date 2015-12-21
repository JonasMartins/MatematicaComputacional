#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include "./Matriz.h"


int main(int argc,char **argv){

  matriz *m;
  m = (matriz*)malloc(sizeof(matriz));
  m->rows = 3;
  m->columns = 3;

  Matriz matriz(m); // instanciando...

  matriz.showSystem();

  return EXIT_SUCCESS;
}