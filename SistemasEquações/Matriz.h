#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

using namespace std;

typedef struct {
  unsigned short rows;
  unsigned short columns;
  int **data;

}matriz;

class Matriz{

  public:
  Matriz(matriz *);
  void showSystem();

  private:
  void setMatriz(matriz *);
  void getValues();
  int ** aloca(int,int);

  matriz *m;


};