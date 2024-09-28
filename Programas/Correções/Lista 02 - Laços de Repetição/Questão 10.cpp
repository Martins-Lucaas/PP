#include <stdio.h>
#include <locale.h>

int main ()
{	
	setlocale (LC_ALL, "Portuguese");
	printf ("\nQuestão 10:\n\n");
	
   int num;
   int pares = 0; 
   int impares = 0;
   
   printf("Digite os números que serão calculados:\nObs: O programa encerra quando entrar um número maior que 1000\n\n");

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
    printf("A soma dos números pares digitados são: %d\n", pares);
    printf("A soma dos números ímpares digitados são: %d\n", impares);
    return 0;
}
