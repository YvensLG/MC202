#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada.h"

no* criar_lista (){
    return NULL;
}

void destruir_lista(no* lista) {
    no* atual = lista;
    no* next;
    while(1){
        next = atual -> prox;
        free(atual);
        if(next != NULL){
            atual = next;
        }
        else{
            break;
        }
    }
}

no* adicionar_elemento (no* lista , int x) {
    no* novo;
    novo = malloc(sizeof(no));
    novo -> dado = x;
    novo -> prox = lista;
    return novo;
}

no* adicionar_elemento_ordem (no* lista , int x) {
    if(lista == NULL){
        return adicionar_elemento(lista, x);
    }
    no* novo;
    novo = malloc(sizeof(no));
    novo -> dado = x;
    if(lista -> dado > x){
        novo -> prox = lista;
        return novo; 
    }

    no* atual = lista;
    no* next;
    while(1){
        next = atual -> prox;
        if(next == NULL || next -> dado > x){
            atual -> prox = novo;
            novo -> prox = next;
            return lista;
        }
        atual = atual -> prox;
    }
}

int esta_na_lista(int n, no* lista){
    for(no* atual = lista; atual != NULL; atual = atual -> prox){
        if(n == atual -> dado){
            return 1;
        }
    }
    return 0;
}

/*
uniao em O((m + n)^2), pois olhamos cada elemento e vemos se já está ou não na lista
no pior caso, nunca está, onde a complexidade dá (m+n)^2
*/

no* uniao (no* lista1 , no* lista2) {
    no* lista;
    lista = criar_lista();
    for(no* atual = lista1; atual != NULL; atual = atual -> prox){
        if(!esta_na_lista(atual -> dado, lista)){
            lista = adicionar_elemento(lista, atual -> dado);
        }
    }

    for(no* atual = lista2; atual != NULL; atual = atual -> prox){
        if(!esta_na_lista(atual -> dado, lista)){
            lista = adicionar_elemento(lista, atual -> dado);
        }
    }

    return lista;
}

/*
uniao em O(m + n), pois olhamos cada elemento das duas listas
e colocamos em ordem na nova lista (como ja está em ordem, não precisamos checar se ja foi colocado)
*/

no* uniao_ordenada (no* lista1 , no* lista2) {
    no* lista = criar_lista();
    lista = adicionar_elemento(lista, 0);
    no* a = lista;

    no* atual1 = lista1;
    no* atual2 = lista2;
    no* ant;
    ant = malloc(sizeof(no));
    
    while(1){
        no* b;
        b = malloc(sizeof(no));
        if(atual1 == NULL && atual2 == NULL){
            ant->prox = a->prox;
            free(a);
            free(b);
            break;
        }

        ant = a;
        if(atual1 == NULL || (atual2 != NULL && atual1->dado > atual2->dado)){
            a->dado = atual2->dado;
            b->prox = a->prox;
            a->prox = b;
            a = b;
            atual2 = atual2->prox;
        }
        else if(atual2 == NULL || atual1->dado < atual2->dado){
            a->dado = atual1->dado;
            b->prox = a->prox;
            a->prox = b;
            a = b;
            atual1 = atual1->prox;
        }
        else{
            a->dado = atual2->dado;
            b->prox = a->prox;
            a->prox = b;
            a = b;
            atual2 = atual2->prox;
            atual1 = atual1->prox;
        }
    }

    return lista;
}

void imprime(no* lista) {
    no* atual;
    for (atual = lista; atual != NULL; atual = atual -> prox){
        printf("%d ", atual -> dado);
    }
    printf("\n");
}
