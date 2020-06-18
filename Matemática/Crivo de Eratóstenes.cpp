/*
	Crivo de Eratóstenes
	
	O Crivo de Eratóstenes é um algoritmo simples e prático criado para encontrar números primos até um valor limite (valor_analisado).
	
	Funcionamento e exemplo de números de 1 à 30:
	
		- Inicialmente, determina-se o maior número a ser checado. Ele corresponde a raiz quadrada do valor limite,
		arredondando para baixo.
		
			maior_numero_a_checar = sqrt(30) = 5
			
		- Crie uma lista com todos os números de 2 até o valor limite.
		
			lista = [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30]
			
		- Remova todos os multiplos de 2, com exceção do 2.
		
			lista = [2, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29]
			
		- Remova todos os multiplos de 3, com exceção do 3.
		
			lista = [2, 3, 5, 7, 11, 13, 17, 19, 23, 25, 29]
			
		- Remova todos os multiplos de 5 (valor encontrado no primeiro passo), com exceção do 5.
		
			lista = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
			
	Lista de primos de 1 à 30 é [2, 3, 5, 7, 11, 13, 17, 19, 23, 29].
*/

#include <bits/stdc++.h>

using namespace std;

// Tamanho maximo dos números que serão analisado (10^7)
bitset<10000010> bs;

// Vetor onde serão armazenados os números primos.
vector<int> numeros_primos;

// Tamanho o valor analisado pelo Crivo de Eratostenes.
long long tamanho_crivo;

/*
	O método "crivo_eratostenes" preenchera a variável "numeros_primos" no intervalo de "valor_analisado" de forma 
	eficiente.
*/
void crivo_eratostenes(long long valor_analisado) {
	
	tamanho_crivo = valor_analisado + 1;
	
	bs.set();
	bs[0] = bs[1] = 1;
	
	for(long long i = 2; i < tamanho_crivo; ++i) {

		if(bs[i]) {

			for(long long j = (i * i); j < tamanho_crivo; j += i)
				bs[j] = 0;

			numeros_primos.push_back((int)i);			
		}
	}
}

/*
	O método "is_prime" retorna "true" caso o "valor_analisado" (baseado no algoritmo do "crivo_eratostenes) seja um 
	número primo.

	Obs: O algoritmo "crivo_eratostenes" dever ser executado antes do algoritmo "is_prime".
*/
bool is_prime(long long valor_analisado) {

	if(valor_analisado <= tamanho_crivo)
		return bs[valor_analisado];

	for(int i = 0; i < (int)numeros_primos.size(); ++i) {

		if(valor_analisado % numeros_primos[i] == 0) {

			return false;
		}
	}
			
	return true;
}

