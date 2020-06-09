/*
	Funções Envolvendo Fatores Primos
	
	- quantidade_fatores_primos: Retorna o número de fatores primos de um valor previamente escolhido.
	
	- quantidade_fatores_primos_diferentes: Retorna o número de fatores primos de um valor previamente escolhido que não 
	se repetem.
	
	- soma_fatores_primos: Retorna a soma dos fatores primos de um valor previamente escolhido.
	
	- quantidade_divisores_valor: Retorna o número de divisores de um valor previamente escolhido.
	
	- soma_divisores_valor: Retorna a soma dos divisores de um valor previamente escolhido.
	
	- euler_phi: Retorna o número de inteiros positivos menores ou iguais a um valor previamente escolhido que são
	co-primos deste mesmo valor.
*/

#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>

using namespace std;

/*
	Tamanho maximo dos números que serão analisado (10^7).
*/
bitset<10000010> bs;

/*
	Vetor onde serão armazenados os números primos.
*/
vector<int> numeros_primos;

/*
	Tamanho o valor analisado pelo Crivo de Eratostenes.
*/
long long tamanho_crivo;

/*
	Determinar o número de primos em um dado intervalo de forma eficiente.
*/
void crivo_eratostenes(long long valor_analisado) {
	
	tamanho_crivo = valor_analisado + 1;
	
	bs.set();
	bs[0] = bs[1] = 1;
	
	for(long long i = 2; i < tamanho_crivo; ++i) {

		if(bs[i]) {
			// Descartar os valores multiplos de i começando por (i * i)
			for(long long j = (i * i); j < tamanho_crivo; j += i)
				bs[j] = 0;
			// Adiciona o valor primo verificado a lista.
			numeros_primos.push_back((int)i);			
		}
	}
}

/*
	Retorna o número de fatores primos do "valor_analisado".
	
	Observação: O algoritmo "crivo_eratostenes" dever ser executado antes do algoritmo "quantidade_fatores_primos".
*/
long long quantidade_fatores_primos(long long valor_analisado) {
	
	long long indice_fator = 0;
	long long int fator = numeros_primos[indice_fator];
	long long resposta = 0;
	
	while(fator * fator <= valor_analisado) {
		
		while(valor_analisado % fator == 0) {
			
			valor_analisado /= fator;
			resposta++;
		}
		
		fator = numeros_primos[++indice_fator];
	}
	
	if(valor_analisado != 1)
		resposta++;
		
	return resposta;
}

/*
	Retorna o número de fatores primos do "valor_analisado" que não se repetem.
	
	Observação: O algoritmo "crivo_eratostenes" dever ser executado antes do algoritmo "quantidade_fatores_primos_diferentes".
*/
long long quantidade_fatores_primos_diferentes(long long valor_analisado) {
	
	long long indice_fator = 0;
	long long int fator = numeros_primos[indice_fator];
	long long resposta = 0;
	bool verificado;
	
	while(fator * fator <= valor_analisado) {
		
		verificado = true;
		
		while(valor_analisado % fator == 0) {
			
			valor_analisado /= fator;
			
			if(verificado) {
				
				resposta++;
				verificado = false;
			}
		}
		
		fator = numeros_primos[++indice_fator];
	}
	
	if(valor_analisado != 1)
		resposta++;
		
	return resposta;
}

/*
	Retorna a soma dos fatores primos do "valor_analisado".
	
	Observação: O algoritmo "crivo_eratostenes" dever ser executado antes do algoritmo "soma_fatores_primos".
*/
long long soma_fatores_primos(long long valor_analisado) {
	
	long long indice_fator = 0;
	long long int fator = numeros_primos[indice_fator];
	long long soma = 0;
	
	while(fator * fator <= valor_analisado) {
		
		while(valor_analisado % fator == 0) {
			
			valor_analisado /= fator;
			soma += fator;
		}
		
		fator = numeros_primos[++indice_fator];
	}
	
	if(valor_analisado != 1)
		soma += valor_analisado;
		
	return soma;
}

/*
	Retorna o número de divisores do "valor_analisado".
	
	Observação: O algoritmo "crivo_eratostenes" dever ser executado antes do algoritmo "quantidade_divisores_valor".
*/
long long quantidade_divisores_valor(long long valor_analisado) {
	
	long long indice_fator = 0;
	long long int fator = numeros_primos[indice_fator];
	long long resposta = 1;
	
	while(fator * fator <= valor_analisado) {
		
		long long expoente = 0;
		
		while(valor_analisado % fator == 0) {
			
			valor_analisado /= fator;
			expoente++;
		}
		
		resposta *= (expoente + 1);
		
		fator = numeros_primos[++indice_fator];
	}
	
	if(valor_analisado != 1)
		resposta *= 2;
		
	return resposta;
}

/*
	Retorna a soma dos divisores do "valor_analisado".
	
	Observação: O algoritmo "crivo_eratostenes" dever ser executado antes do algoritmo "soma_divisores_valor".
*/
long long soma_divisores_valor(long long valor_analisado) {
	
	long long indice_fator = 0;
	long long int fator = numeros_primos[indice_fator];
	long long resposta = 1;
	
	while(fator * fator <= valor_analisado) {
		
		long long expoente = 0;
		
		while(valor_analisado % fator == 0) {
			
			valor_analisado /= fator;
			expoente++;
		}
		
		resposta *= ((long long)pow((double)fator, expoente + 1.0) - 1) / (fator - 1);
		
		fator = numeros_primos[++indice_fator];
	}
	
	if(valor_analisado != 1)
		resposta *= ((long long)pow((double)valor_analisado, 2.0) - 1) / (fator - 1);
		
	return resposta;
}

/*
	Retorna o número de inteiros positivos menores ou iguais ao "valor_analisado" que são co-primos deste mesmo valor.
	
	Observação: O algoritmo "crivo_eratostenes" dever ser executado antes do algoritmo "euler_phi".
*/
long long euler_phi(long long valor_analisado) {
	
	long long indice_fator = 0;
	long long int fator = numeros_primos[indice_fator];
	long long resposta = valor_analisado;
	
	while(fator * fator <= valor_analisado) {
		
		if(valor_analisado % fator == 0)
			resposta -= (resposta / fator);
		
		while(valor_analisado % fator == 0) {
			
			valor_analisado /= fator;
		}
		
		fator = numeros_primos[++indice_fator];
	}
	
	if(valor_analisado != 1)
		resposta -= (resposta / valor_analisado);
		
	return resposta;
}

