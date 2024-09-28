#include <stdio.h>

int main(void){
	
	
	printf("Atividade 1 ponteiros\n");
	
	int x = 10;
	int*ponteiro;
	
	ponteiro = &x;
	
	int y = 20;
	*ponteiro = y;
	
	printf("%i %i\n", x, y);
	
	getchar();
	
	return 0;
	
}
