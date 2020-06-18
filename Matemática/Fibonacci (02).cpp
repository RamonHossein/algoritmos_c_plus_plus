/*
	Fibonacci
	
	O algoritmo de Fibonacci representa uma sequência de números inteiros, iniciados pelos valor 0 e 1, no qual, cada termo
	subsequente corresponde à soma dos dois termos anteriores a ele.
	
	Obs: O algoritmo mostrado abaixo calcula a sequência de Fibonacci utilizando recursão.
*/


#include <bits/stdc++.h>

using namespace std;

/*
	O método "fibonacci" retorna o número na sequência de Fibonacci definido na posição (number). 
*/
int fibonacci(int number) {
	
	if(number == 0 || number == 1)
		return number;
		
	return fibonacci(number - 1) + fibonacci(number - 2);
}

