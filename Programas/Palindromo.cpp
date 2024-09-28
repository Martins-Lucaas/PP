#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main ()
{
	char Frase[80], FraseInv[80];
	int j,i, tamanho, iguais;
	
	printf("Insira a frase que se deseja ser analisada\n");
	gets(Frase);

	tamanho = strlen(Frase);
	
	for(i = tamanho-1 , j=0;i>=0;i--,j++){
		FraseInv[j]=Frase[i];	
	}
	
	iguais = strcmpi(Frase,FraseInv);
	printf("\n%d\n",iguais);
	
	if(iguais==0){
		printf("Palindromo\n");
	}
	else{
		printf("Nao e palindromo\n");
	}
	
	return 0;
	
}
