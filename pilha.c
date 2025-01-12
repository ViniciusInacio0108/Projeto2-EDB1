#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void init_pilha(Pilha *p) {
    p->topo = -1;
}

int pilha_empty(Pilha *p) {
    return p->topo == -1;
}

int pilha_full(Pilha *p) {
    return p->topo == MAX - 1;
}

Pilha get_pilha(Pilha *p, const char *value) {
    for (int i = 0; i < p->topo; i++)
    {
        if(p->valor[i] == value) {
            return p->valor[i];
        }
    }

    print("Não encontrado!");
}

void pile(Pilha *p, const char *newValue) {
    if (pilha_full(p)) {
        print("Pilha cheia!");
        return;
    }

    p->topo++;
    // alocar com o tamanhbo da linha da mensagem
    p->valor[p->topo] = (char *)malloc(strlen(newValue) + 1);
    if (p->valor[p->topo] != NULL) {
        strcpy(p->valor[p->topo], newValue);
    }
}

void depile(Pilha *p) {
    if (pilha_empty(p)) {
        print("Pilha Vazia!");
        return;  
    }

    free(p->valor[p->topo]);
    p->topo--;
}
