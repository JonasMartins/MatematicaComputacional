#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

typedef struct{

  double x0;
  double x1;
  double fx0;
  double fx1;
  double raiz;
  double fx;
  double erro;
  int k;

}tipo_output;

#define MAXITERATIONS 7 // EDGE...

class Secante{

  public:
  Secante(tipo_output *);
  void showMainTitle();
  void setStructure(tipo_output *);
  bool checkPrecision();
  void showTurnIterarion();
  void run();
  double calculateFx(double);
  tipo_output * secant();
  tipo_output * changeTerms();

  private:
  tipo_output *t;

};


