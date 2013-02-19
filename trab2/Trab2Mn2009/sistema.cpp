#include "sistema.h"
#include "gaussjordan.h"

Sistema::Sistema(float **matriz, int numlinhas, int numcolunas) {
  this -> matriz = new float*[numlinhas];
  this -> numlinhas = numlinhas;

  for (int i = 0; i < numlinhas; i++) {
    this -> matriz[i] = new float[numcolunas];

    for (int j = 0; j < numcolunas; j++) {
      this -> matriz[i][j] = matriz[i][j];
    }
  }

  this -> numlinhas = numlinhas;
  this -> numcolunas = numcolunas;
  calculaQe();
}

Sistema::~Sistema() {
  for (int i = 0; i < numlinhas; i++) {
    delete matriz[i];
  }

  delete matriz;
}

void Sistema::trocaColunas(int i, int j) {
  for (int k = 0; k < numlinhas; k++) {
    float temp = matriz[k][i];
    matriz[k][i] = matriz[k][j];
    matriz[k][j] = temp;
  }
}

void Sistema::calculaQe() {
  Qe = new float[numlinhas];

  GaussJordan inicial(matriz, numlinhas);
  float detC = inicial.determinante();



  Qe[0] = detC;

}
