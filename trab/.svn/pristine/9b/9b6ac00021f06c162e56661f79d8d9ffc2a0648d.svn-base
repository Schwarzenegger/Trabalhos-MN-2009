#include "funcao.hpp"

Funcao::Funcao(float Qs)
{
        this->Qs = Qs;
}

Funcao::~Funcao()
{
	
}

void Funcao::IntervaloRaiz()
{
   int iteration = 0;
   float i = 0.0;      //início do intervalo positivo
   float j = 1.0;      //fim do intervalo positivo
   float a = -1.0;     //fim do intervalo negativo
   float b = 0.0;      //início do intervalo negativo
   QPointF isolament(1,2); //ponto inicial do isolamento
   bool achou = false; //indica se o isolamento foi achado

   while( (iteration < MAX_ITERACOES) && (!achou) )
   {
      if((iteration % 2) == 0) //'anda' no eixo positivo
      {
         if( this->RaizExiste(i,j) ) //existe raiz no eixo positivo?
         {
            //armazena o isolamento encontrado
            isolament.setX(i);  //mínimo do isolamento
            isolament.setY(j);  //máximo do isolamento

            achou = true;       //achei o isolamento! : )
         }
         else //continua até estourar o limite de iterações
         {
            i = j;
            j++;
         }
      }
      else //'anda' no eixo negativo
      {
         if( this->RaizExiste(a,b) ) //existe raiz no eixo negativo?
         {
            //armazena o isolamento encontrado
            isolament.setX(a);  //mínimo do isolamento
            isolament.setY(b);  //máximo do isolamento

            achou = true;       //achei o isolamento! : )
         }
         else  //continua até estourar o limite de iterações
         {
            b = a;
                a--;
         }
      }
      iteration++;
   }

   this->isolamento = isolament; //armazena o isolamento
}


QPointF Funcao::getIntervaloRaiz()
{
	this->IntervaloRaiz();
	return this->isolamento;
}

bool Funcao::RaizExiste(float a,float b)
{
   float pa;  
   float pb;  
   
   pa = this->Y(a);  //valor da função em a
   pb = this->Y(b);  //valor da função em b
   
   //retorna false se os dois valores da função aplicados nos pontos a e b,
   //são maiores que zero quando multiplicados um pelo outro
   if((pa * pb) > 0) return(false);
   
   //retorna true caso contrário
   return(true);
}
