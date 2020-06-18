/*
	Derivada
	
	No c�lculo, a derivada em um ponto de uma fun��o "y = f(x)" representa a taxa de varia��o instant�nea de (y)
	em rela��o a (x) neste mesmo ponto.
*/

#include <bits/stdc++.h>

using namespace std;

/*
	O m�todo "derivada" retorna o resultado da integral de uma fun��o passada na forma de um m�todo ou na forma de uma fun��o lambda 
	juntamente com seus limites. 
	
		- fun��o lambda:
	
			[](double x) { return sin(x); }
		
		- m�todo:
	
			double func(double x) { return sin(x); }
		
	A precis�o da derivada � definida pelo variavel "precissao".
*/
double derivada(double(*funcao)(double), double ponto) {
	
	double precissao = 0.00000001;
	
	return (funcao(ponto + precissao) - funcao(ponto)) / precissao;
}

