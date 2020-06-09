/*
	Algoritmo de Detecção de Ciclo de Floyd
	
	É um algoritmo de detecção de ciclo ou constatação de ciclo.
	
	Dada uma função y = f(x) e um valor inicial x0, ele determina as características do cilco presente
	na sequência (x0, f(x0), f(f(x0)), ... )
*/

#include <iostream>
#include <cmath>

using namespace std;

/*
	O método "funcao_observada" é a função onde será verificada a existência de um ciclo.
*/
int funcao_observada(int x) {
	
	return (z * x + j) % m; 
}


/*
	O método "floyd" retorna 'mu' e 'lambda' sendo:

		- mu: O índice a partir do qual o ciclo se inicia.
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

