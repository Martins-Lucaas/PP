#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include<string.h>

int main()
{
	setlocale(LC_ALL,"Portuguese");
	
	
	char nome[50],ende[80],cep[8],telefone[15]; 
	
	
	printf("Insira seu nome\n");
	gets(nome);
	
	printf("Insira seu endereço\n");
	gets(ende);
	
	printf("Insira seu CEP\nEle deve ter estar no formato XXXXX-XXX\n");
	gets(cep);
	
	printf("Insira seu telefone\n");
	gets(telefone);
	
	printf("\n");
	printf("Nome completo:%s\n", nome);
	printf("Endereço:%s\n", ende);
	printf("Cep e telefone:%s,   %s\n", cep, telefone);
	return 0;
	
}
