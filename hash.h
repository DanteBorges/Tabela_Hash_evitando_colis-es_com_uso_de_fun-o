#ifndef HASH_H_INCLUDED
#define MODULO 19

struct universidade
{
    int uninumero;
    char nome[51], nomeprof[21], CNPJ[21], site[21], telefone[21],tipo[21],endereco[21],complemento[21],cidade[21],estado[21],CEP[21];

};typedef struct universidade Universidade;

typedef Universidade* Hash[MODULO];

int hash_(int chave);
void mostrar();
void comecar(Hash tab);
void busca(Hash tab);
Universidade*cadastro();
Universidade* inserir(Hash tab, int uninumero, char* N, char *C, char *NP, char *S, char *T, char *TI, char *END, char *COM, char *CI, char *ES, char *CE);


#endif
