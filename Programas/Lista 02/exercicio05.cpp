#include <stdio.h>
using namespace std;

int main(void)
{
    int mult2 = 0, mult3 = 0, mult5 = 0;

    for (int i=1; i<=100; i=i+2)
    {
        mult2 = mult2 + 1;
    }
    
    for (int i=1; i<=100; i=i+3)
    {
        mult3 = mult3 + 1;
    }

    for (int i=1; i<=100; i=i+5)
    {
        mult5 = mult5 + 1;
    }

    printf("Existem, entre 1 e 100, existem %d multiplos de 2, %d multiplos de 3, %d multiplos de 5\n", mult2, mult3, mult5);
    return 0;
}