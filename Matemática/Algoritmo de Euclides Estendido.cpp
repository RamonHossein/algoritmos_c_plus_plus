/*
	Algoritmo de Euclides Estendido
	
	O Algoritmo de Euclides Estendido � uma extens�o do Algoritmo de Euclides, que, al�m de calcular o m�ximo divisor comum (MDC) entre
	"a", "b" (pertencendo aos n�meros inteiros), fornece os coeficientes "x", "y" (pertencendo aos n�meros inteiros) tais que:
	
		ax + by = MDC(a, b)
		
	O Algoritmo de Euclides Estendido, ao inv�s de retornar um valor �nico, fornece uma combina��o linear, muito �til, quando os inteiros 
	s�o primos entre s� (coprimos).
*/

#include <iostream>

using namespace std;

/*
	Triple � uma estrutura criada para armazenar os valores do mdc(a, b) e os coeficiente x e y.
*/
struct Triple {
	
	int mdc_ab, x, y;
	
	Triple(int a, int b, int c) : mdc_ab(a), x(b), y(c) {}
};

/*
	O algoritmo "euclides_mdc" recebe dois inteiros n�o negativos a e b e devolve uma "Triple" cuja primeira posi��o � o mdc(a,b), a segunda posi��o 
	� o valor x e a terceira o valor y tais que a*x + b*y = mdc(a,b).
*/
Triple euclides_mdc(int a, int b) {
	
	if(!b) return Triple(a, 1, 0);
	
	Triple q = euclides_mdc(b, a % b);
	
	return Triple(q.mdc_ab, q.y, (q.x - a / b * q.y));
}

