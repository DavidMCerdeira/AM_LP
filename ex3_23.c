#include <string.h>

/*3.23) Foi feita uma estatística nas 50 principais cidades portuguesas para recolher dados sobre acidentes
de trânsito. Foram obtidos os seguintes dados: - código da cidade ; - distrito (PO, LI, BR, ...) ; - número
de veículos de passeio (em 2001) ; - número de acidentes de trânsito com vítimas (em 2001)
Deseja-se saber: a, b, c */
struct cidade
{
    char distrito[2];
    int codigo;
    int n_veiculos;
    int n_acidentes_com_vitimas;
};

//a) qual o maior e o menor índice de acidentes de trânsito e a que cidades pertencem
void a(struct cidade cidades[], int s, struct cidade **cid_max, float *max_ind,
                                        struct cidade **cid_min, float *min_ind)
{
    float lmax_ind = -1;
    float lmin_ind = -1;

    for(int i = 0; i < s; i++)
    {
        if(cidades[i].n_acidentes_com_vitimas > lmax_ind)
        {
            lmax_ind = cidades[i].n_acidentes_com_vitimas;
            (*cid_max) = &cidades[i];
            *max_ind = lmax_ind;
        }
        else if(cidades[i].n_acidentes_com_vitimas < lmin_ind)
        {
            lmin_ind = cidades[i].n_acidentes_com_vitimas;
            (*cid_min) = &cidades[i];
            *min_ind = lmin_ind;
        }
    }
}

//b) qual a média de veículos nas cidades portuguesas
float b(struct cidade cidades[], int s)
{
    float acc = 0;
    for(int i = 0; i < s; i++)
    {
        acc += cidades[i].n_veiculos;
    }
    return acc / s;
}

//c) qual a média de acidentes com vítimas nas cidades do distrito do Porto
float c(struct cidade cidades[], int s, char dist[2])
{
    float media_acc_dist = 0;
    int n_cidades = 0;
    for(int i = 0; i < s; i++)
    {
        if(strcmp(cidades[i].dist[], dist) == 0){
            media_acc_dist += cidades[i].n_acidentes_com_vitimas;
            n_cidades++;
        }
    }
    return media_acc_dist/n_cidades;
}

void ex3_23()
{
    struct cidade pais[1000];
    printf("media de veiculos e': %f\n", b(pais, 1000));

    struct cidade *c_max;
    struct cidade *c_min;
    float i_max, i_min;

    a(pais, 1000, &c_max, &i_max, &c_min, &i_min);
    printf("Cidade max: %s ind:%f\n", c_max->codigo, i_max);
    printf("Cidade min: %s ind:%f\n", c_min->codigo, i_min);

    printf("media de acidentes com vitimas e': %f\n", c(pais, 1000, "PT"));
}
