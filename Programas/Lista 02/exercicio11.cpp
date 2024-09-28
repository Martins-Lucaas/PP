#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

#define TAM_MAX 100010

int main(void)
{
    int n, cont = 0;

    printf("Digite um número inteiro\n");
    scanf("%d", &n);


/*bool e_composto[TAM_MAX];

    void crivo(int n)
    {
        e_composto[1] = 1; //1 não é composto, mas na verdade guarda os números que não são primos
        for(int i = 2; i <= n; ++i)
        {
            if(!e_composto[i])
            {
                for(int j = 2; i*j <= n; ++j)
                {
                    e_composto[i*j] = 1;
                }
            }
        }
        return;
    }

int main()
{
    int N, Q, a;
    scanf("%d, %d", N, Q);
    crivo(N); //Complexidade 0(n*log(log(n)))
    for(int i = 0; i < Q; ++i) //Complexidade 0(Q)
    {
        scanf("%d", a);
        printf("%d\n", !e_composto[a]); //Se composto é falso, então primo, caso contrário é composto
    }
}*/

//--------------------------------------------------------------------
    for (int i = 2; i <= n / 2; i++) 
    {
        if (n % i == 0) 
        {
            cont++;
            break;
        }
    }

    if (cont == 0)
    {
        printf("%d é um número primo\n", n);
    }  
    if (n == 1 || cont != 0)
    {
        printf("%d não é um número primo\n", n);
    }

    return 0;
}
//--------------------------------------------------------------------

//Há problema com os números 1 e 2 dessa forma
//Método de resolução - Crivo de Eratóstenes