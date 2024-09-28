#include <stdio.h>
#include <locale.h>

int main ()
{
    setlocale (LC_ALL, "Portuguese");
	printf ("\nQuestão 5:\n\n");
	
	int multiplo2;
	int multiplo3;
	int multiplo5;
	
	for (int x=1; x<=100; x=x+2)
    {
        multiplo2 = multiplo2 + 1;
    }
    
    for (int x=1; x<=100; x=x+3)
    {
        multiplo3 = multiplo3 + 1;
    }

    for (int x=1; x<=100; x=x+5)
    {
        multiplo5 = multiplo5 + 1;
    }

    printf("Entre 1 e 100, existem %i multiplos de 2, %i multiplos de 3 e %i multiplos de 5\n", multiplo2, multiplo3, multiplo5);
    
	return 0;
}
