#include <stdio.h>
using namespace std;

int main(void)
{
    int num = 233;
    if ((num >= 233) && (num < 300))
    {
        for (num; num >= 233 && num < 300; num = num + 2)
        {
            printf("%d,", num);
        }
    }
    if ((num > 300) && (num <= 400)){
        for (num; num <= 400; num = num + 5)
        {
            printf("%d,", num);
        }
    }
    if ((num > 400) && (num < 456))
    {
        for (num; num > 400 && num <= 456; num = num + 2)
        {
            printf("%d,",num);
        }
    }
    return 0;
}