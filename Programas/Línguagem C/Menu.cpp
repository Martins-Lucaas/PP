#include <stdio.h>
#include <stdlib.h>
#include<locale.h>



int main()
{
	setlocale(LC_ALL,"Portuguese");
	
	int number;


    printf("0 - Fim\n");
    printf("1 - inlcui\n");
    printf("2 - Altera \n");
    printf("3 - Exclui\n");
    printf("4 - consulta\n");
    
    
    scanf("%i",&number);
    printf("Opção: '%i'", number);
    

	return 0;
	
}
