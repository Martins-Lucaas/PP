#include <stdio.h>

int main(void){
	void testeVariavel (int x);
	void testePonteiro(int *pX);
	int teste = 25;
	int *pTeste = &teste;
	
	testePonteiro(pTeste);
	
	
	printf("%i\n", teste);
	
	getchar();
	return 0;	
}

void testeVariavel(int x){
	++x;
}
void testePonteiro(int *pX){
	++*pX;
}
