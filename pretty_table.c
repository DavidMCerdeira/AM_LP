#include <stdio.h>  /* printf, scanf, puts */
#include <stdlib.h> /* realloc, free, exit, NULL */

#ifndef N
#define N 8
#endif

void print_ascii_table()
{
    for (int i = 0; i < 256; i++)
        printf("%c -> %d\n\n", i, i);
}
int main()
{
    int line_size = 0;
    line_size = printf("     ");

    for (int i = 1; i <= N; i++)
    {
        line_size += printf(" %4d ", i);
    }
    line_size += printf("\n");

    putchar(201);
    for (int i = 1; i < line_size - 1; i++)
    {
        if ((i + 1) % 6 == 0)
            putchar(203);
        else
            putchar(205);
    }
    putchar(187);
    printf("\n");

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            printf("%4d %c", j * i, 186);
        }
        printf("\n");
    }

    putchar(200);
    for (int i = 1; i < line_size - 1; i++)
    {
        if ((i + 1) % 6 == 0)
            putchar(202);
        else
            putchar(205);
    }
    putchar(188);

    printf("\n");
}
