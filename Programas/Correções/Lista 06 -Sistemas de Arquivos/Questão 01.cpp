#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main ()
{
    setlocale (LC_ALL, "Portuguese");
	printf ("Questão 01:\n\n");
	
	char frase[100] = "";
	int c = -1;

	FILE *file;
    file = fopen("questao1.txt", "w");
   
    if (file == NULL) {
        printf("Erro ao tentar abrir o arquivo!");
        exit(1); }
        
    printf("Digite frases e para encerrar digite \"Fim\": \n");
	while(strcmp(frase, "Fim\n") != 0){
		fgets(frase, 100, stdin);
		fputs(frase, file);
		c++;
	}
    fclose(file);
    
     printf("\ncontando frases...\n");

    while(fgets(frase, 100, file) != NULL) printf("%s", frase);
    printf("\nForam %d frases digitadas.\n", c);

    fclose(file);
    
    return 0;

}



