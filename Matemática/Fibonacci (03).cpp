/*
	Fibonacci
	
	O algoritmo de Fibonacci representa uma sequência de números inteiros, iniciados por 0 e 1, no qual, cada termo subsequente
	corresponde à soma dos dois termos anteriores a ele.
	
	O algoritmo mostrado abaixo calcula a sequência de Fibonacci utilizando a fórmula de Binet.
*/

#include <iostream>
#include <cmath>

using namespace std;

/*
	O método "fibonacci" retorna o número fibonacci da posição definida por "number".
*/
double fibonacci(int number) {

	double valor_1 = (1 + sqrt(5)) / 2.0;
	
	double valor_2 = (1 - sqrt(5)) / 2.0;
	
	double fib = (pow(valor_1, number) - pow(valor_2, number)) / sqrt(5);
	
	return fib;
}

