#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main ()
{
	setlocale (LC_ALL, "Portuguese");
	printf ("Questão 01:\n\n");
    int vetor[5] = {1, 2, 3, 4, 5};
    
	printf("vetor =");
	for (int i = 0; i < 5; ++i){
		printf(" %i",  vetor[i]);
	}
	
	return 0;
}
