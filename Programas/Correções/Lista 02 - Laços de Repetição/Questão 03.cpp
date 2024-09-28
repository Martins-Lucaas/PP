#include <stdio.h>
#include <locale.h>

int main ()
{
    setlocale (LC_ALL, "Portuguese");
	printf ("\nQuestão 3:\n\n");
	
	int contador  = 0;
	int soma = 0;
	int num;
	
    printf ("Digite um número: ");
    scanf("%i", &num);
	
	while (contador <= num){
     	soma = soma + contador;
	    ++contador; 
	}
	printf ("%i", soma);
	
	return 0;
}
