#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main ()
{
    setlocale (LC_ALL, "Portuguese");
	printf ("Quest�o 08:\n\n");
	float valor1, valor2, valor3, valor4, valor5, med;
	printf ("Digite o primeiro n�mero: ");
    scanf("%f", &valor1);
    printf ("Digite o segundo n�mero: ");
    scanf("%f", &valor2);
    printf ("Digite o terceiro n�mero: ");
    scanf("%f", &valor3);
    printf ("Digite o quarto n�mero: ");
    scanf("%f", &valor4);
    printf ("Digite o quinto n�mero: ");
    scanf("%f", &valor5);
    med = (valor1 + valor2 + valor3 + valor4 + valor5) / 5;
    printf ("A m�dia dos n�meros �: %f\n", med);
    return 0;
}
