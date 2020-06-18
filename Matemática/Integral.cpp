/*
	Integral
	
	No c�lculo, a integral de uma fun��o foi criada originalmente para determinar a �rea sob uma curva no plano cartesiano.
*/

#include <bits/stdc++.h>

using namespace std;

/*
	O m�todo "integral" retorna o resultado da integral de uma fun��o passada na forma de um m�todo ou na forma de uma fun��o lambda 
	juntamente com seus limites. 
	
		- fun��o lambda:
	
			[](double x) { return sin(x); }
		
		- m�todo:
	
			double func(double x) { return sin(x); }
		
	A precis�o da integral � definida pelo variavel "precissao".
*/
double integral(double(*funcao)(double), double a, double b) {
	
	double precissao = 0.00001;
	
	double resultado = 0.0;
	
	for(double i = a; i < b; i += precissao)
		resultado += funcao(i) * precissao;
	
	return resultado;
}

