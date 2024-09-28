#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>

int main() {
	
 	setlocale (LC_ALL, "Portuguese");
	printf ("Questão 04:\n\n");
	
	int matriz [3][4] = {{10, 10, 10, 10}, {10, 10, 10, 10}, {10, 10, 10, 10}};
	int linha = 0;
	int coluna = 0;
	
	while(linha<=2){
		int coluna = 0;
		while(coluna<=3){
		printf("%i", matriz[linha][coluna]+15);
		++coluna;
	}
	++linha;
	printf ("\n");
}

	return 0;
}

