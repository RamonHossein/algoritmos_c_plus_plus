/*
	Lista de F�rmulas Matem�ticas
	
		1. somatorio_quadrado: Retorna a soma dos "n" primeiros n�meros ao quadrado.
*/

#include <bits/stdc++.h>

using namespace std;

/*
	O m�todo "somatorio_quadrado" retorna a soma ao quadrado dos "n" primeiros inteiros reais.
*/
long long somatorio_quadrado(long long a) {
	
	long long resultado = (a * (a + 1) * (2 * a + 1)) / 6;
		
	return resultado;
}

