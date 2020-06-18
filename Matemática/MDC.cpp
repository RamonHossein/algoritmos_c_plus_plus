/*
	MMC - Maior Divisor Comum

	Determinar o maior divisor comum entre dois n�meros inteiros positivos.
	
	Obs: Se o m�todo "mdc" retornar o valor '1', ent�o os n�meros (a, b) s�o co-primos.
*/

#include <bits/stdc++.h>

using namespace std;

/*
	O m�todo "mdc" retorna o maior divisor comum entre os n�meros inteiros (a, b). 
*/
inline int mdc(int a, int b) {
	
	return b ? mdc(b, a % b) : abs(a);
}

