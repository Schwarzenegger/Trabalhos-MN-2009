#include "canvas.hpp"

Canvas::Canvas(QWidget *parent)
    : QGLWidget(parent)
{
    setFormat(QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer));
    
    //Inicializando os dados
    
    this->metodobissecao = new bissecao(0,0);
    this->metodobissecao->setValorFuncQs(0);
    this->metodoPF = new posicaofalsa(0,0);
    this->metodoPF->setValorFuncQs(0);



    
    this->xmin            = -100.0;
    this->xmax            = 100.0;
    this->ymin            = -30.0;
    this->ymax            = 30.0;
    this->pontos          = 500000;
    this->pmax            = 0.1;
    this->pmin            = -0.1;
    this->fmax            = 0.1;
    this->raizIniBis      = 0;
    this->raizFimBis      = 0;
    this->raizIniPF      = 0;
    this->raizFimPF      = 0;

}

//Inicializa o OpenGL
void Canvas::initializeGL()
{
    qglClearColor(Qt::white);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    
    gluOrtho2D(-10,10,-10,10);
}

//Redimensiona o OpenGL
void Canvas::resizeGL(int width, int height)
{
   glViewport(0, 0, width, height);
   
   glFlush(); 
}

//Pinta no Canvas
void Canvas::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     
    draw();
}


//Desenha no Canvas
void Canvas::draw()
{
    plota_eixo();
    plota_funcao();

}


//desenhando eixo do gráfico
/* -------------------------------- */
void Canvas::plota_eixo()
/* -------------------------------- */
{
   float i,j;
   
   glColor3f(0.0,0.0,1.0);

   //desenhando eixo cartesiano
   glBegin(GL_LINES);
      glVertex2f(this->xmin,0);
      glVertex2f(this->xmax,0);
      glVertex2f(0,this->ymin);
      glVertex2f(0,this->ymax);
   glEnd();

   //desenhando intervalos da abcissa
   for(i = this->xmin; i <= this->xmax; i++)
   {
       glBegin(GL_LINES);
          glVertex2f(i,this->pmin);
          glVertex2f(i,this->pmax);
       glEnd();
   }

   //desenhando intervalos da ordenada
   for(j=this->ymin; j <= this->ymax; j++)
   {
       glBegin(GL_LINES);
          glVertex2f(this->pmin,j);
          glVertex2f(this->pmax,j);
       glEnd();
   }

   //desenhando flechas
   glBegin(GL_LINES);
      glVertex2f(this->xmax,this->pmax);
      glVertex2f(this->xmax+this->fmax,0);
      glVertex2f(this->xmax,this->pmin);
      glVertex2f(this->xmax+this->fmax,0);

      glVertex2f(this->xmin,this->pmax);
      glVertex2f(this->xmin-this->fmax,0);
      glVertex2f(this->xmin,this->pmin);
      glVertex2f(this->xmin-this->fmax,0);

      glVertex2f(this->pmax,this->ymax);
      glVertex2f(0,this->ymax+this->fmax);
      glVertex2f(this->pmin,this->ymax);
      glVertex2f(0,this->ymax+this->fmax);

      glVertex2f(this->pmax,this->ymin);
      glVertex2f(0,this->ymin-this->fmax);
      glVertex2f(this->pmin,this->ymin);
      glVertex2f(0,this->ymin-this->fmax);
   glEnd();
}


QList<float> Canvas::Qebissecao(QList<float> dias,float prec1, float prec2)
{

    int i;
    QList<float> resultado;
    float Qe,Qc;
    this->metodobissecao->setE1(prec1);
    this->metodobissecao->setE2(prec2);

    for(i = 0; i < dias.size(); i += 3)
    {

          this->metodobissecao->setValorFuncQs(dias[i+2]);
          if(i == 0) this->raizIniBis = this->metodobissecao->getRaiz();

          Qe = this->metodobissecao->getRaiz() - dias[i+1];
          Qc =  this->metodobissecao->getRaiz();
          //passando os valores calculados para a lista que será retornada
          resultado << dias[i];
          resultado << Qe;
          resultado << Qc;

    }

    this->raizFimBis = this->metodobissecao->getRaiz(); //raiz final

    return(resultado);



}

