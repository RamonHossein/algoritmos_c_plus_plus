/*
	Fibonacci
	
	O algoritmo de Fibonacci representa uma sequência de números inteiros, iniciados por 0 e 1, no qual, cada termo subsequente
	corresponde à soma dos dois termos anteriores a ele.
	
	O algoritmo mostrado abaixo calcula a sequência de Fibonacci utilizando recursão.
*/

#include <iostream>

using namespace std;

/*
	O método "fibonacci" retorna o número fibonacci da posição definida por "number".
*/
int fibonacci(int number) {
	
	if(number == 0 || number == 1)
		return number;
		
	return fibonacci(number - 1) + fibonacci(number - 2);
}

