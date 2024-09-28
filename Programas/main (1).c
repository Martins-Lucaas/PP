#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    double dol, eur, lib, real;
    int letra;
    printf("----Questao 3----\n");


    printf("Insira a quantidade em dolar: ");
    scanf("%f", &dol);

    printf("Insira a moeda de conversao:\n");
    printf("E => Euro\n");
    printf("L => Libra esterlina\n");
    printf("R => Real brasileiro\n");


    scanf("%i",&letra);
    printf("Voce digitou: '%i'", letra);
	
    if (letra == "e"){
        eur = dol / 0,896547;
        printf("Quantidade equivalente = %.2\n", eur);

    }

    if (letra == "l"){
        lib = dol / 0,746144;
        printf("Quantidade equivalente = %.2\n", lib);
    }

    if (letra == "r"){
        real = dol / 5,369490;
        printf("Quantidade equivalente = %.2\n", real);
    }

    return 0;
}
