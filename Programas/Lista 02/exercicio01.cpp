#include <stdio.h>
using namespace std;

int main(void)
{
    int num = 0;
    printf("Digite um número:\n");
    scanf("%d", &num);
    printf("%d,", num);
    
    while(num < 100)
    {
        num = num * 3;
        printf("%d,", num);
    }
    
    printf("\n");
    return 0;
}
