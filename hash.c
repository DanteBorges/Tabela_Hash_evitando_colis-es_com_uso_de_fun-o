#include<stdio.h>
#include<stdlib.h>
#include "hash.h"

Hash tab;


void opcoes()
{
    system("cls");
    printf(" ====== CADASTRO DE UNIVERSIDADES ======\n");
    printf("1 - INSERIR UNIVERSIDADES\n");
    printf("2 - LISTA DE UNIVERSIDADES\n");
    printf("3 - PESQUISA \n");
    printf("4 - EXIT\n");

}

void menu()
{
    int opcao, key;
    opcoes();

    printf("ESCOLHA UMA OPCAO: ");
    scanf("%d", &opcao);

    while(opcao < 1 || opcao > 4)
    {
        opcoes();
        printf("ESCOLHA UMA OPCAO VALIDA: ");
        scanf("%d", &opcao);
    }

    switch(opcao)
    {
    case 1:
       cadastro();
        break;
    case 2:
        mostrar(tab);
        break;
    case 3:
       comparar(tab);
        break;
    case 4:
        exit(1);
    }
    menu();
}


int hash_(int chave)
{
    return chave%MODULO;
}

void comecar(Hash tab)
{
    int i;
    for(i=0; i<MODULO; i++)
    {
        tab[i] = NULL;
    }
}

void mostrar(Hash tab)
{
    system("cls");
    int i;
    for(i=0; i<MODULO; i++)
    {
        if(tab[i] != NULL)
        {
            printf("Posicao: %03d\n", i);
            printf("    N. Do Cadastro: %06d\n", tab[i] -> uninumero);
            printf("    Nome Da Universidade: %s\n", tab[i] -> nome);
            printf("    Nome do Professor Mentor: %s\n", tab[i] -> nomeprof);
            printf("    CNPJ: %s\n", tab[i] -> CNPJ);
            printf("    Site da Instituicao: %s\n", tab[i] -> site);
            printf("    Telefone: %s\n", tab[i] -> telefone);
            printf("    Tipo: %s\n", tab[i] -> tipo);
            printf("    Endereco: %s\n", tab[i] -> endereco);
            printf("    Complemento: %s\n", tab[i] -> complemento);
            printf("    Cidade: %s\n", tab[i] -> cidade);
            printf("    Estado: %s\n", tab[i] -> estado);
            printf("    CEP: %s\n", tab[i] -> CEP);
            printf("\n");
        }
    }
    system("pause");
}

Universidade* inserir(Hash tab,int numero, char* N, char *C, char *NP, char *S, char *T, char *TI, char *END, char *COM, char *CI, char *ES, char *CE)
{
    int h = hash_(numero);
    while(tab[h] != NULL)
    {
        if(tab[h]->uninumero == numero)
            break;
        h=(h*2)%MODULO;
    }
    if(tab[h] == NULL)
    {
        tab[h] = (Universidade*)malloc(sizeof(Universidade));
        tab[h] -> uninumero = numero;
    }
    strcpy(tab[h]->nome, N);
    strcpy(tab[h]->CNPJ, C);
    strcpy(tab[h]->nomeprof, NP);
    strcpy(tab[h]->site, S);
    strcpy(tab[h]->telefone, T);
    strcpy(tab[h]->tipo, TI);
    strcpy(tab[h]->endereco, END);
    strcpy(tab[h]->complemento, COM);
    strcpy(tab[h]->cidade, CI);
    strcpy(tab[h]->estado, ES);
    strcpy(tab[h]->CEP, CE);

    return tab[h];
}

void busca(Hash tab)
{
    int key;
    system("cls");
    printf("DIGITE O N. DO CADASTRO: ");
    scanf("%d", &key);
    system("cls");
    int h = hash_(key);
    while(tab[h] != NULL)
    {
        if(tab[h]->uninumero == key)
            break;
        h=(h*2)%MODULO;
    }
    if(tab[h] != NULL)
    {
        printf("Posicao: %03d\n", h);
        printf("    N. Do Cadastro: %06d\n", tab[h] -> uninumero);
        printf("    Nome Da Universidade: %s\n", tab[h] -> nome);
        printf("    Nome do Professor Mentor: %s\n", tab[h] -> nomeprof);
        printf("    CNPJ: %s\n", tab[h] -> CNPJ);
        printf("    Site da Instituicao: %s\n", tab[h] -> site);
        printf("    Telefone: %s\n", tab[h] -> telefone);
        printf("    Tipo: %s\n", tab[h] -> tipo);
        printf("    Endereco: %s\n", tab[h] -> endereco);
        printf("    Complemento: %s\n", tab[h] -> complemento);
        printf("    Cidade: %s\n", tab[h] -> cidade);
        printf("    Estado: %s\n", tab[h] -> estado);
        printf("    CEP: %s\n", tab[h] -> CEP);
        printf("\n\n");
    }
    else
    {
        printf("REGISTRO NAO ENCONTRADO!\n");

    }
    system("pause");
}

