#include <stdio.h>
#include <locale.h>

int main ()
{
	
	setlocale (LC_ALL, "Portuguese");
	printf ("\nQuest�o 8:\n\n");
	
    int nums, contador = 1;

    printf("Digite os n�meros que ser�o calculados:\nObs: digite o n�mero 0 para encerrar o programa.\n");

    while(true)
    {
        scanf("%d", &nums);
        if(nums == 0)
        {
            break;
        }
        contador = contador * nums;
    }

    printf("O produto dos n�meros digitados s�o: %d\n", contador);
	return 0;
}
