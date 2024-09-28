#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>

int main (void){
	
	setlocale (LC_ALL, "Portuguese");
	printf ("Questão 03:\n\n");
	
    int matriz[3][4] = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 4; ++j){
		    printf("%i ", matriz[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
