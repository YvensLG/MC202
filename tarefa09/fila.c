#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

no* criar_lista(){
    return NULL;
}

void destruir_lista(no* lista){
    if(lista != NULL){
        destruir_lista(lista -> prox);
        free(lista);
    }
}

fila* criar_fila(){
    fila* f = malloc(sizeof(fila));
    f -> ini = NULL;
    f -> fim = NULL;
    return f;
}

void push(fila* f, int x){
    no* novo = malloc(sizeof(no));
    novo -> dado = x;
    novo -> prox = NULL;
    if(f -> ini == NULL){
        f -> ini = novo;
    }
    else{
        f -> fim -> prox = novo;
    }
    f -> fim = novo;
}

int pop(fila* f){
    no* primeiro = f -> ini;
    int x = f -> ini -> dado;

    f -> ini = f -> ini -> prox;
    if(f -> ini == NULL){
        f -> fim = NULL;
    }
    free(primeiro);
    return x;
}

void destruir_fila(fila* f){
    destruir_lista(f -> ini);
    free(f);
}
