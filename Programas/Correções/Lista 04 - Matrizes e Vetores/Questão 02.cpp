#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main ()
{
	setlocale (LC_ALL, "Portuguese");
	printf ("Quest�o 02:\n\n");
    int vetor1[5] = {0};
    int vetor2[5];
    int count;
    int aux, i, x;
    
    for (i = 0; i < 5; ++i){
    	printf("insira o valor da posi��o %i do vetor 1: ", i);
    	scanf("%i", &vetor1[i]);
	}
	
	for(i = 0; i < 5; ++i){
		for(x = i+1; x < 5; ++x){
			if(vetor1[i] > vetor1[x]){
				aux = vetor1[i];
				vetor1[i] = vetor1[x];
				vetor1[x] = aux;
			}
		}	
	}    
  
	for(count=0 ; count < 5; count++)
	    vetor2[count] = vetor1[count];
	
    printf("\nO vetor 2 ser�");
	for (int i = 0; i < 5; ++i){
		printf(" %i", vetor2[i]);
	}
	
	return 0;
}



