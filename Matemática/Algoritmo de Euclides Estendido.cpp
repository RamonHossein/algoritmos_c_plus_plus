/*
	Algoritmo de Euclides Estendido
	
	O Algoritmo de Euclides Estendido é uma extensão do Algoritmo de Euclides, que, além de calcular o máximo divisor comum (MDC) entre
	"a", "b" (pertencendo aos números inteiros), fornece os coeficientes "x", "y" (pertencendo aos números inteiros) tais que:
	
		ax + by = MDC(a, b)
		
	O Algoritmo de Euclides Estendido, ao invés de retornar um valor único, fornece uma combinação linear, muito útil, quando os inteiros 
	são primos entre sí (coprimos).
*/

#include <iostream>

using namespace std;

/*
	Triple é uma estrutura criada para armazenar os valores do mdc(a, b) e os coeficiente x e y.
*/
struct Triple {
	
	int mdc_ab, x, y;
	
	Triple(int a, int b, int c) : mdc_ab(a), x(b), y(c) {}
};

/*
	O algoritmo "euclides_mdc" recebe dois inteiros não negativos a e b e devolve uma "Triple" cuja primeira posição é o mdc(a,b), a segunda posição 
	é o valor x e a terceira o valor y tais que a*x + b*y = mdc(a,b).
*/
Triple euclides_mdc(int a, int b) {
	
	if(!b) return Triple(a, 1, 0);
	
	Triple q = euclides_mdc(b, a % b);
	
	return Triple(q.mdc_ab, q.y, (q.x - a / b * q.y));
}

