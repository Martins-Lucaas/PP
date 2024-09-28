#include <stdio.h>
#include <locale.h>

int main ()
{
    setlocale (LC_ALL, "Portuguese");
	printf ("\nQuestão 4:\n\n");
	
	int num = 233;
	
	if ((num >= 233) && (num < 300))
    {
        for (num; num >= 233 && num < 300; num = num + 5)
        {
            printf("%i,", num);
        }
    }
    
    if ((num > 300) && (num <= 400)){
        for (num; num <= 400; num = num + 3)
        {
            printf("%i,", num);
        }
    }
    
    if ((num > 400) && (num < 456))
    {
        for (num; num > 400 && num <= 456; num = num + 5)
        {
            printf("%i,",num);
        }
    }
    
	return 0;
}
