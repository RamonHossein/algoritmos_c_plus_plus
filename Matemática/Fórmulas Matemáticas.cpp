/*
	Fórmulas Matemáticas
	
	- somatorio_quadrado: Retorna a soma dos "n" primeiros números ao quadrado.
	- integral: Retorna a integral de uma função em um intervalo de pontos.
	- derivada: retorna a derivada de uma função em um determinado ponto.
*/

#include <iostream>
#include <cmath>

using namespace std;

/*
	O método "somatorio_quadrado" retorna a soma ao quadrado dos "n" primeiros inteiros reais. 
	
	resultado = (1)^2 + (2)^2 + ... (n)^2
*/
long long somatorio_quadrado(long long a) {
	
	long long resultado = (a * (a + 1) * (2 * a + 1)) / 6;
		
	return resultado;
}

/*
	O método "integral" retorna o resultado da integral passada pelo uma método ou uma função lambda juntamente com seus limites. 
	
	Função lambda:
	
		[](double x) { return sin(x); }
		
	Método:
	
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

/*
	O método "derivada" retorna o resultado a derivada passada pelo uma método ou uma função lambda em um ponto especifico. 
	
	função lambda:
	
		[](double x) { return sin(x); }
		
	método:
	
		double func(double x) { return sin(x); }
		
	A precisão da derivada é definida pelo variavel "precissao".
*/
double derivada(double(*funcao)(double), double ponto) {
	
	double precissao = 0.00000001;
	
	return (funcao(ponto + precissao) - funcao(ponto)) / precissao;
}

