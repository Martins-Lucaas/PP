#include <stdio.h>
#include <locale.h>

int main ()
{
    setlocale (LC_ALL, "Portuguese");
	printf ("Questão 10:\n\n");
	float base, altura, area;
	printf ("Digite a base do triângulo: ");
    scanf("%f", &base);
    printf ("Digite a altura do triângulo: ");
    scanf("%f", &altura);
    area = (base * altura)/2;
    printf ("A área do triângulo é: %f\n\n\n", area);
    return 0;
}
