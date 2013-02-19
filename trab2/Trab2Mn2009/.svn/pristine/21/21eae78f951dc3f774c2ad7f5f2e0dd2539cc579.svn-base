#include "gaussjordan.h"

GaussJordan::GaussJordan(float **m, int numlinhas){
  this -> matriz = new float*[numlinhas];
  this -> numlinhas = numlinhas;

  for (int i = 0; i < numlinhas; i++) {
    this -> matriz[i] = new float[numlinhas];

    for (int j = 0; j < numlinhas; j++) {
      this -> matriz[i][j] = m[i][j];
    }
  }

  for (int i = 0; i < numlinhas; i++) {//Cada passo do metodo
    float maior = matriz[i][i];
    int linha = i;

    for (int j = i + 1; j < numlinhas; j++) {
      if (matriz[j][i] > maior) {
        maior = matriz[j][i];
        linha = j;
      }
    }

    if (linha != i) {
      trocaLinhas(i, linha);
    }

    if (matriz[i][i] != 0) {
      for (int j = 0; j < numlinhas; j++) {
        if (j != i) {
          float multiplicador = matriz[j][i]/matriz[i][i];

          for (int k = 0; k < numlinhas; k++) {
            matriz[j][k] = matriz[j][k] - multiplicador*matriz[i][k];
          }
        }
      }
    }
  }
}

GaussJordan::~GaussJordan() {
  for (int i = 0; i < numlinhas; i++) {
    delete matriz[i];
  }

  delete matriz;
}

void GaussJordan::trocaLinhas(int l1, int l2) {
  for (int i = 0; i < numlinhas; i++) {
    float temp = matriz[l1][i];
    matriz[l1][i] = matriz[l2][i];
    matriz[l2][i] = temp;
  }
}

float GaussJordan::determinante() {
  float det = 1;

  for (int i = 0; i < numlinhas; i++) {
    det = det*matriz[i][i];
  }

  return det;
}
