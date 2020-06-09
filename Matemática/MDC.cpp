/*
	MDC - Maior Divisor Comum
	
	Determinar o maior divisor comum entre dois n�meros inteiros positivos "a" e "b".
	
	Se "mdc(a, b) == 1", ent�o "a" e "b" s�o co-primos.
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

