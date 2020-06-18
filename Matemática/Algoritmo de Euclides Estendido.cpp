/*
	Algoritmo de Euclides Estendido
	
	O algoritmo de Euclides estendido é uma extensão do algoritmo de Euclides, que, além de calcular o maior divisor comum (MDC) entre 
	dois inteiros (a, b), também fornece os coeficientes inteiros (x, y) tais que:
	
		ax + by = mdc(a, b) 
	
	Obs: O algoritmo de Euclides estendido, ao invés de retornar um único valor, ele fornecerá uma combinação linear (muito útil) quando
	os inteiros forem primos entre sí.
*/

#include <bits/stdc++.h>

using namespace std;

/*
	A struct "Triple" é utilizada para armazenar os valores do mdc(a, b) e os coeficiente x e y.
*/
struct Triple {
	
	int mdc_ab, x, y;
	
	Triple(int a, int b, int c) : mdc_ab(a), x(b), y(c) {}
};

/*
	O método "euclides_mdc" recebe dois inteiros não negativos (a, b) e devolve uma "Triple" cuja primeira posição é o mdc(a, b), a segunda
	posição é o valor de (x) e a terceira posição o valor de (y), tais que "ax + by = mdc(a, b) ". 
*/
Triple euclides_mdc(int a, int b) {
	
	if(!b) return Triple(a, 1, 0);
	
	Triple q = euclides_mdc(b, a % b);
	
	return Triple(q.mdc_ab, q.y, (q.x - a / b * q.y));
}

