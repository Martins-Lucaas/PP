#include <stdio.h>
#include<locale.h>

#define TAM_MAX 128

int main(void)
{
    setlocale(LC_ALL,"Portuguese");
	int num[TAM_MAX];
    printf("Digite os 15 valores \n");

    for(int i=0;i<15;i++)
    {
        scanf("%d", &num[i]);
    }

    int min = num[0]; //valor mínimo
    for(int i=0; i<15; i++)
    {
        if(num[i]<min)
        {
            min = num[i];
        }
    }

    int max = num[0]; //valor máximo
    for(int i=0; i<15; i++){
        if(num[i]>max)
        {
            max = num[i];
        }
    }

    printf("O maior valor digitado foi %d\n", max);
    printf("O menor valor digitado foi %d\n", min);

    return 0;
    
}
