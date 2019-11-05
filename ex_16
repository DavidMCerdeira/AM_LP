void ex11_16()
{
    char nome[] = "Zeferino Pedro Duarte Aguiar";

    char apelido[20];
    char iniciais[20];

    /* get apelido */
    int name_size = strlen(nome);
    int i = name_size-1;
    int ap_i = 0;
    while(nome[i] != ' '){
        i--;
    }
    int a = i;
    apelido[name_size-i] = '\0';
    strcpy(apelido, &nome[i+1]);

    /* get iniciais */
    i = 0;
    int in_it = 0;
    for(int j = 1; j < a; j++){
        if(nome[j-1] == ' '){
            iniciais[in_it++] = nome[j];
        } else if(j == 1){
            iniciais[in_it++] = nome[j-1];
        }
    }
    int size_in = in_it;

    /* imprimir */
    printf("%s, ", apelido);
    for(int k = 0; k < size_in; k++){
        printf("%c. ", iniciais[k]);
    }

}
