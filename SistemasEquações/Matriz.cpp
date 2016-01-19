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
matriz * Matriz::getMatriz(){
  return m;
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
void Matriz::setValues(){
  cout<<"Digite a Sequencia Segundo as definições dadas\n";
  for(i=0;i<m->rows;i++)
    for(j=0;j<m->columns;j++)
      cin>>m->data[i][j];
}

void Matriz::setVectorD(){
  d = (matriz*)malloc(sizeof(matriz));
  d->rows=m->rows;
  d->columns=1; //Vetor uma coluna!
  d->data = aloca(d->rows,d->columns);//alocando a matriz
  cout<<"Digite o vetor D\n";
  for(i=0;i<d->rows;i++)
    cin>>d->data[i][0];
}

void Matriz::setValues_Default(){

  unsigned short mat_u[3][3] = {
    {20,7,9},{7,30,8},{9,8,30}
  };
  for(i=0;i<m->rows;i++)
    for(j=0;j<m->columns;j++)
      m->data[i][j] = mat_u[i][j];
}

void Matriz::setVectorD_Default(){

  unsigned short mat_b[3] = {16,38,38};

  d = (matriz*)malloc(sizeof(matriz));
  d->rows=m->rows;
  d->columns=1; //Vetor uma coluna!
  d->data = aloca(d->rows,d->columns);//alocando a matriz
  for(i=0;i<d->rows;i++)
    d->data[i][0] = mat_b[i];

}
matriz * Matriz::getVectorD(){
  return d;
}
void Matriz::showSystem(){
  //string aux="";
  //stringstream s;
  for(i=0;i<m->rows;i++){
    for(j=0;j<m->columns;j++){
        printf("%6s"," ");
        printf("%07.4f",m->data[i][j]);// perfect!
      }
    //s<<i+1;
    //aux="x"+s.str();
    printf("%6s"," ");
    //cout<< "|"+aux+"|";
    //s.str(std::string());// apagando s streamstream.
    //printf("%3s"," ");
    printf("|%.4f|",d->data[i][0]);
    cout<<"\n";

  }
  cout<<"\n";
}
void Matriz::showMatriz(matriz *m){
  for(i=0;i<m->rows;i++){
    for(j=0;j<m->columns;j++){
        printf("%6s"," ");
        printf("%07.4f",m->data[i][j]);
      }
      cout<<"\n";
    }
  cout<<"\n";
}

matriz * Matriz::gauss(){
  // stopd here work on git later;
  double factor;
  int k=0;
  i=0;
  while(k<2){
    factor = m->data[i+1][0]/m->data[0][0];
    factor*=-1;
      //cout<<endl;
      //cout<<factor<<endl;
      for(j=0;j<m->columns;j++){
        m->data[i+1][j]+=factor*m->data[0][j];
      }
    d->data[i+1][0]+=factor*d->data[i][0];
    showSystem();
    k++;
    i=k;
  }
  return m;
}

matriz * Matriz::times(matriz *m,matriz *n){//ok
  //Critério
  if(m->columns!=n->rows){
    cout<<"Impossivel multiplicar! Parâmetros incorretos."<<endl;
    exit(0);
  }
  unsigned short q;// outro int
  double buffer=0;
  matriz *product;
  product = (matriz*)malloc(sizeof(matriz));
  //linhas de m e colunas de n
  product->rows=m->rows;
  product->columns=n->columns;
  product->data=aloca(product->rows,product->columns);

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
/*--------------- FUNÇÕES DE PERMUTAÇÃO -----------------*/
void Matriz::createEmptyMatriz(){
  n = (matriz*)malloc(sizeof(matriz));
  n->rows = 3;
  n->columns = 3;
  n->data=aloca(3,3);
  int i,j;
  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
      n->data[i][j]=0;

}
void Matriz::resetEmptyMatriz(){
  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
      n->data[i][j]=0;
}

matriz * Matriz::permuteOne_to_two(){

  resetEmptyMatriz();//reseta n se houver mudado
  //linha 1 troca de lugar com linha 2
  n->data[0][1]=1;
  n->data[1][0]=1;
  n->data[2][2]=1;
  return n;
}

matriz * Matriz::permuteOne_to_three(){

  resetEmptyMatriz();//reseta n se houver mudado
  //linha 1 troca de lugar com linha 3
  n->data[0][2]=1;
  n->data[1][1]=1;
  n->data[2][0]=1;
  return n;
}
matriz * Matriz::permuteTwo_to_three(){

  resetEmptyMatriz();//reseta n se houver mudado
  //linha 2 troca de lugar com 3
  n->data[0][0]=1;
  n->data[1][2]=1;
  n->data[2][1]=1;
  return n;
}

/*------------- FIM DAS FUNÇÕES DE PERMUTAÇÃO  ------------*/

void Matriz::run(){

  createEmptyMatriz();//criado e alocado n;

  //exemplo que prova o funcionamento da multiplicação
  //de matrizes.
  //showMatriz(times(getMatriz(),getVectorD()));


  //exemplo permutações....
  showMatriz(getMatriz());
  showMatriz(times(permuteOne_to_two(),getMatriz()));
  showMatriz(times(permuteOne_to_three(),getMatriz()));
  showMatriz(times(permuteTwo_to_three(),getMatriz()));

}




