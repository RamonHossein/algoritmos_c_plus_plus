/*
	Equa��es Lineares Diofantinas
	
	Na matem�tica, uma equa��o Diofantina � uma equa��o polinomial que permite a duas ou mais vari�veis assumirem apenas valores inteiros.
	
	Obs: Uma equa��o Linear Diofantina � uma equa��o entre duas somas de mon�mios de grau zero ou um.
	
	Equa��es Lineares Diofantinas assumem a forma: 
		
		ax + by = c
		
	Obs: A equa��o Diofantina "ax + by = c", (com a, b e c pertencendo aos n�meros inteiros), adimite solu��o se, e somente se, o mdc(a, b) dividir c.
	
	Interpreta��o geom�trica: Uma Equa��o linear Diofantina com duas inc�gnitas representa no plano uma reta, onde buscar solu��es de uma equa��o
	da forma "ax + by = c" � equivalente a buscar pontos que pertencem a reta com essa equa��o.
	
	Exemplo: Quantas figurinhas de R$ 4,00 e quantas figurinhas de R$ 5,00 podem ser compradas com R$ 100,00.
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
	O m�todo "equacoes_diofantinas" determina todos os valores inteiros que x e y podem assumir para satisfazer a equa��o linear diofantica 
	"ax + by = c".
	
	se "mdc_ab == 0" ent�o a equa��o n�o possu� solu��o.
	
	Se "mdc_ab != 0" ent�o a equa��o n�o possu� infinitas na forma.
	
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

