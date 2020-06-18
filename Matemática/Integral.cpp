/*
	Integral
	
	No cálculo, a integral de uma função foi criada originalmente para determinar a área sob uma curva no plano cartesiano.
*/

#include <bits/stdc++.h>

using namespace std;

/*
	O método "integral" retorna o resultado da integral de uma função passada na forma de um método ou na forma de uma função lambda 
	juntamente com seus limites. 
	
		- função lambda:
	
			[](double x) { return sin(x); }
		
		- método:
	
			double func(double x) { return sin(x); }
		
	A precisão da integral é definida pelo variavel "precissao".
*/
double integral(double(*funcao)(double), double a, double b) {
	
	double precissao = 0.00001;
	
	double resultado = 0.0;
	
	for(double i = a; i < b; i += precissao)
		resultado += funcao(i) * precissao;
	
	return resultado;
}

