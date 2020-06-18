/*
	Triângulo de Pascal

	É um triângulo aritmético infinito onde são dispostos os coeficientes das expansões binomiais (n, k).

	Obs: Relação de Stifel: Cada número do triângulo de Pascal é igual a soma do número imediatamente acima e do seu 
	antecessor.
	
	Obs: A soma de uma linha 'n' no triângulo de Pascal é igual a (2^n).
	
	Obs: A soma de uma coluna no triângulo de Pascal pode ser calculada pela relação (n + k + 1) / (n + 1).
	
	Obs: A soma de uma diagonal no triângulo de Pascal pode ser calculada pela relação (n + k + 1) / (k).
	
	Obs: Em toda a coluna central do triângulo de Pascal o produto de dois de seus elementos é maior que o produto de
	dois elementos quaiquer pertencente a mesma coluna.
	
	
	Exemplo: Triângulo de Pascal (padrão)

		    1
		   1 1
		  1 2 1
		 1 3 3 1
		1 4 6 4 1
	
	Exemplo: Triângulo de Pascal (matriz)
	
		1 1 1 1 1
		0 1 2 3 4
		0 0 1 3 6
		0 0 0 1 4
		0 0 0 0 1
*/

#include <bits/stdc++.h>

// Tamanho maxímo do triângulo de Pascal.
#define maxn 5

using namespace std;

// A variável "triangulo" armazenará os valores do triângulo de Pascal.
int triangulo[maxn][maxn];

/*
	O método "triangulo_pascal" preenchera a variável "triangulo" na ordem de (maxn - 1).
	
	O "triangulo[c][k]" é igual ao valor da combinação C(n, k) onde k > n.
*/
void triangulo_pascal() {
		
	for(unsigned long long n = 0; n < maxn; ++n) {
		
		triangulo[n][0] = triangulo[n][n] = 1;
		
		for(unsigned long long k = 1; k < n; ++k)
			triangulo[n][k] = triangulo[n - 1][k - 1] + triangulo[n - 1][k];
	} 
}

