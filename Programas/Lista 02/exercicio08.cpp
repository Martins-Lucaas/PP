#include <stdio.h>
#include<locale.h>

int main(void)
{
	setlocale(LC_ALL,"Portuguese");
    int numeros, contador = 1;

    printf("Digite os números que serão calculados:\nO número 0 encerra a operação.\n");

    while(numeros =! 0)
    {
        scanf("%d", &numeros);
        if(numeros == 0)
        {
            break;
        }
        contador = contador * numeros;
    }

    printf("O produto dos números digitados é: %d\n", contador);

    return 0;
}
