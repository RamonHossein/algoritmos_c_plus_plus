/*
	MMC - Menor Multiplo Comum
	
	Determinar o menor multiplo comum entre dois números inteiros positivos "a" e "b".
*/

#include <iostream>
#include <cstdlib>

using namespace std;

/*
	Retorna o maior divisor comum dos inteiros "a" e 'b".
*/
inline int mdc(int a, int b) {
	
	return b ? mdc(b, a % b) : abs(a);
}

/*
	Retorna o menor multiplo comum dos inteiros "a" e 'b".
*/
inline long long mmc(int a, int b) {
	
	if(a && b)
		return abs(a) / mdc(a, b) * (long long)abs(b);
	else
		return (long long) abs(a | b);
}

