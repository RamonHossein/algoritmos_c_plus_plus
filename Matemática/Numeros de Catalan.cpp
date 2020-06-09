/*
	N�meros de Catalan
	
	Em combinat�ria os n�meros de Catalan formam uma sequ�ncia de n�meros naturais que ocorrem em v�rios problemas de 
	contagem, frequentemente envolvendo objetos definidos recursivamente.
	
	O algoritmo mostrado abaixo calcula a sequ�ncia de Catalan utilizando recurs�o.
	
	Sequ�ncia dos 10 primeiros n�meros de Catalan: 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796
	
	Exemplo: Qual o n�mero de maneiras de se dividir um pol�gono de (n + 2) lados, em n tri�ngulos.
	
	Exemplo: Qual o n�mero de �rvores bin�rias que temos com (n + 1) folhas.
*/

#include <iostream>

using namespace std;

/*
	Calculo dos n�meros de Catalan.
*/
int catalan(int number) {
	
	if(number <= 0)
		return 1;
		
	return (2 * (2 * number - 1) * catalan(number - 1)) / (number + 1);
}

