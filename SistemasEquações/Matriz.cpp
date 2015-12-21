#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include "./Matriz.h"


Matriz::Matriz(matriz *m){
  setMatriz(m);
  m->data = aloca(m->rows,m->columns);//alocando a matriz
  getValues(); //preenchendo a matriz
}
void Matriz::setMatriz(matriz *mm){
  m = mm;
}

int ** Matriz::aloca( int lin, int col ){
  int **ret, i, j;
    if( lin ==0 || col ==0 ){
      printf( "Impossivel alocar espaco\n" );
      exit( 3 );
    }
    ret =(int **)malloc( sizeof(int*) * lin );
    if( ret == NULL  ){
      printf( "Impossivel alocar espaco" );
      exit( 3 );
    }
    ret[0] =(int *)malloc( sizeof(int) * ( lin * col ) );
    if( ret[0] == NULL  ){
      printf( "Impossivel alocar espaco" );
      exit( 3 );
    }
    for( i=1; i<lin; i++ )
      ret[i] = ret[i-1] + col;
   return ret;
}
void Matriz::getValues(){

  // matriz com os indices das equacoes
  unsigned short mat[3][3] = {{1,2,3},
                              {4,5,6},
                              {7,8,9}};

  for(unsigned short i=0;i<m->rows;i++)
    for(unsigned short j=0;j<m->columns;j++)
      m->data[i][j] = mat[i][j];

}
void Matriz::showSystem(){
  for(unsigned short i=0;i<m->rows;i++){
    for(unsigned short j=0;j<m->columns;j++){
        printf("%5d",m->data[i][j]);
      }
    cout<<"\n";
  }
}





