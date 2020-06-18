/*
	Inverso Mudular
	
	Um Inverso Multiplicativo Modular de um n�mero "a" � um n�mero inteiro "x" de modo que  "a + x = 1 (mod n)". 
	
		a * x = 1 (mod n)
		
	Obs: Em aritm�tica modular n�o temos uma opera��o de divis�o. No entanto temos inversos modulares.
	
		- O inverso modular de A (mod C) � A^-1.
		
		- (A * A^-1) = 1 (mod C) ou de modo equivalente (A * A^-1) (mod C) = 1.
		 
		- Apenas n�meros primos de C t�m um inverso modular (mod C).
		
	Em "a + x = 1 (mod n)", se "n" � primo, ent�o "x = (a^(n - 2)) % n".
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

/*
	O m�todo "inverso_modular" retorna a solu��o da equa��o "a * x = 1 (mod n)".
	
	Obs: se "x == 0" ent�o a equa��o n�o possu� solu��o.
*/
int inverso_modular(int a, int n) {
	
	Triple t = euclides_mdc(a, n);
	
	if(t.mdc_ab > 1) return 0;
	
	int r = t.x % n;
	
	int x = (r < 0) ?  (r + n) : r; 
	
	return x;
}

