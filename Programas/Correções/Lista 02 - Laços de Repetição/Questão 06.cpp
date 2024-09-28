#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
	setlocale (LC_ALL, "Portuguese");
	printf ("\nQuestão 6:\n\n");
	
	int multiplos = 0;
	int x = 1;
	
	while (x <= 100){
		if(x % 30 == 0){
		++multiplos;
		}
		++ x;
	}
    
    printf("Existem %i multiplos de 2, 3 e 5 ao mesmo tempo entre 1 e 100\n", multiplos);
	return 0;
}
