#include <stdio.h>

int main(void){
	
	
	printf("Atividade 2 ponteiros\n");
	
	int x = 10;
	double y = 20.50;
	char z = 'a';
	
	int *pX = &x;
	double *pY = &y;
	char *pZ = &z;
	
	int *resultado;
	resultado = &x;
	
	printf("Valor x = %i\n", resultado);
	
	getchar();
	
	return 0;
	
}
