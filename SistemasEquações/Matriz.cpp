#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include "./Matriz.h"


Matriz::Matriz(matriz *m){
  setMatriz(m);
  m->data = aloca(m->rows,m->columns);//alocando a matriz
}
void Matriz::setMatriz(matriz *mm){
  m = mm;
}

double ** Matriz::aloca( int lin, int col ){
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
matriz * Matriz::getValues(){
  cout<<"Digite a Sequencia Segundo as definições dadas\n";
  for(i=0;i<m->rows;i++)
    for(j=0;j<m->columns;j++)
      cin>>m->data[i][j];
  return m;
}

matriz * Matriz::getVectorD(){
  d = (matriz*)malloc(sizeof(matriz));
  d->rows=m->rows;
  d->columns=1; //Vetor uma coluna!
  d->data = aloca(d->rows,d->columns);//alocando a matriz
  cout<<"Digite o vetor D\n";
  for(i=0;i<d->rows;i++)
    cin>>d->data[i][0];
  return d;
}

matriz * Matriz::getValues_Default(){

  unsigned short mat_u[3][3] = {
    {20,7,9},{7,30,8},{9,8,30}
  };
  for(i=0;i<m->rows;i++)
    for(j=0;j<m->columns;j++)
      m->data[i][j] = mat_u[i][j];
  return m;
}

matriz * Matriz::getVectorD_Default(){

  unsigned short mat_b[3] = {16,38,38};

  d = (matriz*)malloc(sizeof(matriz));
  d->rows=m->rows;
  d->columns=1; //Vetor uma coluna!
  d->data = aloca(d->rows,d->columns);//alocando a matriz
  cout<<"Digite o vetor D\n";
  for(i=0;i<d->rows;i++)
    d->data[i][0] = mat_b[i];
  return d;
}

void Matriz::showSystem(){
  //string aux="";
  //stringstream s;
  for(i=0;i<m->rows;i++){
    for(j=0;j<m->columns;j++){
        printf("%3s"," ");
        printf("%04.1f",m->data[i][j]);// perfect!
      }
    //s<<i+1;
    //aux="x"+s.str();
    printf("%3s"," ");
    //cout<< "|"+aux+"|";
    //s.str(std::string());// apagando s streamstream.
    //printf("%3s"," ");
    printf("|%.1f|",d->data[i][0]);
    cout<<"\n";
  }
}

matriz * Matriz::gauss(){
  // stopd here work on git later;
  double factor;
  factor = m->data[1][0]/m->data[0][0];
  factor*=-1;
  for(i=0;i<m->rows;i++){
    m->data[1][i] += factor*m->data[0][i];
  }
  d->data[1][0]+=factor*d->data[0][0];
  return m;
}






