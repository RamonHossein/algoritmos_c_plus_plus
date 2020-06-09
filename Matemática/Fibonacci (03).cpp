/*
	Fibonacci
	
	O algoritmo de Fibonacci representa uma sequ�ncia de n�meros inteiros, iniciados por 0 e 1, no qual, cada termo subsequente
	corresponde � soma dos dois termos anteriores a ele.
	
	O algoritmo mostrado abaixo calcula a sequ�ncia de Fibonacci utilizando a f�rmula de Binet.
*/

#include <iostream>
#include <cmath>

using namespace std;

/*
	O m�todo "fibonacci" retorna o n�mero fibonacci da posi��o definida por "number".
*/
double fibonacci(int number) {

	double valor_1 = (1 + sqrt(5)) / 2.0;
	
	double valor_2 = (1 - sqrt(5)) / 2.0;
	
	double fib = (pow(valor_1, number) - pow(valor_2, number)) / sqrt(5);
	
	return fib;
}

