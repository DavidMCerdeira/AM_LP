/*3.15) Escrever um algoritmo que lê 5 pares de valores a, b,
todos inteiros e positivos, um par de cada vez,
e com a < b, escreve os inteiros pares de a até b,
incluindo o a e o b se forem pares.
*/

void print_within(int a, int b)
{
    for(int i = a; i < b; i++){
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
        pairs[j][0] = a;
        pairs[j][1] = b;
        i++;
    }

    for(int j = 0; j < i; j++){
        if(pairs[j][0] < pairs[j][1]){
            print_within(pairs[j][0], pairs[j][1]);
        }
    }
}