Universidade*cadastro()
{

    int uninumero;
    char nome[51], nomeprof[21], CNPJ[21], site[21], telefone[21],tipo[21],endereco[21],complemento[21],cidade[21],estado[21],CEP[21];
    system("cls");
    printf("DIGITE O NUMERO DO CADASTRO DA UNIVERSIDADE:     ");
    scanf("%d", &uninumero);
    setbuf(stdin, NULL);
    printf("DIGITE O NOME DA UNIVERSIDADE:     ");
    scanf("%[^\n]s", nome);
    setbuf(stdin, NULL);
    printf("DIGITE O NOME DO PROFESSOR MENTOR:      ");
    scanf("%[^\n]s", nomeprof);
    setbuf(stdin, NULL);
    printf("DIGITE O CNPJ DA UNIVERSIDADE:       ");
    scanf("%[^\n]s", CNPJ);
    setbuf(stdin, NULL);
    printf("DIGITE O SITE DA UNIVERSIDADE:       ");
    scanf("%[^\n]s", site);
    setbuf(stdin, NULL);
    printf("DIGITE O TELEFONE DA UNIVERSIDADE: ");
    scanf("%[^\n]s", telefone);
    setbuf(stdin, NULL);
    printf("DIGITE O TIPO DA UNIVERSIDADE: ");
    scanf("%[^\n]s", tipo);
    setbuf(stdin, NULL);
    printf("DIGITE O ENDERECO DA UNIVERSIDADE: ");
    scanf("%[^\n]s", endereco);
    setbuf(stdin, NULL);
    printf("DIGITE O COMPLEMENTO: ");
    scanf("%[^\n]s", complemento);
    setbuf(stdin, NULL);
    printf("DIGITE A CIDADE AONDE A UNIVERSIDADE SE LOCALIZA: ");
    scanf("%[^\n]s", cidade);
    setbuf(stdin, NULL);
    printf("DIGITE O ESTADO AONDE A UNIVERSIDADE SE LOCALIZA: ");
    scanf("%[^\n]s", estado);
    setbuf(stdin, NULL);
    printf("DIGITE CEP: ");
    scanf("%[^\n]s", CEP);
    setbuf(stdin, NULL);

    inserir(tab, uninumero, nome, nomeprof, CNPJ, site, telefone,tipo,endereco,complemento,cidade,estado,CEP);
    system("cls");
    printf("UNIVERSIDADE CADASTRADA COM SUCESSO\n");
    system("pause");
}

void pesquisaSequencial(Hash tab)
{
    int key, i;
    system("cls");
    printf("DIGITE O N. DO CADASTRO: ");
    scanf("%d", &key);
    system("cls");

    for(i=0; i<MODULO; i++)
    {
        if(tab[i] != NULL)
        {
            if(tab[i] -> uninumero == key)
            {
                printf("    N. Do Cadastro: %06d\n", tab[i] -> uninumero);
                printf("    Nome Da Universidade: %s\n", tab[i] -> nome);
                printf("    Nome do Professor Mentor: %s\n", tab[i] -> nomeprof);
                printf("    CNPJ: %s\n", tab[i] -> CNPJ);
                printf("    Site da Instituicao: %s\n", tab[i] -> site);
                printf("    Telefone: %s\n", tab[i] -> telefone);
                printf("    Tipo: %s\n", tab[i] -> tipo);
                printf("    Endereco: %s\n", tab[i] -> endereco);
                printf("    Complemento: %s\n", tab[i] -> complemento);
                printf("    Cidade: %s\n", tab[i] -> cidade);
                printf("    Estado: %s\n", tab[i] -> estado);
                printf("    CEP: %s\n", tab[i] -> CEP);
                printf("\n\n");
                system("pause");
                return;
            }
        }
    }
    printf("REGISTRO NAO ENCONTRADO!\n\n");
    system("pause");
}

void comparar(Hash tab)
{
    int i, key, oti=0;
    system("cls");
    printf("DIGITE O N. DO CADASTRO: ");
    scanf("%d", &key);
    system("cls");

    //SEQUENCIAL: VALOR DE I
    for(i=0; i<MODULO; i++)
    {
        if(tab[i] != NULL)
        {
            if(tab[i] -> uninumero == key)
            {
                break;
            }
        }
    }

    //OTIMIZADA: tab[h]
    int h = hash_(key);
    while(tab[h] != NULL)
    {
        if(tab[h]->uninumero == key)
        {
            break;
        }
        oti++;
        h=(h*2)%MODULO;
    }
    oti++;

    if(tab[h] != NULL)
    {
        printf("Posicao: %03d\n", h);
        printf("    N. Do Cadastro: %06d\n", tab[i] -> uninumero);
        printf("    Nome Da Universidade: %s\n", tab[i] -> nome);
        printf("    Nome do Professor Mentor: %s\n", tab[i] -> nomeprof);
        printf("    CNPJ: %s\n", tab[i] -> CNPJ);
        printf("    Site da Instituicao: %s\n", tab[i] -> site);
        printf("    Telefone: %s\n", tab[i] -> telefone);
        printf("    Tipo: %s\n", tab[i] -> tipo);
        printf("    Endereco: %s\n", tab[i] -> endereco);
        printf("    Complemento: %s\n", tab[i] -> complemento);
        printf("    Cidade: %s\n", tab[i] -> cidade);
        printf("    Estado: %s\n", tab[i] -> estado);
        printf("    CEP: %s\n", tab[i] -> CEP);
        printf("\n\n");

    }

    else
    {
        printf("CADASTRO NAO ENCONTRADO!\n");
    }

    system("pause");
}
