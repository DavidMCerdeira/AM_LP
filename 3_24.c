/* 3.24) Uma loja tem 150 clientes registrados e deseja
mandar uma correspondência a cada um deles
anunciando um bónus especial. Escreva um algoritmo que
leia o nome do cliente e o valor das suas
compras no ano passado e calcule um bónus de 10% se o valor
das compras for menor que 1000€ e de
20%, caso contrário */
struct data{
    int year;
};

struct compra{
    float valor;
    struct data d;
};

struct client{
    char nome[100];
    char morada[100];
    int n_compras;
    struct compra *compras;
};

struct loja{
    struct client clientes[150];
};

int calc_bonus(struct client *c)
{
    int acc = 0;
    int last_year = current_year() - 1;

    for(int i = 0; i < 100; i++){
        if(c->compras[i]->d.year == last_year){
            acc += c->compras[i]->valor;
        }
    }

    return acc > 1000 ? 20 : 10;
}

void enviar_bonus(struct client *c, int bonus)
{
    printf("Sending bonus to %s\n", c->morada);
}

void ex_3_24()
{
    struct loja l;

    get_data(&l);

    int bonus;
    for(int i = 0; i < 150; i++){
        bonus = calc_bonus(&l.clientes[i]);
        enviar_bonus(&l.clientes[i], bonus);
    }
}
