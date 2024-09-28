#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main ()
{
	setlocale (LC_ALL, "Portuguese");
	printf ("Questão 03:\n\n");
    printf ("Aluno(a)     Nota\n=========    =====\nAline         9.0\nMário         Dez\nSérgio        4.5\nShirley       7.0");
    return 0;
}
