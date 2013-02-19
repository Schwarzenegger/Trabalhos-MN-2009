#include "parentmethod.hpp"

ParentMethod::ParentMethod(float prec1,float prec2)
{
	this->e1 = prec1;
	this->e2 = prec2;
	this->funcao = new Funcao(0);
	this->raiz = 0;
	this->iteracao = 0;
	this->criterioDeParada = SEM_CRITERIO;
}

ParentMethod::~ParentMethod()
{
	
}
