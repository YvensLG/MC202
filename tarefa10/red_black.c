#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "red_black.h"

int ehVermelho(no_rb* x){
    if (x == NULL){
        return 0;
    }
    return x -> cor == VERMELHO;
}

int ehPreto(no_rb* x){
    if (x == NULL){
        return 1;
    }
    return x->cor == PRETO;
}

no_rb* rotaciona_para_esquerda(no_rb* raiz) {
    no_rb* x = raiz->dir;
    raiz->dir = x->esq;
    x->esq = raiz;
    x->cor = raiz->cor;
    raiz->cor = VERMELHO;
    return x;
}

no_rb* rotaciona_para_direita(no_rb* raiz) {
    no_rb* x = raiz->esq;
    raiz->esq = x->dir;
    x->dir = raiz;
    x->cor = raiz->cor;
    raiz->cor = VERMELHO;
    return x;
}

void sobe_vermelho(no_rb* raiz) {
    raiz->cor = VERMELHO;
    raiz->esq->cor = PRETO;
    raiz->dir->cor = PRETO;
}

no_rb* inserir_rec(no_rb* raiz, char* chave, int num) {
    no_rb* novo;
    if (raiz == NULL) {
        novo = malloc(sizeof(no_rb));
        novo->esq = novo->dir = NULL;
        novo->chave = malloc(sizeof(char) * MAX);
        novo->num = num;
        strcpy(novo->chave, chave);
        novo->cor = VERMELHO;
        return novo;
    }

    if (strcmp(chave, raiz->chave) < 0){
        raiz->esq = inserir_rec(raiz->esq, chave, num);
    }
    else{
        raiz->dir = inserir_rec(raiz->dir, chave, num);
    }
    
    if (ehVermelho(raiz->dir) && ehPreto(raiz->esq)){
        raiz = rotaciona_para_esquerda(raiz);
    }
    if (ehVermelho(raiz->esq) && ehVermelho(raiz->esq->esq)){
        raiz = rotaciona_para_direita(raiz);
    }
    if (ehVermelho(raiz->esq) && ehVermelho(raiz->dir)){
        sobe_vermelho(raiz);
    }

    return raiz;
}

no_rb* inserir(no_rb* raiz, char* chave, int num) {
    raiz = inserir_rec(raiz, chave, num);
    raiz->cor = PRETO;
    return raiz;
}

no_rb* buscar(no_rb* raiz, char* chave) {
    while (raiz != NULL && strcmp(chave, raiz->chave) != 0){
        if (strcmp(chave, raiz->chave) < 0){
            raiz = raiz->esq;
        }
        else{
            raiz = raiz->dir;
        }
    }
    return raiz;
}

void destruir_rb(no_rb* raiz){
    if(raiz -> esq != NULL){
        destruir_rb(raiz -> esq);
    }
    if(raiz -> dir != NULL){
        destruir_rb(raiz -> dir);
    }

    free(raiz -> chave);
    free(raiz);
}