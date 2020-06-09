/*
	Fibonacci
	
	O algoritmo de Fibonacci representa uma sequ�ncia de n�meros inteiros, iniciados por 0 e 1, no qual, cada termo subsequente
	corresponde � soma dos dois termos anteriores a ele.
	
	O algoritmo mostrado abaixo calcula a sequ�ncia de Fibonacci utilizando recurs�o.
*/

#include <iostream>

using namespace std;

/*
	O m�todo "fibonacci" retorna o n�mero fibonacci da posi��o definida por "number".
*/
int fibonacci(int number) {
	
	if(number == 0 || number == 1)
		return number;
		
	return fibonacci(number - 1) + fibonacci(number - 2);
}

