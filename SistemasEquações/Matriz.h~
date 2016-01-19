#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>

using namespace std;

typedef struct {
  unsigned short rows;
  unsigned short columns;
  double **data;
}matriz;

class Matriz{

  public:
  Matriz(matriz *);
  void showSystem();
  matriz * getValues();
  matriz * getVectorD();
  matriz * getValues_Default();
  matriz * getVectorD_Default();
  matriz * gauss();

  private:
  unsigned short i;
  unsigned short j;
  void setMatriz(matriz *);
  double ** aloca(int,int);

  matriz *m;
  matriz *d;

};