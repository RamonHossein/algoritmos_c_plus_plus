/*
	Exponenciação Modular

	Exponenciação Modular é um tipo de exponenciação realizada ao longo de um módulo.
	
		a ^ k (mod n)
		
	Usando as regras de Multiplicação Modular (caso K = 2):
	
		- A ^ K (mod C) = (A ^ 2) (mod C) = (A * A) (mod C) = (A (mod C) * A (mod C)) (mod C)
*/

#include <iostream>

using namespace std;

/*
	O algoritmo "exponenciacao_modular" determina a solução da equação a ^ k (mod n).
*/
long long exponenciacao_modular(long long a, long long k, long long n) {
	
	long long ret = 1;
	
	for(long long pow = a; k > 0; k >>= 1, pow = (pow * pow) % n)
		if(k & 1)
			ret = (ret * pow) % n;
			
	return ret;
}

