#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main ()
{
    setlocale (LC_ALL, "Portuguese");
	printf ("Questão 08:\n\n");
	float valor1, valor2, valor3, valor4, valor5, med;
	printf ("Digite o primeiro número: ");
    scanf("%f", &valor1);
    printf ("Digite o segundo número: ");
    scanf("%f", &valor2);
    printf ("Digite o terceiro número: ");
    scanf("%f", &valor3);
    printf ("Digite o quarto número: ");
    scanf("%f", &valor4);
    printf ("Digite o quinto número: ");
    scanf("%f", &valor5);
    med = (valor1 + valor2 + valor3 + valor4 + valor5) / 5;
    printf ("A média dos números é: %f\n", med);
    return 0;
}
