/*
	MMC - Menor Multiplo Comum

	Determinar o menor multiplo comum entre dois n�meros inteiros positivos.
*/

#include <bits/stdc++.h>

using namespace std;

/*
	O m�todo "mdc" retorna o maior divisor comum entre os n�meros inteiros (a, b). 
*/
inline int mdc(int a, int b) {
	
	return b ? mdc(b, a % b) : abs(a);
}

/*
	O m�todo "mmc" retorna o menor multiplo comum entre os n�meros inteiros (a, b).
*/
inline long long mmc(int a, int b) {
	
	if(a && b)
		return abs(a) / mdc(a, b) * (long long)abs(b);
	else
		return (long long) abs(a | b);
}

