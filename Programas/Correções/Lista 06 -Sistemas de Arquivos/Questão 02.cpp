#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main ()
{
    setlocale (LC_ALL, "Portuguese");
	printf ("Questão 02:\n\n");
	
	int n, i, nfat, r;    
	  FILE *file2;
	  file2 = fopen("questao2.txt", "a");
	  
	  printf("Digite um número para ser calculado fatorial: ");
	  scanf("%d", &n);
	  nfat = 1;
	  for (i = n; i > 1; i--) {
	      nfat = nfat * i; }
	  fprintf(file2,"O valor de %d!= %d\n", n, nfat);
	  if(r == EOF) {
	       printf("\nErro ao tentar gravar os dados! \n"); }
	   else {
	        printf("\nDados gravados com sucesso. \n"); }
	   fclose(file2);
	   
	  return 0;
}



