#include <stdio.h>
#include <locale.h>

int main ()
{	
	setlocale (LC_ALL, "Portuguese");
	printf ("\nQuest�o 10:\n\n");
	
   int num;
   int pares = 0; 
   int impares = 0;
   
   printf("Digite os n�meros que ser�o calculados:\nObs: O programa encerra quando entrar um n�mero maior que 1000\n\n");

    while(true)
    {
        scanf("%d", &num);
        if(num > 1000)
        {
            printf("\nO programa foi encerrado\n");
            break;
        }
        
        if(num % 2 == 0)
        {
            pares = pares + num;
        }
        else{
            impares = impares + num;
        }
        
    }
    printf("A soma dos n�meros pares digitados s�o: %d\n", pares);
    printf("A soma dos n�meros �mpares digitados s�o: %d\n", impares);
    return 0;
}
