#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

int espacos(int i, int count, char fr)
{
	
	setlocale (LC_ALL, "Portuguese");
	printf ("Questão 4:\n\n");
	  
	  	char frase[100];
	    fr = frase[0];
	  
	  	printf("Digite uma frase: ");
		gets(frase);
		
	    while (fr != '\0') {
	        fr = frase[i];
	        if (isspace(fr))
	            count++;
	        i++;
	    }
	    
	    return (count);
}

int main()
{  
    char fr;
    int i = 0, count = 0;
  
    count = espacos(i, count, fr);
  
    printf("\nO número de espaços em branco é: %d", count);
  
    return 0;
}


	

