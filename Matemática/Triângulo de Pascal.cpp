/*
	Tri�ngulo de Pascal

	� um tri�ngulo aritm�tico infinito onde s�o dispostos os coeficientes das expans�es binomiais (n, k).

	Obs: Rela��o de Stifel: Cada n�mero do tri�ngulo de Pascal � igual a soma do n�mero imediatamente acima e do seu 
	antecessor.
	
	Obs: A soma de uma linha 'n' no tri�ngulo de Pascal � igual a (2^n).
	
	Obs: A soma de uma coluna no tri�ngulo de Pascal pode ser calculada pela rela��o (n + k + 1) / (n + 1).
	
	Obs: A soma de uma diagonal no tri�ngulo de Pascal pode ser calculada pela rela��o (n + k + 1) / (k).
	
	Obs: Em toda a coluna central do tri�ngulo de Pascal o produto de dois de seus elementos � maior que o produto de
	dois elementos quaiquer pertencente a mesma coluna.
	
	
	Exemplo: Tri�ngulo de Pascal (padr�o)

		    1
		   1 1
		  1 2 1
		 1 3 3 1
		1 4 6 4 1
	
	Exemplo: Tri�ngulo de Pascal (matriz)
	
		1 1 1 1 1
		0 1 2 3 4
		0 0 1 3 6
		0 0 0 1 4
		0 0 0 0 1
*/

#include <bits/stdc++.h>

// Tamanho max�mo do tri�ngulo de Pascal.
#define maxn 5

using namespace std;

// A vari�vel "triangulo" armazenar� os valores do tri�ngulo de Pascal.
int triangulo[maxn][maxn];

/*
	O m�todo "triangulo_pascal" preenchera a vari�vel "triangulo" na ordem de (maxn - 1).
	
	O "triangulo[c][k]" � igual ao valor da combina��o C(n, k) onde k > n.
*/
void triangulo_pascal() {
		
	for(unsigned long long n = 0; n < maxn; ++n) {
		
		triangulo[n][0] = triangulo[n][n] = 1;
		
		for(unsigned long long k = 1; k < n; ++k)
			triangulo[n][k] = triangulo[n - 1][k - 1] + triangulo[n - 1][k];
	} 
}

