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

double ** aloca( int lin, int col ){
  double **ret;
  int k;
    if( lin ==0 || col ==0 ){
      printf( "Impossivel alocar espaco\n" );
      exit( 3 );
    }
    ret =(double **)malloc( sizeof(double*) * lin );
    if( ret == NULL  ){
      printf( "Impossivel alocar espaco" );
      exit( 3 );
    }
    ret[0] =(double *)malloc( sizeof(double) * ( lin * col ) );
    if( ret[0] == NULL  ){
      printf( "Impossivel alocar espaco" );
      exit( 3 );
    }
    for( k=1; k<lin; k++ )
      ret[k] = ret[k-1] + col;
   return ret;
}


matriz * times(matriz *m,matriz *n){
  int i,j;
  //Critério
  if(m->columns!=n->rows){
    cout<<"Impossivel multiplicar! Parâmetros incorretos."<<endl;
    exit(0);
  }
  int q;// outro int
  double buffer=0;
  matriz *product;
  product = (matriz*)malloc(sizeof(matriz));
  //linhas de m e colunas de n
  product->rows=m->rows;
  product->columns=n->columns;
  product->data=aloca(3,3);

  for(q=0;q<m->rows;q++){
    for(i=0;i<m->columns;i++){
      for(j=0;j<n->rows;j++){
        buffer+=(m->data[q][j]*n->data[j][i]);
        product->data[q][i]=buffer;
      }
      buffer=0;
    }
  }

  return product;
}

matriz * setValues_Default(matriz *m){
  int i,j;
  unsigned short mat_u[3][3] = {
    {20,7,9},{7,30,8},{9,8,30}
  };
  for(i=0;i<m->rows;i++)
    for(j=0;j<m->columns;j++)
      m->data[i][j] = mat_u[i][j];
  return m;
}

void showMatriz(matriz *m){
  int i,j;
  for(i=0;i<m->rows;i++){
    for(j=0;j<m->columns;j++){
        printf("%6s"," ");
        printf("%07.4f",m->data[i][j]);
      }
      cout<<"\n";
    }
  cout<<"\n";
}

int main(){


  matriz *m;
  m = (matriz*)malloc(sizeof(matriz));
  m->rows = 3;
  m->columns = 3;
  m->data=aloca(3,3);

  m = setValues_Default(m);

  matriz *n;
  n = (matriz*)malloc(sizeof(matriz));
  n->rows = 3;
  n->columns = 3;
  n->data=aloca(3,3);

  int i,j;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++)
      n->data[i][j]=0;
  }
  /* //linha 1 troca de lugar com linha 3
  n->data[0][2]=1;
  n->data[1][1]=1;
  n->data[2][0]=1;
  */
  /* //linha 2 troca de lugar com 3
  n->data[0][0]=1;
  n->data[1][2]=1;
  n->data[2][1]=1;
  */
  /* //linha 1 troca de lugar com a 2
  n->data[0][1]=1;
  n->data[1][0]=1;
  n->data[2][2]=1;
  */
  // troca de uma vez duas:
  //linha 1 troca com a 2
  //depois linha 2 troca com a linha 1
  n->data[0][2]=1;
  n->data[1][0]=1;
  n->data[2][1]=1;



  showMatriz(n);
  showMatriz(m);

  showMatriz(times(n,m));

  return 0;
}





