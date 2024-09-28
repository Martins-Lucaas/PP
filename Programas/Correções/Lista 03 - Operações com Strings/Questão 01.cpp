#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale (LC_ALL, "Portuguese");
	printf ("Questão 1:\n\n");
	
	char string[100];
	int tamanho;
	
	printf("Digite uma String: ");
	gets(string);
	
	tamanho = strlen(string);
	
	printf("\nO tamanho da string é de: %i caracteres. \n", tamanho);
	
	return 0; 
}
	

