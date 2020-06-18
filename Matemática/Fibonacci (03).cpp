/*
	Fibonacci
	
	O algoritmo de Fibonacci representa uma sequ�ncia de n�meros inteiros, iniciados pelos valor 0 e 1, no qual, cada termo
	subsequente corresponde � soma dos dois termos anteriores a ele.
	
	Obs: O algoritmo mostrado abaixo calcula a sequ�ncia de Fibonacci utilizando a f�rmula de Binet.
*/


#include <bits/stdc++.h>

using namespace std;

/*
	O m�todo "fibonacci" retorna o n�mero na sequ�ncia de Fibonacci definido na posi��o (number). 
*/
double fibonacci(int number) {

	double valor_1 = (1 + sqrt(5)) / 2.0;
	
	double valor_2 = (1 - sqrt(5)) / 2.0;
	
	double fib = (pow(valor_1, number) - pow(valor_2, number)) / sqrt(5);
	
	return fib;
}

