#include <stdio.h>
#include <locale.h>

int main ()
{	
	setlocale (LC_ALL, "Portuguese");
	printf ("\nQuest�o 11:\n\n");
	
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
        printf("O n�mero %d � primo!\n", num);
        }
        else{
        printf("O n�mero %d n�o � primo!\n", num);
    }
    return 0;
}
