#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arvore.h"
#define MAX 11
#define MOD 256

no* criar_arvore(no* pai){
    no* arv;
    arv = malloc(sizeof(no));

    arv -> dado = malloc(sizeof(char) * MAX);
    arv -> esq = NULL;
    arv -> dir = NULL;
    arv -> pai = pai;

    return arv;
}

no* ler_expressao(){
    char c[MAX];
    no* arv = criar_arvore(NULL);

    //lendo a expressão
    while(scanf(" %s", c) != EOF){
        if(strcmp(c, ";") == 0){
            break;
        }
        //se abriu um parênteses, criamos um filho na esquerda
        else if(strcmp(c, "(") == 0){
            no* novo = criar_arvore(arv);
            arv -> esq = novo;
            arv = novo;
        }
        
        //se fechou um parênteses, voltamos para o pai
        else if(strcmp(c, ")") == 0){
            arv = arv -> pai;
        }

        //se recebe uma operação, volta pro pai, atualiza seus dados, e criamos um filho na direita
        else if(strcmp(c, "+") == 0 || strcmp(c, "-") == 0 || strcmp(c, "*") == 0 || strcmp(c, "/") == 0){
            arv = arv -> pai;
            strcpy(arv -> dado, c);

            no* novo = criar_arvore(arv);
            arv -> dir = novo;
            arv = novo;
        }

        //se recebe um número, atualiza os dados do nó atual
        else{
            strcpy(arv -> dado, c);
        }            
    }
    return arv;
}

void destruir_arvore(no* arv){
    if(arv -> esq != NULL){
        destruir_arvore(arv -> esq);
    }
    if(arv -> dir != NULL){
        destruir_arvore(arv -> dir);
    }

    free(arv -> dado);
    free(arv);
}

void imprimir_arvore(no* arv){
    if(arv == NULL){
        return;
    }

    char* c = arv -> dado;
    int b = (strcmp(c, "+") == 0 || strcmp(c, "-") == 0 || strcmp(c, "*") == 0 || strcmp(c, "/") == 0);

    //se for uma operação, imprime o parênteses
    if(b){
        printf("( ");
    }
    
    imprimir_arvore(arv -> esq);

    printf("%s ", arv -> dado);

    imprimir_arvore(arv -> dir);
    
    //se for uma operação, imprime o parênteses
    if(b){
        printf(") ");
    }
}

void otimizar_arvore(no* arv){
    //não tem como otimizar
    if(arv == NULL || arv -> esq == NULL || arv -> dir == NULL){
        return;
    }

    //otimiza recursivamente
    otimizar_arvore(arv -> esq);
    otimizar_arvore(arv -> dir);

    //se o dado da arvore esquerda nao e um numero, para
    int e = atoi(arv -> esq -> dado);
    if(e == 0 && strcmp(arv -> esq -> dado, "0") != 0){
        return;
    }

    //se o dado da arvore direita nao e um numero, para
    int d = atoi(arv -> dir -> dado);
    if(d == 0 && strcmp(arv -> dir -> dado, "0") != 0){
        return;
    }

    //números positivos
    e = (e + MOD) % MOD;
    d = (d + MOD) % MOD;

    char* c = arv -> dado;
    int b = (strcmp(c, "+") == 0 || strcmp(c, "-") == 0 || strcmp(c, "*") == 0 || strcmp(c, "/") == 0);

    //c recebe o número da operação
    if(strcmp(c, "+") == 0){
        sprintf(c, "%d", (e + d) % MOD);
    }
    else if(strcmp(c, "-") == 0){
        sprintf(c, "%d", (e + (MOD - d)) % MOD);
    }
    else if(strcmp(c, "*") == 0){
        sprintf(c, "%d", (e * d) % MOD);
    }
    else if(strcmp(c, "/") == 0){
        sprintf(c, "%d", (e / d) % MOD);
    }

    //se c recebeu um novo número, apagamos as árvores da esquerda e da direita
    if(b){
        destruir_arvore(arv -> esq);
        arv -> esq = NULL;

        destruir_arvore(arv -> dir);
        arv -> dir = NULL;
    }
}

// red black:

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

no_rb* inserir_rec(no_rb* raiz, char* chave, no* arv) {
    no_rb* novo;
    if (raiz == NULL) {
        novo = malloc(sizeof(no_rb));
        novo->esq = novo->dir = NULL;
        novo->chave = malloc(sizeof(char) * MAX);
        strcpy(novo->chave, chave);
        novo->cor = VERMELHO;
        novo->arv = arv;
        return novo;
    }

    if (strcmp(chave, raiz->chave) < 0){
        raiz->esq = inserir_rec(raiz->esq, chave, arv);
    }
    else{
        raiz->dir = inserir_rec(raiz->dir, chave, arv);
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

no_rb* inserir(no_rb* raiz, char* chave, no* arv) {
    raiz = inserir_rec(raiz, chave, arv);
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

void remove_variaveis(no* arv, no_rb* conjunto){
    //sem variáveis
    if(arv == NULL){
        return;
    }

    //remove recursivamente
    remove_variaveis(arv -> esq, conjunto);
    remove_variaveis(arv -> dir, conjunto);

    char* c = arv -> dado;
    int b = (strcmp(c, "+") == 0 || strcmp(c, "-") == 0 || strcmp(c, "*") == 0|| strcmp(c, "/") == 0 ||
             strcmp(c, "(") == 0 || strcmp(c, ")") == 0);
    int d = atoi(c);

    //se o que está armazenado na arvore é uma variável
    if(d == 0 && strcmp(c, "0") != 0 && !b){
        //acha a árvore que representa a expressão dessa variável
        no* arv2 = buscar(conjunto, c) -> arv;

        //remove as variáveis dessa árvore
        remove_variaveis(arv2, conjunto);

        //substitui o número achado pela variável
        strcpy(arv -> dado, arv2 -> dado);
    }

    //otimiza para sobrar só um número
    otimizar_arvore(arv);
}

void destruir_rb(no_rb* raiz){
    if(raiz -> esq != NULL){
        destruir_rb(raiz -> esq);
    }
    if(raiz -> dir != NULL){
        destruir_rb(raiz -> dir);
    }

    free(raiz -> chave);
    destruir_arvore(raiz -> arv);
    free(raiz);
}