/*
	Exponencia��o Modular

	A exponencia��o modular � um tipo de exponencia��o realizada ao longo de um m�dulo.
	
		a ^ k (mod n)
		
	Exemplo: Usando as regras de Multiplica��o Modular (caso K = 2):
	
		- A ^ K (mod C) = (A ^ 2) (mod C) = (A * A) (mod C) = (A (mod C) * A (mod C)) (mod C)
*/

#include <bits/stdc++.h>

using namespace std;

/*
	O m�todo "exponenciacao_modular" retorna a solu��o da equa��o a ^ k (mod n).
*/
long long exponenciacao_modular(long long a, long long k, long long n) {
	
	long long ret = 1;
	
	for(long long pow = a; k > 0; k >>= 1, pow = (pow * pow) % n)
		if(k & 1)
			ret = (ret * pow) % n;
			
	return ret;
}

