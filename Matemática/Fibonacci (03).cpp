/*
	Fibonacci
	
	O algoritmo de Fibonacci representa uma sequência de números inteiros, iniciados pelos valor 0 e 1, no qual, cada termo
	subsequente corresponde à soma dos dois termos anteriores a ele.
	
	Obs: O algoritmo mostrado abaixo calcula a sequência de Fibonacci utilizando a fórmula de Binet.
*/


#include <bits/stdc++.h>

using namespace std;

/*
	O método "fibonacci" retorna o número na sequência de Fibonacci definido na posição (number). 
*/
double fibonacci(int number) {

	double valor_1 = (1 + sqrt(5)) / 2.0;
	
	double valor_2 = (1 - sqrt(5)) / 2.0;
	
	double fib = (pow(valor_1, number) - pow(valor_2, number)) / sqrt(5);
	
	return fib;
}

