#include <stdio.h>

int main(void){

	printf("Atividade 3 ponteiros\n");
	struct horario{
		int hora;
		int minuto;
		int segundo;	
	};
	
	struct horario agora, *depois;
	depois = &agora;
	
	depois->hora = 15;
	depois->minuto = 11;
	depois->segundo = 58;
	
	printf("%i:%i:%i", agora.hora, agora.minuto, agora.segundo);
	

	getchar();
	
	return 0;
	
	
	
}
