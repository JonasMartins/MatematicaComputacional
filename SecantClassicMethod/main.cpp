#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "./Secante.h"

int main(int argc, char**argv){

  /*
    run: c++ -o Secante Secante.cpp -o main main.cpp
         ./main
  */


  tipo_output *t ;
  t = (tipo_output*)malloc(sizeof(tipo_output));

  t->x0 = 1.5;
  t->x1 = 1.7;
  t->raiz = 2.0;
  t->erro = 0.001;
  t->k=0; // SUPPOSE AT A LEAST ONE TURN.

  Secante s(t);
  s.run();

  return EXIT_SUCCESS;
}










