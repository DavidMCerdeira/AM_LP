#include <stdio.h>
#include <stdlib.h>

/*3.15) Escrever um algoritmo que lê 5 pares de valores a, b,
todos inteiros e positivos, um par de cada vez,
e com a < b, escreve os inteiros pares de a até b,
incluindo o a e o b se forem pares.
*/

void print_within(int a, int b)
{
    for(int i = a; i < b; i++)
    {
        if(i % 2 == 0)
            printf("%d ", i);
    }
}

void ex3_15()
{
    /* 5 linhas, 2 colunas */
    int pairs[5][2];
    int a, b;

    int i = 0;
    while(i < 5)
    {
        int a;
        int b;
        scanf("%i %i", &a, &b);
        pairs[i][0] = a;
        pairs[i][1] = b;
        i++;
    }

    for(int j = 0; j < i; j++)
    {
        if(pairs[j][0] < pairs[j][1])
        {
            print_within(pairs[j][0], pairs[j][1]);
        }
    }
}

/*Escrever um algoritmo que leia uma quantidade desconhecida de números e conte quantos deles
estão nos seguintes intervalos: [0.25], [26,50], [51,75] e [76,100].
A entrada de dados deve terminar quando for lido um número negativo. */
void ex3_10()
{
    int interval[][2] = { {0, 25},
        {26, 50},
        {51, 75},
        {76, 1000}
    };

    int numero_de_intervalos = sizeof(interval)/sizeof(interval[0]);
    int n;
    int counter = 0;
    do
    {
        scanf("%i", &n);
        for(int i = 0; i < numero_de_intervalos; i++)
        {
            int min = interval[i][0];
            int max = interval[i][1];
            if((n >= min) && (n <= max))
            {
                counter++;
                break;
            }
        }
    }
    while(n >= 0);

    printf("%d", counter);
}
void desenha_linha(char c, int size)
{
    while(size-- > 0)
        printf("%c", c);
    printf("\n");
}
void desenha_margens(char c, int size)
{
    int s = size;

    printf("%c", c);
    int n_space = size - 3;
    for(int i = 0; i < n_space; i++)
        printf(" ");

    printf("%c", c);
    printf("\n");
}
void desenha_quad(char c, int size)
{
    int s = size;
    desenha_linha(c, size);
    while(size-- > 2)
    {
        desenha_margens(c, s);
    }
    desenha_linha(c, s);
}

void ex9_3()
{
    int g = 5;
    desenha_quad('u', g);
    printf("%d", g);
}

void print_n_char(char c, int n)
{
    while(n--)
        putchar(c);
}

void imprime_folhas(char c, int size)
{
    for(int i = size; i > 0; i--)
    {
        print_n_char('a', i-1);
        print_n_char(c, (size - i)*2 + 1);
        putchar('\n');
    }
}

void imprime_tronco(char c, int size)
{
}

void desenha_arv(char c, int size)
{
    imprime_folhas(c, size);
    imprime_tronco(c, size);
}
void ex9_7()
{
    desenha_arv('#', 4);
}

/* 4.26) Escreva um algoritmo que leia10 caracteres
para um vector e os escreva depois, noecrã, em ordem inversa */
void invert(int vec[], int n)
{
    for(int i = 0; i < n/2; i++)
    {
        int aux = vec[n-i - 1];
        vec[n-i - 1] = vec[i];
        vec[i] = aux;
        print_vec(vec, 10);
    }
}

void print_vec(int vec[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", vec[i]);
    }
    putchar('\n');
}

void ex4_26()
{
    int vec[] = {1,2,3,4,5,6,7,8,9,10};

    print_vec(vec, 10);
    invert(vec, 10);
    print_vec(&vec[0], 10);
}

int main()
{
    ex4_26();
    return 0;
}
