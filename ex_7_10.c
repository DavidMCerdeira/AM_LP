/* 7.10) Construa uma função que recebe, por parâmetro,
a altura (alt) e o sexo de uma pessoa e
retorna o seu peso ideal. Para homens, calcular o peso ideal
usando a fórmula peso ideal =
72.7 x alt - 58 e ,para mulheres, peso ideal = 62.1 x alt - 44.7 */
struct pessoa{
    char sexo;
    float altura;
};

float calc_peso_ideal(struct pessoa *p)
{
    float peso_ideal = -1;

    switch(p->sexo){
    case 'H':
    case 'h':
    peso_ideal = 72.7 * p->altura - 58;
    break;

    case 'M':
    case 'm':
    peso_ideal = 62.1 * p->altura - 44.7;
    break;
    }

    return peso_ideal;
}

void ex_7_10()
{
    struct pessoa p;

    printf("Ideal weight is &.2f\n", calc_peso_ideal(&p));
}
