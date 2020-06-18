/*
	Algoritmo de Detec��o de Ciclo de Floyd
	
	� um algoritmo de detec��o de ciclos ou de constata��o de ciclo.
	
	Dada uma fun��o y = f(x) e um valor inicial x0, ele determina as caracteristicas do ciclo presente na
	sequ�ncia (x0, f(x0), f(f(x0)), ... ) 
*/

#include <bits/stdc++.h>

using namespace std;

/*
	O m�todo "funcao_observada" retorna a fun��o na qual ser� verificada a exist�ncia de ciclos. 
*/
int funcao_observada(int x) {
	
	return (z * x + j) % m; 
}

/*
	O m�todo "floyd" retorna os valores (mu, lambda), onde:
	
		- mu: O �ndice a partir do qual o ciclo se inicia.
		- lambda: O tamanho do ciclo.
*/
pair<int, int> floyd(int x) {

	int tartaruga = funcao_observada(x);
	int lebre = funcao_observada(funcao_observada(x));
	
	while (tartaruga != lebre) { 
	
		tartaruga = funcao_observada(tartaruga); 
		lebre = funcao_observada(funcao_observada(lebre)); 
	}

	int mu = 0; 
	lebre = x;
	
	while (tartaruga != lebre) { 
	
		tartaruga = funcao_observada(tartaruga); 
		lebre = funcao_observada(lebre); 
		mu++;
	}

	int lambda = 1; 
	lebre = funcao_observada(tartaruga);
	
	while (tartaruga != lebre) { 
	
		lebre = funcao_observada(lebre); 
		lambda++; 
	}
	
	return make_pair(mu, lambda);
}

