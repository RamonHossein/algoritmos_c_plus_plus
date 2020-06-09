/*
	Inverso Modular
	
	Um Inverso Multiplicativo Modular de um número "a" é um número inteiro "x" de modo que  "a + x = 1 (mod n)". 
	
		a * x = 1 (mod n)
		
	Em aritmética modular não temos uma operação de divisão. No entanto temos inversos modulares.
	
		- O inverso modular de A (mod C) é A^-1.
		
		- (A * A^-1) = 1 (mod C) ou de modo equivalente (A * A^-1) (mod C) = 1.
		 
		- Apenas números primos de C têm um inverso modular (mod C).
		
	Em "a + x = 1 (mod n)", se "n" é primo, então "x = (a^(n - 2)) % n".
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

/*
	O algoritmo "inverso_modular" determina a solução da equação 'a * x = 1 (mod n).
	
	se "x == 0" então a equação não possuí solução.
*/
int inverso_modular(int a, int n) {
	
	Triple t = euclides_mdc(a, n);
	
	if(t.mdc_ab > 1) return 0;
	
	int r = t.x % n;
	
	int x = (r < 0) ?  (r + n) : r; 
	
	return x;
}

