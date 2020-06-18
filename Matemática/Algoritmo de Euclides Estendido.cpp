/*
	Algoritmo de Euclides Estendido
	
	O algoritmo de Euclides estendido � uma extens�o do algoritmo de Euclides, que, al�m de calcular o maior divisor comum (MDC) entre 
	dois inteiros (a, b), tamb�m fornece os coeficientes inteiros (x, y) tais que:
	
		ax + by = mdc(a, b) 
	
	Obs: O algoritmo de Euclides estendido, ao inv�s de retornar um �nico valor, ele fornecer� uma combina��o linear (muito �til) quando
	os inteiros forem primos entre s�.
*/

#include <bits/stdc++.h>

using namespace std;

/*
	A struct "Triple" � utilizada para armazenar os valores do mdc(a, b) e os coeficiente x e y.
*/
struct Triple {
	
	int mdc_ab, x, y;
	
	Triple(int a, int b, int c) : mdc_ab(a), x(b), y(c) {}
};

/*
	O m�todo "euclides_mdc" recebe dois inteiros n�o negativos (a, b) e devolve uma "Triple" cuja primeira posi��o � o mdc(a, b), a segunda
	posi��o � o valor de (x) e a terceira posi��o o valor de (y), tais que "ax + by = mdc(a, b) ". 
*/
Triple euclides_mdc(int a, int b) {
	
	if(!b) return Triple(a, 1, 0);
	
	Triple q = euclides_mdc(b, a % b);
	
	return Triple(q.mdc_ab, q.y, (q.x - a / b * q.y));
}

