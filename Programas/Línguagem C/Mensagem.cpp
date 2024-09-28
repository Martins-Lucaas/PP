#include <stdio.h>
#include <conio.h>
#include<locale.h>
#include<string.h>


int main()
{
	setlocale(LC_ALL,"Portuguese");
	char mensagem[100];
	
	printf("Digite a sua mensagem\n");
	gets(mensagem);
	fflush(stdin);
	printf("A mensagem digitada foi: %s\n", mensagem);
	
	
	getch();
	return 0;
	
}
