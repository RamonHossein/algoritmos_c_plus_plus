/*
	Derivada
	
	No cálculo, a derivada em um ponto de uma função "y = f(x)" representa a taxa de variação instantânea de (y)
	em relação a (x) neste mesmo ponto.
*/

#include <bits/stdc++.h>

using namespace std;

/*
	O método "derivada" retorna o resultado da integral de uma função passada na forma de um método ou na forma de uma função lambda 
	juntamente com seus limites. 
	
		- função lambda:
	
			[](double x) { return sin(x); }
		
		- método:
	
			double func(double x) { return sin(x); }
		
	A precisão da derivada é definida pelo variavel "precissao".
*/
double derivada(double(*funcao)(double), double ponto) {
	
	double precissao = 0.00000001;
	
	return (funcao(ponto + precissao) - funcao(ponto)) / precissao;
}

