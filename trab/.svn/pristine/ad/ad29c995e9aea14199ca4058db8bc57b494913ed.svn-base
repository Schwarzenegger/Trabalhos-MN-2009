#ifndef FUNCAO_HPP_
#define FUNCAO_HPP_

class Funcao;

/**
 * numero maximo de iteracoes para isolar uma raiz
 */

#define MAX_ITERACOES 100000

/**
 * define o valor de pi
 */
#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

#include <QPointF>
#include <math.h>
#include <iostream>
using namespace std;
/**
 * classe da funcao dos metodos
 */

class Funcao
{
private:
	/**
	 * isola uma raiz da equacao
	 */
	void IntervaloRaiz();
	/**
	 * verifica se existe raiz entre a e b
	 * \return true caso exista raiz no intervalo
	 * \return false caso contrario
	 */
	bool RaizExiste(float a, float b);
	QPointF isolamento;
	/**
         * valor de Qs na equacao;
	 */
        float Qs;
	
public:
	
	/**
	 * construtor da funcao
	 */
        Funcao(float Qs);
	
	/**
	 * destrutor da funcao
	 */
	~Funcao();
	
	/**
	 * retorna um intervalo onde contem uma raiz da funcao
	 */
	QPointF getIntervaloRaiz();
	
        void setQs(float Qs)
	{
                this->Qs = Qs;
		this->IntervaloRaiz();
	}
	
	/**
         * retorn o valor de Qs
	 */
        float getQs()
	{
                return this->Qs;
	}
	/**
	 * retorna o valor y aplicando x
	 */
	float Y(float x)
	{
                return this->Qs*pow(x,3) - x -1;
	}
	


};
#endif /*FUNCAO_HPP_*/
