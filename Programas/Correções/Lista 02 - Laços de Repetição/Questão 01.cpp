#include <stdio.h>
#include <locale.h>

int main ()
{
    setlocale (LC_ALL, "Portuguese");
	printf ("\nQuestão 1:\n\n");
	
	int contador = 0;
	int num;
	num = 1;
	
	while (num <= 100){
		printf ("%i, ", num);
		++num;
	}
	
	printf ("\n\nDigite um número: ");
    scanf("%i", &contador);
    printf ("%i, ", contador);

	while (contador <= 100) {
	contador  = contador * 3;	
	printf ("%i, ", contador);
	}
	return 0;
}
