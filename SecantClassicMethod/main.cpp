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
  s.runTradicional();


  tipo_output *tt ;
  tt = (tipo_output*)malloc(sizeof(tipo_output));

  tt->x0 = 1.5;
  tt->x1 = 1.7;
  tt->raiz = 2.0;
  tt->erro = 0.001;
  tt->k=0; // SUPPOSE AT A LEAST ONE TURN.


  Secante ss(tt);
  ss.runMultiplicidade();


  return EXIT_SUCCESS;
}










