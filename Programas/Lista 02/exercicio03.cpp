#include <stdio.h>
using namespace std;

int main(void)
{
    int num;
    int soma = 0;
    int cont = 0;
    printf("Digite um número:\n");
    scanf("%d", &num);

    while (cont <= num){
        soma = soma + cont;
        cont++;
    }

    printf("A soma dos números de 1 até %d é:%d\n", num, soma);
    return 0;
}