#include <stdio.h>
#include <locale.h>

int main ()
{
    setlocale (LC_ALL, "Portuguese");
	printf ("\nQuestão 2:\n\n");
	
	int contador = 10, soma = 0;
	
	while (contador >= 3){
		printf("%i\n", contador);
		soma = soma + contador;
		--contador;
	}
	printf ("\nSoma: %d\n", soma); 
	return 0;
}
