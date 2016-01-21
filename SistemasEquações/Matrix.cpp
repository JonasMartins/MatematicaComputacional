#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include "./Matriz.h"

unsigned short Matriz::getDimension(){
  return dimension;
}
void Matriz::setDimension(int value){
  dimension=value;
}
double ** Matriz::aloca( int lin, int col ){

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

  for(i=0;i<m->rows;i++){
    for(j=0;j<m->columns;j++){
        printf("%6s"," ");
        printf("%07.4f",m->data[i][j]);
      }
    printf("%6s"," ");
    printf("|%.4f|",d->data[i][0]);
    cout<<"\n";
  }
  printf("%s\n","--------------------------------------------------------------");
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

/*--------------- FUNÇÕES DE PERMUTAÇÃO -----------------*/
void Matriz::createEmptyMatriz(){
  n = (matriz*)malloc(sizeof(matriz));
  n->columns=n->rows=m->rows;
  n->data=aloca(getDimension(),getDimension());
  int i,j;
  for(i=0;i<n->rows;i++)
    for(j=0;j<n->columns;j++)
      n->data[i][j]=0;

}
void Matriz::resetEmptyMatriz(){// Matriz identidade
  for(i=0;i<n->rows;i++)
    for(j=0;j<n->columns;j++)
      n->data[i][j]=0;

  for(i=0;i<n->rows;i++)
      n->data[i][i]=1;
}

void Matriz::identityMatriz(matriz *n){// Matriz identidade
  for(i=0;i<n->rows;i++)
    for(j=0;j<n->columns;j++)
      n->data[i][j]=0;

  for(i=0;i<n->rows;i++)
      n->data[i][i]=1;
}

matriz * Matriz::getN(){
  return n;
}
double ** Matriz::alocaVetor(int size){
// recebo a dimensão da linha e retorno um vetor double
// para guardar esses valores

  row =(double **)malloc( sizeof(double*));
    if( row == NULL  ){
      printf( "Impossivel alocar espaco" );
      exit( 3 );
    }
  row[0] =(double *)malloc( sizeof(double)*(size));
    if(row[0] == NULL  ){
      printf( "Impossivel alocar espaco" );
      exit( 3 );
    }
  return row;
}

matriz * Matriz::permuteLines(int line1, int line2){

  //resetEmptyMatriz();//reseta n se houver mudado
  /*VETOR ALOCADO DINAMICAMENTE PARA PEGAR A
  LINHA CORRESPONDENTE DA MATRIZ IDENTIDADE*/

  rowOne=alocaVetor(m->columns);// aloco um vetor do tamanaho de uma linha de n...
  rowTwo=alocaVetor(m->columns);
  for(i=0;i<m->rows;i++){
    rowOne[0][i]=m->data[line1][i];// preencho rowOne com primeira linha
    rowTwo[0][i]=m->data[line2][i];// preencho rowTwo com segunda linha
  }

  /* --------- fazendo a troca de linhas ---------  */
  for(i=0;i<n->rows;i++){
    m->data[line1][i] = rowTwo[0][i];
    m->data[line2][i] = rowOne[0][i];
  }
  permuteLinesD(line1,line2);
  return m;
}
matriz * Matriz::permuteLinesD(int line1, int line2){
  rowOne=alocaVetor(1);
  rowTwo=alocaVetor(1);

  rowTwo[0][0]=d->data[line1][0];
  rowOne[0][0]=d->data[line2][0];
  d->data[line1][0]=rowOne[0][0];
  d->data[line2][0]=rowTwo[0][0];
  return d;
}

void Matriz::showResult(){//depois de gauss....
  double x3,x2,x1,aux;

  aux = m->data[2][2];if(aux==0){aux+=0,00000001;}
  x3 = d->data[2][0]/aux;

  aux = d->data[1][0] - (x3*m->data[1][2]);
  if(m->data[1][1]==0){m->data[1][1]+=0,00000001;}
  x2 = aux/m->data[1][1];

  aux = d->data[0][0]-((x2*m->data[0][1])+(x3*m->data[0][2]));
  if(m->data[0][0]==0){m->data[0][0]+=0,00000001;}
  //jamais seria 0
  x1 = aux/m->data[0][0];

  printf("SOLUÇÃO:\nX3:%5f\nX2:%5f\nX1:%5f\n",x3,x2,x1);
}
/*------------- FIM DAS FUNÇÕES DE PERMUTAÇÃO  ------------*/


/*------------- MENUS  ------------*/
void Matriz::intro(){
  printf("\n\n%60s\n","### SISTEMAS DE EQUAÇÕES ###");
  printf("\n\n%60s\n\n\n","### MÉTODOS NUMÉRICOS I ###");
}
void Matriz::menu(){
  printf("\n\n%60s\n\n","### FATORAÇÃO LU COM PIVOTAÇÃO ###");
  cout<<"Digite a opção Válida:\n";
  cout<<"1): VALORES PADRÕES\n";
  cout<<"2): USUÁRIO DIGITA O SISTEMA\n";
  cout<<"3): EXIT\n";
}
void Matriz::runDefault(){
  setDimension(3);//padrão
  createEmptyMatriz();//criado e alocado n;
  resetEmptyMatriz();
  setValues_Default();
  setVectorD_Default();
  showSystem();
  gauss();
  showResult();
  fatoracaoLU();

}
void Matriz::runUserValues(){
  createEmptyMatriz();//criado e alocado n;
  resetEmptyMatriz();
  setValues();
  setVectorD();
  showSystem();
  gauss();
  showResult();
  fatoracaoLU();
}

void Matriz::run(){

  //exemplo que prova o funcionamento da multiplicação
  //de matrizes.
  //showMatriz(times(getMatriz(),getVectorD()));
  menu();
  int choice;
  cin>>choice;
    switch(choice){
      case 1:
        runDefault();
        break;
      case 2:
        //int n;
        free(m->data[0]);// leberanco memoria;
        free(m);
        cout<<"Digite n (Matriz nxn)\n";
        cin>>dimension;
        matriz *m;
        m = (matriz*)malloc(sizeof(matriz));
        m->rows=m->columns = dimension;
        setMatriz(m);// alocando novamente com as novas dimensões
        m->data = aloca(m->rows,m->columns);//alocando a matriz
        runUserValues();
        break;
      case 3:
        exit(0);
        break;
      default:
        cout<<"Erro!";
        exit(0);
        break;
      }
}