QList<float> Canvas::QePF(QList<float> dias,float prec1, float prec2)
{

    int i;
    QList<float> resultado;
    float Qe,Qc;
    this->metodoPF->setE1(prec1);
    this->metodoPF->setE2(prec2);

    for(i = 0; i < dias.size(); i += 3)
    {

          this->metodoPF->setValorFuncQs(dias[i+2]);
          if(i == 0) this->raizIniPF = this->metodoPF->getRaiz();

          Qe = this->metodoPF->getRaiz() - dias[i+1];
          Qc =  this->metodoPF->getRaiz();

         //passando os valores calculados para a lista que será retornada
         resultado << dias[i];
         resultado << Qe;
        resultado << Qc;

    }

    this->raizFimPF = this->metodoPF->getRaiz(); //raiz final

    return(resultado);


}


//retorna os dados para gerar a tabela comparativa entre os métodos
QList<float> Canvas::retornaComp()
{
     //lista de retorno
     QList<float> compList; 
     //isolamento
     float isolamentoXBissecao;
     float isolamentoYBissecao;
     // iteracao
     int   iteracaoBissecao;
     // criterio de parada
     int   criterioParadaBissecao;
     // informacoes do metodo de Bissecao
     isolamentoXBissecao     = this->metodobissecao->funcao->getIntervaloRaiz().x();
     isolamentoYBissecao    = this->metodobissecao->funcao->getIntervaloRaiz().y();
     iteracaoBissecao        = this->metodobissecao->getIteracao();
     criterioParadaBissecao  = this->metodobissecao->getCriterioDeParada();
     

     
     //isolamento
     float isolamentoXPF;
     float isolamentoYPF;
     // iteracao
     int   iteracaoPF;
     // criterio de parada
     int   criterioParadaPF;
     // informacoes do metodo de posicaofalsa
     isolamentoXPF     = this->metodoPF->funcao->getIntervaloRaiz().x();
     isolamentoYPF     = this->metodoPF->funcao->getIntervaloRaiz().y();
     iteracaoPF       = this->metodoPF->getIteracao();
     criterioParadaPF  = this->metodoPF->getCriterioDeParada();
     

     
     //configurando a Lista a ser retornada com todos os valores a serem passados
     compList << iteracaoBissecao << isolamentoXBissecao << isolamentoYBissecao
              << this->raizIniBis << this->raizFimBis << criterioParadaBissecao
              << iteracaoPF << isolamentoXPF << isolamentoYPF
              << this->raizIniPF << this->raizFimPF << criterioParadaPF;

     return(compList); 
}

//Plotando o gráfico da função
/* -------------------------------- */
void Canvas::plota_funcao()
/* -------------------------------- */
{
   int i;
   float dx ;
   float x,y;

   dx = (xmax - xmin)/pontos;

   glColor3f(0.0,0.0,0.0);
   x = this->xmin;

   for(i = 0; i < this->pontos; i++)
   {
           y = this->metodobissecao->funcao->Y(x);

       glBegin(GL_POINTS);
          glVertex2f(x,y);
       glEnd();

       x = x + dx;
   }



   //plotando raiz aproximada de Bissecao no grafico
   //cor dessa raiz: Verde
   glColor3f(0.0,1.0,0.0);

	   glBegin(GL_LINES);
              glVertex2f(this->raizFimBis,1.0);
              glVertex2f(this->raizFimBis,-1.0);
	   glEnd();
   
   //plotando raiz aproximada da posicaofalsa no grafico
   //cor dessa raiz: Vermelha
   glColor3f(1.0,0.0,0.0);
   glBegin(GL_LINES);
      glVertex2f(this->raizFimPF,1.0);
      glVertex2f(this->raizFimPF,-1.0);
   glEnd();
   
}
