/*
	F�rmulas Matem�ticas
	
	- somatorio_quadrado: Retorna a soma dos "n" primeiros n�meros ao quadrado.
	- integral: Retorna a integral de uma fun��o em um intervalo de pontos.
	- derivada: retorna a derivada de uma fun��o em um determinado ponto.
*/

#include <iostream>
#include <cmath>

using namespace std;

/*
	O m�todo "somatorio_quadrado" retorna a soma ao quadrado dos "n" primeiros inteiros reais. 
	
	resultado = (1)^2 + (2)^2 + ... (n)^2
*/
long long somatorio_quadrado(long long a) {
	
	long long resultado = (a * (a + 1) * (2 * a + 1)) / 6;
		
	return resultado;
}

/*
	O m�todo "integral" retorna o resultado da integral passada pelo uma m�todo ou uma fun��o lambda juntamente com seus limites. 
	
	Fun��o lambda:
	
		[](double x) { return sin(x); }
		
	M�todo:
	
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

/*
	O m�todo "derivada" retorna o resultado a derivada passada pelo uma m�todo ou uma fun��o lambda em um ponto especifico. 
	
	fun��o lambda:
	
		[](double x) { return sin(x); }
		
	m�todo:
	
		double func(double x) { return sin(x); }
		
	A precis�o da derivada � definida pelo variavel "precissao".
*/
double derivada(double(*funcao)(double), double ponto) {
	
	double precissao = 0.00000001;
	
	return (funcao(ponto + precissao) - funcao(ponto)) / precissao;
}

