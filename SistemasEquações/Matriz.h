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

typedef struct{
  unsigned short rows;
  unsigned short columns;
  double value;
}coordinates;


class Matriz{

  public:
  Matriz(matriz *);//Construtor

  unsigned short getDimension();// retorna a nova dimensão
  void identityMatriz(matriz *);
  void showMatriz(matriz *);//Mostra uma matriz especifica
  void setVectorD_Default();//seta D padrão
  void setValues_Default();//seta U padrão
  void runUserValues();
  void fatoracaoLU();
  void runDefault();
  void showSystem();//Mostra o sistema completo
  void showResult();//Mostra o resultado do sistema
  void setVectorD();//User digita D
  void setValues();//User digita U
  void reverseL();
  void intro();
  void menu();
  void run();




  void setDimension(int);

  matriz * times(matriz *,matriz *);//multiplica duas matrizes
  matriz * getMatriz();//retorna U
  matriz * getVectorD();//retorna d
  matriz * getN();
  matriz * gauss();
  matriz * copyMatriz(matriz *,matriz *);

  private:
  unsigned short i;
  unsigned short j;
  unsigned short k; // add o k e tirei a criação do
  unsigned short dimension;


  //mesmo posteriormente

  coordinates * getMaxColumn(matriz *,int);
  coordinates * getCoordinates(int,int);
  double ** aloca(int,int);//Famigerada Aloca...
  double ** alocaVetor(int);// alocar linhas da matriz permutação...

  void createEmptyMatriz();
  void resetEmptyMatriz();
  void setMatriz(matriz *);//Seta no Construtor
  matriz * permuteLines(int,int);
  matriz * permuteLinesD(int,int);

  double **rowOne;
  double **rowTwo;
  double **row;
  double **ret;

  matriz *fat_l;
  matriz *m;
  matriz *n;//Matriz de Permutações
  matriz *d;

};

