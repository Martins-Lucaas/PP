#include <stdio.h>
#include <locale.h>

int main ()
{
    setlocale (LC_ALL, "Portuguese");
	printf ("Quest�o 10:\n\n");
	float base, altura, area;
	printf ("Digite a base do tri�ngulo: ");
    scanf("%f", &base);
    printf ("Digite a altura do tri�ngulo: ");
    scanf("%f", &altura);
    area = (base * altura)/2;
    printf ("A �rea do tri�ngulo �: %f\n\n\n", area);
    return 0;
}
