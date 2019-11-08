#include <stdio.h>
#include <stdlib.h>

/*
Construa um algoritmo que leia as três notas de
50 alunos de uma turma. Para cada aluno, calcule a
média ponderada, como segue:
MP = ( n1*2 + n2*4 + n3*3 ) / 10. Além disso,
calcule a média geral da
turma. Mostre a média de cada aluno e uma mensagem "Aprovado",
caso a média seja maior ou igual a
sete, e uma mensagem "Reprovado", caso contrário. No final,
mostre a média geral
*/

void calc_media_aluno(struct aluno *a)
{
    a->media = ( a->n1*2 + a->n2*4 + a->n3*3 ) / 10;
}

struct aluno{
    int n1;
    int n2;
    int n3;
    float media;
};

struct turma{
    struct aluno alunos[50];
    float media;
};

int passou(struct aluno *a)
{
    return a->media >= 10.0;
}

void calc_media_turma(struct turma *t)
{
    float acc = 0;
    int i;
    for(i = 0; i < 50; i++){
        calc_media_aluno(&t->alunos[i]);
        if(passou(&t->alunos[i])){
            printf("aluno passou\n");
        }else{
            printf("aluno chumbou\n");
        }
        acc = (acc + t->alunos[i].media);
    }
    t->media = acc/50;
}

void ex_3_21()
{
    struct turma am_lp;
    calc_media_turma(&am_lp);
}

int main()
{
    ex_3_21();
    return 0;
}
