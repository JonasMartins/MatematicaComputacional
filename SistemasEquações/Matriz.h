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
  Matriz(matriz *);//Construtor
  void showSystem();//Mostra o sistema completo
  void showMatriz(matriz *);//Mostra uma matriz especifica
  void showResult();//Mostra o resultado do sistema
  void menu();
  void run();
  void runDefault();
  void runUserValues();
  void setValues();//User digita U
  void setVectorD();//User digita D
  void setValues_Default();//seta U padrão
  void setVectorD_Default();//seta D padrão
  matriz * getMatriz();//retorna U
  matriz * getVectorD();//retorna d
  matriz * gauss();
  matriz * times(matriz *,matriz *);//multiplica duas matrizes



  private:
  unsigned short i;
  unsigned short j;
  double ** aloca(int,int);//Famigerada Aloca...
  void createEmptyMatriz();
  void resetEmptyMatriz();
  void setMatriz(matriz *);//Seta no Construtor
  matriz * permuteOne_to_two();
  matriz * permuteOne_to_three();
  matriz * permuteTwo_to_three();

  matriz *m;
  matriz *n;//Matriz de Permutações
  matriz *d;

};

