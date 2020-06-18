/*
	Equações Lineares Diofantinas
	
	Na matemática, uma equação Diofantina é uma equação polinomial que permite a duas ou mais variáveis assumirem apenas valores inteiros.
	
	Obs: Uma equação Linear Diofantina é uma equação entre duas somas de monômios de grau zero ou um.
	
	Equações Lineares Diofantinas assumem a forma: 
		
		ax + by = c
		
	Obs: A equação Diofantina "ax + by = c", (com a, b e c pertencendo aos números inteiros), adimite solução se, e somente se, o mdc(a, b) dividir c.
	
	Interpretação geométrica: Uma Equação linear Diofantina com duas incógnitas representa no plano uma reta, onde buscar soluções de uma equação
	da forma "ax + by = c" é equivalente a buscar pontos que pertencem a reta com essa equação.
	
	Exemplo: Quantas figurinhas de R$ 4,00 e quantas figurinhas de R$ 5,00 podem ser compradas com R$ 100,00.
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

/*
	O método "equacoes_diofantinas" determina todos os valores inteiros que x e y podem assumir para satisfazer a equação linear diofantica 
	"ax + by = c".
	
	se "mdc_ab == 0" então a equação não possuí solução.
	
	Se "mdc_ab != 0" então a equação não possuí infinitas na forma.
	
		x = tripla.x + (k * b / tripla.mdc_ab)
		
		y = tripla.y - (k * a / tripla.mdc_ab)
		
	para todo inteiro "k".
*/
Triple equacoes_diofantinas(int a, int b, int c) {
	
	Triple t = euclides_mdc(a, b);
	
	if(c % t.mdc_ab) return Triple(0, 0, 0);
	
	t.x *= (c / t.mdc_ab);
	t.y *= (c / t.mdc_ab);
	
	return t;
}

