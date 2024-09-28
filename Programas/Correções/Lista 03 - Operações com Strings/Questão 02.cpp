#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale (LC_ALL, "Portuguese");
	printf ("Questão 2:\n\n");
	
	char string1[100];
	char string2[100];
	
	printf("Digite uma String: ");
	gets(string1);
	
	printf("Digite outra String: ");
	gets(string2);
	
	strcat(string1, string2);
	
	printf("\n%s\n", string1);
	
	return 0; 
}
	
