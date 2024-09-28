#include <stdio.h>
using namespace std;

int main(void) 
{
    int multiplos = 0;

    for (int i=0; i <=100; i++)
    {
        if (i%30==0)
        {
            multiplos++;
        }
    }
    printf("Existem %d multiplos de 2, 3 e 5 ao mesmo tempo entre 1 e 100\n",multiplos);
    return 0;
}