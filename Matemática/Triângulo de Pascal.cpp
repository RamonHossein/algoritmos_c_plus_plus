/*
	Triangulo de Pascal
	
	É um triangulo aritmético infinito onde são dispostos os coeficientes das expansões binomiais (n, k).
	
	Relação de Stifel: Cada número do Triangulo de Pascal é igual à soma do número imediatamente acima e do antecessor
	do número acima.
	
	A soma de uma linha no Triangulo de Pascal é igual a (2^n).
	
	A soma de uma coluna no Triangulo de Pascal pode ser calculada pela relação (n + k + 1) / (n + 1).
	
	A soma de uma diagonal no Triangulo de Pascal pode ser calculada pela relação (n + k + 1) / (k).
	
	Em toda a coluna central do Triangulo de Pascal o produto de dois dos seus elementos é maior que o produto de dois 
	elementos quaisquer pertencente a mesma coluna.
	
	Exemplo de Triangulo de Pascal (padrão)

	    1
	   1 1
	  1 2 1
	 1 3 3 1
	1 4 6 4 1
	
	Exemplo de Triangulo de Pascal (matriz)
	
	1 1 1 1 1
	0 1 2 3 4
	0 0 1 3 6
	0 0 0 1 4
	0 0 0 0 1
*/

#include <iostream>

/*
	Tamanho maxímo do Triangulo de Pascal.
*/
#define maxn 5

using namespace std;

/*
	Matriz onde deverão ser armazenado os valores do Triangulo de Pascal.
*/
int triangulo[maxn][maxn];

/*
	Calculo do triãngulo de Pascal de ordem (maxn - 1).
	triangulo[c][k] = valor da combinação C(n, k), ode k > n.
*/
void triangulo_pascal() {
		
	for(unsigned long long n = 0; n < maxn; ++n) {
		
		triangulo[n][0] = triangulo[n][n] = 1;
		
		for(unsigned long long k = 1; k < n; ++k)
			triangulo[n][k] = triangulo[n - 1][k - 1] + triangulo[n - 1][k];
	} 
}

