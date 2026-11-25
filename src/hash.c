#include <stdio.h>
#include <stdlib.h>

/* Se o professor já fornece hash.h, apague estas definições e use o .h */
typedef struct No {
    int matricula;
    int pos;            /* posição do aluno no vetor */
    struct No *prox;
} No;

typedef struct {
    No **tab;           /* vetor de m listas */
    int m;              /* tamanho (primo) */
} Hash;

/* Método da divisão */
int hash_funcao(int chave, int m) {
    return chave % m;
}

/* Cria a tabela com m listas vazias */
Hash *hash_cria(int m) {
    Hash *h = malloc(sizeof(Hash));
    if (!h) return NULL;
    h->m = m;
    h->tab = calloc(m, sizeof(No *));   /* tudo NULL */
    if (!h->tab) { free(h); return NULL; }
    return h;
}

/* Insere no início da lista */
void hash_insere(Hash *h, int matricula, int pos) {
    int i = hash_funcao(matricula, h->m);
    No *novo = malloc(sizeof(No));
    if (!novo) return;
    novo->matricula = matricula;
    novo->pos = pos;
    novo->prox = h->tab[i];
    h->tab[i] = novo;
}

/* Devolve a posição no vetor ou -1. Soma 1 em *comparacoes por nó visitado */
int hash_busca(Hash *h, int matricula, long *comparacoes) {
    int i = hash_funcao(matricula, h->m);
    for (No *p = h->tab[i]; p != NULL; p = p->prox) {
        (*comparacoes)++;
        if (p->matricula == matricula)
            return p->pos;
    }
    return -1;
}

/* Tamanho da maior lista da tabela */
int hash_maior_lista(Hash *h) {
    int maior = 0;
    for (int i = 0; i < h->m; i++) {
        int tam = 0;
        for (No *p = h->tab[i]; p != NULL; p = p->prox)
            tam++;
        if (tam > maior) maior = tam;
    }
    return maior;
}

/* Libera todos os nós e a tabela */
void hash_libera(Hash *h) {
    if (!h) return;
    for (int i = 0; i < h->m; i++) {
        No *p = h->tab[i];
        while (p != NULL) {
            No *prox = p->prox;
            free(p);
            p = prox;
        }
    }
    free(h->tab);
    free(h);
}
