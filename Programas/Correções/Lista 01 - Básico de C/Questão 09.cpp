#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main ()
{
    setlocale (LC_ALL, "Portuguese");
	printf ("Questão 09:\n\n");
	float nota1, nota2, nota3, nota4;
	printf ("Aluno(a)     Nota\n=========    =====\nAline         9.0\nMário         Dez\nSérgio        4.5\nShirley       7.0\n\n");
	float Aline = 9.0;
	float Mario = 10.0;
	float Sergio = 4.5;
	float Shirley = 7.0; 
	if (Aline > 6){
		printf ("Aline foi aprovada!\n");
	} else {
		printf ("Aline foi reprovada!\n");
	}
	if (Mario > 6){
		printf ("Mário foi aprovado!\n");
	} else {
		printf ("Mário foi reprovado!\n");
	}
	if (Sergio > 6){
		printf ("Sérgio foi aprovado!\n");
	} else {
		printf ("Sérgio foi reprovado!\n");
	}
	if (Shirley > 6){
		printf ("Shirley foi aprovada!\n");
	} else {
		printf ("Shirley foi reprovada!\n");
	}
	 return 0;
}	
