#include <stdio.h>
#include <locale.h>

int main ()
{	
	setlocale (LC_ALL, "Portuguese");
	printf ("\nQuestão 9:\n\n");
	
    int num;
     
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
