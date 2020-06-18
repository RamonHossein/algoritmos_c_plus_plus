/*
	Fibonacci
	
	O algoritmo de Fibonacci representa uma sequência de números inteiros, iniciados pelos valor 0 e 1, no qual, cada termo
	subsequente corresponde à soma dos dois termos anteriores a ele.
	
	Obs: O algoritmo mostrado abaixo calcula a sequência de Fibonacci utilizando multiplicação e potência de matriz.
*/


#include <bits/stdc++.h>

using namespace std;

/*
	A struct "matrix" é utilizada como modelo na criação de matrizes (2x2).
*/
struct matrix {
	
	int mat[2][2];
};

/*
	O método "matrix_multiplicacao" retorna o cálculo do produto entre as "a" e "b".
*/
matrix matrix_multiplicacao(matrix a, matrix b) {
	
	matrix ans;
	
	for(int i = 0; i < 2; i++) {
		
		for(int j = 0; j < 2; j++) {
			
			ans.mat[i][j] = 0;
			
			for(int k = 0; k < 2; k++) {
				
				ans.mat[i][j] += a.mat[i][k] * b.mat[k][j]; 
			}
		}
	}
	
	return ans;
}

/*
	O método "matrix_potencia" retorna o cálculo da potência da matriz "base" sob o expoênte "p".
*/
matrix matrix_potencia(matrix base, int p) {
	
	matrix ans;
	
	for(int i = 0; i < 2; i++) {
		
		for(int j = 0; j < 2; j++) {

			ans.mat[i][j] = (i == j);
		}
	}

	while(p) {

		if(p & 1) 
			ans = matrix_multiplicacao(ans, base);

		base = matrix_multiplicacao(base, base);

		p >>= 1;
	}
	
	return ans;
}

/*
	O método "fibonacci" retorna o número na sequência de Fibonacci definido na posição (number). 
		
	Obs: O método "fibonacci" calcula a matriz "fib" onde cada uma das suas posições corresponde aos seguintes valores:
	
		[fib(number + 1)] [fib(number)	  ]
		[fib(number)	] [fib(number + 1)]
*/
int fibonacci(int number) {
	
	matrix base;
	
	base.mat[0][0] = 1;
	base.mat[0][1] = 1;
	base.mat[1][0] = 1;
	base.mat[1][1] = 0;
	
	matrix fib = matrix_potencia(base, number);
			
	return fib.mat[0][1];
}

