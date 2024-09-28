#include <stdio.h>
#include <locale.h>

int main ()
{
	
	setlocale (LC_ALL, "Portuguese");
	printf ("\nQuestão 8:\n\n");
	
    int nums, contador = 1;

    printf("Digite os números que serão calculados:\nObs: digite o número 0 para encerrar o programa.\n");

    while(true)
    {
        scanf("%d", &nums);
        if(nums == 0)
        {
            break;
        }
        contador = contador * nums;
    }

    printf("O produto dos números digitados são: %d\n", contador);
	return 0;
}
