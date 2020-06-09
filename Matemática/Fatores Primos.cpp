/*
	Fatores Primos
	
	Os Fatore primos de um n�mero inteiro positivo s�o os n�meros 'primos' que dividem esse inteiro de forma exata.
	
	Exemplo: fatoracao(18) = [2, 3, 3], porque '2 * 3 * 3 = 18'.
*/

#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

/*
	Tamanho maximo dos n�meros que ser�o analisado (10^7).
*/
bitset<10000010> bs;

/*
	Vetor onde ser�o armazenados os n�meros primos.
*/
vector<int> numeros_primos;

/*
	Tamanho o valor analisado pelo Crivo de Eratostenes.
*/
long long tamanho_crivo;

/*
	Determinar o n�mero de primos em um dado intervalo de forma eficiente.
*/
void crivo_eratostenes(long long valor_analisado) {
	
	tamanho_crivo = valor_analisado + 1;
	
	bs.set();
	bs[0] = bs[1] = 1;
	
	for(long long i = 2; i < tamanho_crivo; ++i) {

		if(bs[i]) {
			// Descartar os valores multiplos de i come�ando por (i * i)
			for(long long j = (i * i); j < tamanho_crivo; j += i)
				bs[j] = 0;
			// Adiciona o valor primo verificado a lista.
			numeros_primos.push_back((int)i);			
		}
	}
}

/*
	Determina a fatora��o em n�meros primos de um determinado "valor_analisado".
	
	Observa��o: O algoritmo "crivo_eratostenes" dever ser executado antes do algoritmo "fatoracao".
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

