#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main ()
{
	setlocale (LC_ALL, "Portuguese");
	printf ("Quest�o 04:\n\n");
    printf ("0 - Fim\n1 - Inclui\n2 - Altera\n3 - Exclui\n4 - Consulta\n");
    int Opcao;
	scanf ("%i", &Opcao);
	printf ("Op��o = %i\n", Opcao);
    return 0;
}
