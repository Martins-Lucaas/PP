#include <stdio.h>
using namespace std;

int main(void)
{
    int cont = 0;
    int i = 3;

    while(i<=10){
        printf("%d,",i);
        cont = cont + i;
        i++;
    }
    printf("\n");
    printf("A soma dos números é:%d\n",cont);
    printf("%d", i);
    return 0;
}