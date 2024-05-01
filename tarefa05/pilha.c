#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

no* criar_lista(){
    return NULL;
}

pilha* criar_pilha(){
    no* vazio = criar_lista();
    pilha* p = malloc(sizeof(pilha));
    p -> topo = vazio;
    return p;
}

void push(pilha* p, int x){
    no* novo = malloc(sizeof(no));
    novo -> dado = x;
    novo -> prox = p -> topo;
    p -> topo = novo;
}

int pop(pilha* p){
    no* top = p -> topo;
    int x = top -> dado;
    p -> topo = p -> topo -> prox;
    free(top);
    return x;
}

void destruir_pilha(pilha* p){
    while(p -> topo != NULL){
        pop(p);
    }
    free(p -> topo);
    free(p);
}