#include <stdio.h>
#include<locale.h>

int main(void)
{
	setlocale(LC_ALL,"Portuguese");
    int numeros, contador = 1;

    printf("Digite os n�meros que ser�o calculados:\nO n�mero 0 encerra a opera��o.\n");

    while(numeros =! 0)
    {
        scanf("%d", &numeros);
        if(numeros == 0)
        {
            break;
        }
        contador = contador * numeros;
    }

    printf("O produto dos n�meros digitados �: %d\n", contador);

    return 0;
}
