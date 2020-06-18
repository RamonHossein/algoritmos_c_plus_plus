/*
	Fatores Primos
	
	Os fatores primos de um número inteiro positivo são os números "primos" que dividem esse inteiro de forma exata.
	
	Exemplo: fatoracao(18) = [2, 3, 3], porque '2 * 3 * 3 = 18'.
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
	O método "fatoracao" retorna um vetor contendo os números primos resultantes da fatoração do "valor_analisado".
	número primo.

	Obs: O algoritmo "crivo_eratostenes" dever ser executado antes do algoritmo "is_prime".
*/
vector<int> fatoracao(long long valor_analisado) {
	
	vector<int> fatores;
	
	long long fatores_index = 0;

	long long numero_primo = numeros_primos[fatores_index];
	
	while(numero_primo * numero_primo <= valor_analisado) {
		
		while(valor_analisado % numero_primo == 0) {
			
			valor_analisado /= numero_primo;
			fatores.push_back(numero_primo);
		}

		numero_primo = numeros_primos[++fatores_index];
	}
	
	if(valor_analisado != 1)
		fatores.push_back(valor_analisado);

	return fatores;
}

