/*
	MDC - Maior Divisor Comum
	
	Determinar o maior divisor comum entre dois números inteiros positivos "a" e "b".
	
	Se "mdc(a, b) == 1", então "a" e "b" são co-primos.
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

