#ifndef PARENTMETHOD_HPP_
#define PARENTMETHOD_HPP_

class ParentMethod;

#include "funcao.hpp"
#include <QPointF>
#include <iostream>

using namespace std;


#define SEM_CRITERIO       0
#define CRITERIO_POR_E1    1
#define CRITERIO_POR_E2    2
#define CRITERIO_POR_E3    3

/**
 * classe de metodo generico, com caracteristica comum a todos os metodos abordados
 */
class ParentMethod
{
protected:
	/**
	 * intervalo de criterio de parada do metodo
	 * para quando |a-b| >= e1
	 */
	float e1;
	/**
	 * itervalo de criterio de parada do metodo
	 * para quando |f(a)| >= e2
	 */
	float e2;
	/**
	 * armazena o criterio de parada quando calcula a raiz aproximada
	 */
	int criterioDeParada;

	/**
	 * valor da raiz aproximada
	 */
	float raiz;
	/**
	 * numero de iteracoes para calcular a raiz
	 */
	int iteracao;

	/**
	 * construtor do metodo
	 * \param x0 valor inicial
	 * \precisao e1
	 * \precisao e2
	 */
	ParentMethod(float prec1, float prec2);
	/**
	 * destrutor
	 */
	virtual ~ParentMethod();
	/**
	 * calcula uma aproximaxao para raiz
	 */
	virtual void calculaRaiz() = 0;
public:
	
	/**
	 * muda a precisao e1
	 */
	void setE1(float e1)
	{
		this->e1 = e1;
	}
	/**
	 * muda a precisao e1
	 */
	void setE2(float e2)
	{
		this->e2 = e2;
	}
	/**
	 * retorna a raiz
	 */
	float getRaiz()
	{
		this->calculaRaiz();
		return this->raiz;
	}
	
	/**
	 * muda o valor de a na funcao do metodo
	 */
        void setValorFuncQs(float Qs)
	{
                this->funcao->setQs(Qs);
		
	}
	
	int getCriterioDeParada()
	{
		return this->criterioDeParada;
	}
	
	int getIteracao()
	{
		return this->iteracao;
	}
	
	void resetIteracao()
	{
		this->iteracao = 0;
	}
	/**
	 * funcao usada no metodo
	 */
	Funcao *funcao;
	
};

#endif /*PARENTMETHOD_HPP_*/
