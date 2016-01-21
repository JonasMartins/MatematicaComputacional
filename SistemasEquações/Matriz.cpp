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
  product->columns=product->rows=m->rows;
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
matriz * Matriz::gauss(){

  double factor;
  coordinates *p,*q;
  p = (coordinates*)malloc(sizeof(coordinates));
  q = (coordinates*)malloc(sizeof(coordinates));

  fat_l = (matriz*)malloc(sizeof(matriz));
  fat_l->columns=fat_l->rows=m->rows;
  fat_l->data=aloca(fat_l->rows,fat_l->columns);

  identityMatriz(fat_l);// transforma fat_l em identidade

  k=(getDimension())-1;
  int l=0;
  while(l<(m->rows-1)){
    while(k>l){
    q = getCoordinates(k,l);
    p = getMaxColumn(m,l);
    if(q->value=p->value && (p->rows>l)){
      permuteLines(l,p->rows);
      }
      factor = m->data[k][l]/m->data[l][l];
      factor*=-1;
      fat_l->data[k][l] = factor;//preenchendo matriz L
        for(j=0;j<m->columns;j++){
          m->data[k][j]+=factor*m->data[l][j];
        }
      d->data[k][0]+=factor*d->data[l][0];
      showSystem();
      k--;
    }
    k=m->rows-1;
    l++;
  }
  return m;
}

coordinates * Matriz::getMaxColumn(matriz *m,int column){
  coordinates *p;
  p = (coordinates*)malloc(sizeof(coordinates));
  p->value=abs(m->data[column][column]);
  p->rows=column;
  p->columns=column;
  //0 antes
  for(i=column;i<m->rows;i++){
    if(abs(m->data[i][column])>p->value){
      p->value=abs(m->data[i][column]);
      p->rows=i;
      p->columns=column;
    }
  }
  return p;
}

coordinates * Matriz::getCoordinates(int row,int column){
  coordinates *p;
  p = (coordinates*)malloc(sizeof(coordinates));
  p->value=abs(m->data[row][column]);
  p->rows=row;
  p->columns=column;
  return p;
}
matriz * Matriz::copyMatriz(matriz *m,matriz *mm){
  for(j=0;j<m->rows;j++)
    for(i=0;i<m->columns;i++)
      mm->data[j][i]=m->data[j][i];

  return m;
}
void Matriz::reverseL(){
   for(j=0;j<m->rows;j++){
    for(i=0;i<m->columns;i++){
      if(fat_l->data[j][i]<0){
        fat_l->data[j][i]*=-1;
      }
      if(fat_l->data[j][i]>1){
        fat_l->data[j][i]*=-1;
      }
    }
  }
}
void Matriz::fatoracaoLU(){
  printf("\n\nMatriz L:\n");
  reverseL();
  showMatriz(fat_l);
  printf("Matriz U:\n");
  showMatriz(m);
  printf("Matriz LU:\n");
  showMatriz(times(fat_l,m));
}




