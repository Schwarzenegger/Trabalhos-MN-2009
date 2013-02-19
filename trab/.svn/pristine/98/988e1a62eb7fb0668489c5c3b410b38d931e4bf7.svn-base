#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <QWidget>
#include <QtOpenGL>
#include "bissecao.h"
#include "posicaofalsa.hpp"

class Canvas : public QGLWidget
{
    Q_OBJECT
public:
    //construtor
    Canvas(QWidget *parent = 0);


    //retornando uma lista de coisas a serem comparadas entre o método de Bissecao e PF
    QList<float> retornaComp();

    //calculos dos Qe
    QList<float> Qebissecao(QList<float> dias, float prec1, float prec2);

    //calculos dos Qe
    QList<float> QePF(QList<float> dias, float prec1, float prec2);


    //método virtual para desenhar na tela
    void draw();
  
protected:
    //métodos virtuais da QGLWidget
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
   
    //método para plotar os eixos 
    void plota_eixo();
    //método para plotar o gráfico da função
    void plota_funcao();

private:
	
        ParentMethod *metodobissecao;
        ParentMethod *metodoPF;
	
    //Membros de Dados
    float xmin;         //valor min de x
    float xmax;         //valor max de x
    float ymin;         //valor min de y
    float ymax;         //valor max de y
    int pontos;         //numero de pontos \O/
    float pmax;         //max das retas dos intervalos
    float pmin;         //min das retas dos intervalos
    float fmax;         //max das flechas 
    float raizIniBis;   //raiz inicial pelo método da Bissecao
    float raizFimBis;   //raiz final pelo método da Bissecao
    float raizIniPF;   //raiz inicial pelo método do PF
    float raizFimPF;   //raiz final pelo método do PF
};

#endif

