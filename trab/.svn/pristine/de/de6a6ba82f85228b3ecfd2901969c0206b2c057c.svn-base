#include "posicaofalsa.hpp"

posicaofalsa::posicaofalsa(float prec1, float prec2) : ParentMethod(prec1,prec2)
{
}

posicaofalsa::~posicaofalsa()
{

}

void posicaofalsa::calculaRaiz()
{

float a,b,M,x,xa;

   this->iteracao = 0;
   a = this->funcao->getIntervaloRaiz().x();
   b = this->funcao->getIntervaloRaiz().y();

   x = 0;
   xa = 0;

   if (this->e2 < 0.0000001 )
   {
    this->e2 = 0.000001;
   }

   if( fabs(b - a) >= this->e1)
   {

      while( (fabs(b - a) >= this->e1)  )
      {

         M = this->funcao->Y(a);
         x = (a*this->funcao->Y(b) - b*this->funcao->Y(a))/(this->funcao->Y(b) - this->funcao->Y(a));       

         if (fabs(this->funcao->Y(x)) <= this->e2)
         {
            this->iteracao++;
            this->criterioDeParada = CRITERIO_POR_E1;
            this->raiz = x;
            break;
        }
         if (M*this->funcao->Y(x) > 0)
         {
            a = x;

         }
         else
         {
            b = x;

         }
      xa = x;
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
