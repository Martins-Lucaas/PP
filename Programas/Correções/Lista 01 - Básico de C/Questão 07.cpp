#include <stdio.h>
#include <locale.h>

int main ()
{
    setlocale (LC_ALL, "Portuguese");
	printf ("Questão 07:\n\n");
	printf ("7.1. Soma\n\n");
	float valor1, valor2, soma;
	printf ("Digite um número: ");
    scanf("%f", &valor1);
    printf ("Digite outro número: ");
    scanf("%f", &valor2);
    soma = valor1 + valor2;
    printf ("A soma dos dois números é: %f\n\n\n", soma);
    
    printf ("7.2. Subtração\n\n");
	float valor3, valor4, sub;
	printf ("Digite um número: ");
    scanf("%f", &valor3);
    printf ("Digite outro número: ");
    scanf("%f", &valor4);
    sub = valor3 - valor4;
    printf ("A subtração dos dois números é: %f\n\n\n", sub);
    
    printf ("7.3. Divisão\n\n");
	float valor5, valor6, div;
	printf ("Digite um número: ");
    scanf("%f", &valor5);
    printf ("Digite outro número: ");
    scanf("%f", &valor6);
    div = valor5/valor6;
    printf ("A divisão dos dois números é: %f\n\n\n", div);
    
    printf ("7.4. Multiplicação\n\n");
	float valor7, valor8, mult;
	printf ("Digite um número: ");
    scanf("%f", &valor7);
    printf ("Digite outro número: ");
    scanf("%f", &valor8);
    mult = valor7 * valor8;
    printf ("A multiplicação dos dois números é: %f\n\n", mult);
    return 0;
}
