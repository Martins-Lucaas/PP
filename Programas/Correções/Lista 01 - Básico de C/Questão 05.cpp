#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


int main ()
{
	setlocale (LC_ALL, "Portuguese");
	printf ("Questão 05:\n\n");
    printf ("Digite a sua mensagem:\n");
    char mensagem[100];
    gets(mensagem);	
	printf ("a mensagem digitada foi: %s\n", mensagem);
    return 0;
}
