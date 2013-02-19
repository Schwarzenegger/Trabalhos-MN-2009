#include "bissecao.h"

bissecao::bissecao(float prec1, float prec2) : ParentMethod(prec1,prec2)
{

}


bissecao::~bissecao()
{

}


void bissecao::calculaRaiz()
{
   float a,b,M,x;

   this->iteracao = 0;
   a = this->funcao->getIntervaloRaiz().x();
   b = this->funcao->getIntervaloRaiz().y();

   if( fabs(b - a) >= this->e1)
   {

      while( (fabs(b - a) >= this->e1) )
      {

         M = this->funcao->Y(a);
         x = (a + b)/2;

         if (M*this->funcao->Y(x) > 0)
         {

            a = x;

         }

         else
         {

            b = x;


         }

      cout << x <<'\n';
     this->iteracao++;

 }
      if(fabs(b - a ) < this->e1) this->criterioDeParada = CRITERIO_POR_E2;
      this->raiz = x; //armazenando a raiz

   }
   else
   {

      this->criterioDeParada = CRITERIO_POR_E3;

      this->raiz = b; //armazenando a raiz
   }

}
