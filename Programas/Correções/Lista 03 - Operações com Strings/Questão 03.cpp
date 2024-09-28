#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale (LC_ALL, "Portuguese");
	printf ("Questão 3:\n\n");
	
	char string1[100];
	char string2[100];
	char string3[100];
	int comparacao1;
	int comparacao2;
	int comparacao3; 
	int comparacao4;
	
	printf("\nDigite a primeira String: ");
	gets(string1);
	
	printf("\nDigite a segunda String: ");
	gets(string2);
	
	printf("\nDigite a terceira String: ");
	gets(string3);
	
	comparacao1 = strcmp(string1, string2);
	comparacao2 = strcmp(string1, string3);
	comparacao3 = strcmp(string2, string3);
	
	if (comparacao1 == 0){
	    printf ("\nA primeira string é igual a segunda\n");
	} else {
     	printf ("\nA primeira string é diferente da segunda\n");
	}
	
	if (comparacao2 == 0){
    	printf ("A primeira string é igual a terceira\n");
	} else {
	    printf ("A primeira string é diferente da terceira\n");
	}
	
	if (comparacao3 == 0){
	    printf ("A segunda string é igual a terceira\n");
	} else {
	    printf ("A segunda string é diferente da terceira\n");
	}
	
	return 0; 
}
