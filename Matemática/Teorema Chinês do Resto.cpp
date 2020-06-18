/*
	Teorema Chinês do Resto
	
	Dado dois inteiros "p1", "p2" (maior ou igual a 2) primos entre sí, e dados outros dois inteiros quaisquer "a1", "a2", o sistema
	
		x = a1 (mod p1)
		x = a2 (mod p2)
		
	possui uma solução "x = x0". Além disso, um inteiro "x" será a solução do sistema se, e somente se, "x = x0 (mod m1 m2)".
	
	Exemplo: Qual o menor número natural que dividido por 7 deixa resto 3 e quando dividido por 6 deixa resto 5.
*/

#include <bits/stdc++.h>

// Tamanho maxímo das equações que poderão entrar na solução geral.
#define maxn 1001

using namespace std;

// Número de casos.
int n;

// Vetores onde deverão ser armazenado os valores "a" e "p" na equação "a (mod p)".
int a[maxn];
int p[maxn];

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

/*
	O método "inverso_modular" retorna a solução da equação "a * x = 1 (mod n)".
	
	Obs: se "x == 0" então a equação não possuí solução.
*/
int inverso_modular(int a, int n) {
	
	Triple t = euclides_mdc(a, n);
	
	if(t.mdc_ab > 1) return 0;
	
	int r = t.x % n;
	
	int x = (r < 0) ?  (r + n) : r; 
	
	return x;
}

/*
	O método "teorema_chines_resto" retorna a solução da equação x = a[i] (mod p[i]).
*/
int teorema_chines_resto() {

	int m = 1;
	int x = 0;
	
	for(int i = 0; i < n; ++i)
		m *= p[i];
		
	for(int i = 0; i < n; ++i)
		x += a[i] * inverso_modular(m / p[i], p[i]) * (m / p[i]);
		
	int r = ((x % m) + m) % m;
	
	return r;
}

