/*
	Números de Catalan
	
	Em combinatória os números de Catalan formam uma sequência de números naturais que ocorrem em vários problemas de
	contagem, frequentemente envolvendo objetos definidos recursivamente.
	
	Obs: O algoritmo mostrado abaixo cálcula a sequência de Catalan utilizando recursão.
	
	A sequência dos 10 primeiros números de Catalan: 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796.

	Exemplo: Qual o número de maneiras de se dividir um polígono de (n + 2) lados em 'n' triângulos.
	
	Exemplo: Qual o número de árvores binárias que temos com (n + 1) folhas.
*/

#include <bits/stdc++.h>

using namespace std;

/*
	O método "catalan" retorna o número na sequência de Catalan definido na posição (number). 
*/
int catalan(int number) {
	
	if(number <= 0)
		return 1;
		
	return (2 * (2 * number - 1) * catalan(number - 1)) / (number + 1);
}

