/*
	Lista de Fun��es Envolvendo Fatores Primos
	
		1. Quantidade_fatores_primos: Retorna o n�mero de fatores primos de um valor previamente escolhido.
	
		2. Quantidade_fatores_primos_diferentes: Retorna o n�mero de fatores primos de um valor previamente escolhido,
		que n�o se repetem.
	
		3. soma_fatores_primos: Retorna a soma dos fatores primos de um valor previamente escolhido.
	
		4. quantidade_divisores_valor: Retorna o n�mero de divisores de um valor previamente escolhido.
	
		5. soma_divisores_valor: Retorna a soma dos divisores de um valor previamente escolhido.
	
		6. euler_phi: Retorna o n�mero de inteiros positivos menores ou iguais a um valor previamente escolhido que s�o
		co-primos deste mesmo valor.
*/

#include <bits/stdc++.h>

using namespace std;

// Tamanho maximo dos n�meros que ser�o analisado (10^7)
bitset<10000010> bs;

// Vetor onde ser�o armazenados os n�meros primos.
vector<int> numeros_primos;

// Tamanho o valor analisado pelo Crivo de Eratostenes.
long long tamanho_crivo;

/*
	O m�todo "crivo_eratostenes" preenchera a vari�vel "numeros_primos" no intervalo de "valor_analisado" de forma 
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
	O m�todo "quantidade_fatores_primos" retorna o n�mero de fatores primos do "valor_analisado".

	Obs: O algoritmo "crivo_eratostenes" dever ser executado antes do algoritmo "quantidade_fatores_primos".
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
	O m�todo "quantidade_fatores_primos_diferentes" retorna o n�mero de fatores primos que n�o se repetem do "valor_analisado".

	Obs: O algoritmo "crivo_eratostenes" dever ser executado antes do algoritmo "quantidade_fatores_primos_diferentes".
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
	O m�todo "soma_fatores_primos" retorna a soma dos fatores primos do "valor_analisado".

	Obs: O algoritmo "crivo_eratostenes" dever ser executado antes do algoritmo "soma_fatores_primos".
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
	O m�todo "quantidade_divisores_valor" retorna o n�mero de divisores do "valor_analisado".

	Obs: O algoritmo "crivo_eratostenes" dever ser executado antes do algoritmo "quantidade_divisores_valor".
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
	O m�todo "soma_divisores_valor" retorna a soma dos divisores do "valor_analisado".

	Obs: O algoritmo "crivo_eratostenes" dever ser executado antes do algoritmo "soma_divisores_valor".
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
	O m�todo "euler_phi" retorna o n�mero de inteiros positivos menores ou iguais ao "valor_analisado" que s�o co-primos 
	deste mesmo valor.

	Obs: O algoritmo "crivo_eratostenes" dever ser executado antes do algoritmo "euler_phi".
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

