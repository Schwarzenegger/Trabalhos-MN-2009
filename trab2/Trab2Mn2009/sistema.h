#ifndef __SISTEMA_H__

#define __SISTEMA_H__

class Sistema {
  private:
    float **matriz;
    int numlinhas, numcolunas;
    float *Qe;

    void calculaQe();
    void trocaColunas(int i, int j);
  public:
    Sistema(float **matriz, int numlinhas, int numcolunas);
    ~Sistema();
    float getQe(int i) { return Qe[i]; }
};

#endif /* __SISTEMA_H__ */
