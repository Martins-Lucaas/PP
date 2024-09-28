#include <stdio.h>
#include <locale.h>

int main ()
{	
	setlocale (LC_ALL, "Portuguese");
	printf ("\nQuestão 7:\n\n");
	
	int num[15];
    
    for(int i=0;i<15;i++)
    {
        scanf("%d", &num[i]);
    }

    int min = num[0]; 
    for(int i=0; i<15; i++)
    {
        if(num[i]<min)
        {
            min = num[i];
        }
    }

    int max = num[0]; 
    for(int i=0; i<15; i++){
        if(num[i]>max)
        {
            max = num[i];
        }
    }

    printf("O maior valor digitado foi %d\n", max);
    printf("O menor valor digitado foi %d\n", min);

    return 0;
}
