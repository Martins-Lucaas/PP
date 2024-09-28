#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale (LC_ALL, "Portuguese");
	printf ("Quest„o 5:\n\n");
	
	char palavra[100];
	int i;
	int tamanho;
	int diferentes = 0;
	
	printf("Digite uma palavra: ");
	gets(palavra);
	
	tamanho = strlen(palavra);
	--tamanho;
	i = 0;
	
	while(tamanho >= i){
		if(palavra[i] != palavra[tamanho])
		   ++diferentes;
		++i;
		--tamanho;	
	}
	
	if(diferentes==0)
     	printf("\n… palindromo!\n");
    else
        printf("\nN„o È palindromo!");
	
	return 0; 
}
