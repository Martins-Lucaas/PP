#include <stdio.h>
using namespace std;

int main(void)
{
    int n;
    int pares = 0, impares = 0;

    printf("Digite os numeros que serao somados da seguinte forma: par-par e impar-impar\nAtencao, para valores maiores que 1000, a execucao sera encerrada.\n");

    while(true)
    {
        scanf("%d", &n);
        if(n > 1000)
        {
            printf("A execução foi encerrada\n");
            break;
        }
        
        if(n % 2 == 0)
        {
            pares = pares + n;
        }
        else{
            impares = impares + n;
        }
        
    }
    printf("A somatoría dos números pares digitados é %d\n", pares);
    printf("A somatória dos númeos ímpares digitados é %d\n", impares);
    return 0;
}
