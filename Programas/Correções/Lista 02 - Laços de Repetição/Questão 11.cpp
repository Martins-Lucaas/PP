#include <stdio.h>
#include <locale.h>

int main ()
{	
	setlocale (LC_ALL, "Portuguese");
	printf ("\nQuestão 11:\n\n");
	
   int num; 
   int i;
   int result = 0;
   
   printf("Digite um numero: ");
   scanf("%d", &num);
   
   for (i = 2; i <= num / 2; i++){
   	if (num % i == 0) {
   		result++;
   		break;
	   }
   }

    if(result == 0){
        printf("O número %d é primo!\n", num);
        }
        else{
        printf("O número %d não é primo!\n", num);
    }
    return 0;
}
