/* função que retorna a posição do coracter separador */
int get_end_of_name(char str[], int len)
{
    int i = 0;
    while(i < len){
        if(str[i] == ' ' || str[i] == 0)
            return i;
        i++;
    }

    return -1;
}

/* esta função separa os nomes, copiandos
 * cada um para uma string diferent */
void ex_16_v2()
{
    char name[] = "Zeferino Pedro Duarte Aguiar";
    int name_size = sizeof(name)/sizeof(name[0]);

    char names_seperated[20][100];

    int curr_pos = 0;
    int name_i = 0;

    do{
        /* string a partir do último nome lido */
        char *name_ptr = &name[curr_pos];
        /* o tamanho do string atual é o tamanho
         * da string menos o que já lemos */
        int curr_size = name_size - curr_pos;
        /* esta função dá-nos o indice onde cada nome acaba */
        int end_of_name = get_end_of_name(name_ptr, curr_size);
        if(end_of_name == -1)
            break;
        /* cada índice é um vetor */
        /* copiar nome encontrado */
        memcpy(names_seperated[name_i++], name_ptr, end_of_name);
        /* adicionamos +1 porque não queremos ler o caracter terminador */
        curr_pos += end_of_name+1;
    } while(curr_pos < name_size);
    /* número de nomes lidos -1 para termos o indice do apelido */
    printf("%s, ",names_seperated[name_i-1]);
    
    /* name_i - 1 porque já lemos o último nome */
    for(int i = 0;i < (name_i-1); i++){
        printf(" %c.", names_seperated[i][0]);
    }
}
