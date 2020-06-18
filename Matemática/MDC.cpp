/*
	MMC - Maior Divisor Comum

	Determinar o maior divisor comum entre dois números inteiros positivos.
	
	Obs: Se o método "mdc" retornar o valor '1', então os números (a, b) são co-primos.
*/

#include <bits/stdc++.h>

using namespace std;

/*
	O método "mdc" retorna o maior divisor comum entre os números inteiros (a, b). 
*/
inline int mdc(int a, int b) {
	
	return b ? mdc(b, a % b) : abs(a);
}

