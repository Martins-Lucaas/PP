#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


int main ()
{
	setlocale (LC_ALL, "Portuguese");
	printf ("Quest�o 06:\n\n");
    printf ("Insira seu nome:\n");
    char nome[100];
    gets(nome);	
	printf ("insira seu endere�o:\n");
    char endereco[100];
    gets(endereco);
	printf ("Insira seu CEP:\nEle deve estar no formado XXXXX-XXX\n");
    char cep[100];
    gets(cep);	
    printf ("Insira seu telefone\n");
    char telefone[100];
    gets(telefone);	
	printf ("\nNome completo: %s\nEndere�o: %s\nCEP e telefone: %s, %s\n", nome, endereco, cep, telefone);
    return 0;
}
