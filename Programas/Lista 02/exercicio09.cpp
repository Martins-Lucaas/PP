#include <stdio.h>
using namespace std;

#define NUM_MAX 128

int main(void)
{
    int num[NUM_MAX];
    for(int i = 1000; i <= 1999; i++)
    {
        if(i % 11 == 5)
        {
            printf("%d,", i);
        }
    }
    printf("\n");
    return 0;
}