#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "./Secante.h"

using namespace std;


  Secante::Secante(tipo_output *t){
    setStructure(t);
  }
  void Secante::setStructure(tipo_output *tt){
    t = tt;
  }
  double Secante::calculateFx(double x){

    /*  função tradicional
    double blockOne = pow(x,4.0) - 5*pow(x,3.0); // FUNCÃO DO TRABALHO!
    double blockTwo = 6*pow(x,2.0) + 4*x;
    return (blockOne+blockTwo)-8;
    */
    // função equivalente sem o termo p de multiplicidade;
    double blockOne = pow((x-2),3.0);
    double blockTwo = x+1;
    return blockOne*blockTwo;
    /*
      double blockOne = pow(x,2.0); // FUNCÃO MAIS SIMPLES PARA TESTES
      double blockTwo = x-6;
      return blockOne+blockTwo;
    */
  }
  bool Secante::checkPrecision(){
  if(t->erro >= (t->x1 - t->x0))
    return true;
  return false;
  }

  void Secante::showMainTitle(){
    printf("\n\n%40s======%s======%s\n\n","***"," Result Table ","***");
    printf("%c|%15c|%15s|%15c|%15s|%15c|%15s|%15s|\n",'k','a',"fa",'b',"fb",'x',"fx","result");
  }

  void Secante::showTurnIterarion(){

    printf("%d|%15f|%15f|%15f|%15f|%15s|%15f|%15f|\n",t->k,t->x0,t->fx0,t->x1,t->fx1,"x",t->fx,
        t->raiz - t->fx);
  }

  tipo_output * Secante::secanteTradicional(){

    double numerator;
    double denominator;
    t->k += 1;

    t->fx0 = calculateFx(t->x0);
    t->fx1 = calculateFx(t->x1);

    /* tradicional...*/
    numerator = (t->x0 * t->fx1) - (t->x1 * t->fx0);
    denominator = t->fx1 - t->fx0;

    t->fx = numerator/denominator;

    return t;
  }
  tipo_output * Secante::secanteMultiplicidade(){

    double numerator;
    double denominator;
    t->k += 1;

    t->fx0 = calculateFx(t->x0);
    t->fx1 = calculateFx(t->x1);

    // secante modificada com multiplicidade p = 3;
    numerator = (3*t->fx1)*(t->x1-t->x0);
    denominator = t->fx1 - t->fx0;

    t->fx = numerator/denominator;
    double aux = t->fx;
    t->fx = t->x1 - aux;

    return t;
  }
  tipo_output * Secante::changeTerms(){
    double aux1,aux2;
    aux1 = t->fx - t->x0;
    aux2 = t->fx - t->x1;

    if(aux2 >= aux1){
      t->x1 = t->x0;
      t->x0 = t->fx;
    }
    t->x0 = t->x1;
    t->x1 = t->fx;
    return t;
  }
  void Secante::runTradicional(){
    int i;
    showMainTitle();

    for(i=0;i< MAXITERATIONS ;i++){
      t = secanteTradicional();
      showTurnIterarion();
      t = changeTerms();
      if(checkPrecision())
          exit(0);
    }
  }
  void Secante::runMultiplicidade(){
    int i;
    showMainTitle();

    for(i=0;i< MAXITERATIONS ;i++){
      t = secanteMultiplicidade();
      showTurnIterarion();
      t = changeTerms();
      if(checkPrecision())
          exit(0);
    }
  }

