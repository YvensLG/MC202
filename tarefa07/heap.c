#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "heap.h"

#define PAI(i) ((i-1)/2) //Pai de i
#define F_ESQ(i) (2*i+1) //Filho esquerdo de i
#define F_DIR(i) (2*i+2) //Filho direito de i

void troca(Item* a, Item* b){
    Item t = *a;
    *a = *b;
    *b = t;
}

fp* criar_filaprio(int tam){
    fp* fprio = malloc(sizeof(fp));
    fprio -> v = malloc(tam * sizeof(Item));
    fprio -> n = 0;
    fprio -> tamanho = tam;
    return fprio;
}

void destruir_filaprio(fp* fprio){
    free(fprio -> v);
    free(fprio);
}

void insere(fp* fprio, Item item){
    fprio -> v[fprio -> n] = item;
    fprio -> n++;
    sobe_no_heap(fprio, fprio -> n - 1);
}

void sobe_no_heap(fp* fprio, int k){
    if (k > 0 && fprio -> v[PAI(k)].chave < fprio -> v[k].chave) {
        troca(&fprio -> v[k], &fprio -> v[PAI(k)]);
        sobe_no_heap(fprio, PAI(k));
    }
}

Item extrai_maximo(fp* fprio){
    Item item = fprio -> v[0];
    troca(&fprio -> v[0], &fprio -> v[fprio -> n - 1]);
    fprio -> n--;
    desce_no_heap(fprio, 0);
    return item;
}

void desce_no_heap(fp* fprio, int k) {
    int maior_filho;
        if (F_ESQ(k) < fprio->n) {
            maior_filho = F_ESQ(k);
        
        if (F_DIR(k) < fprio->n &&
            fprio -> v[F_ESQ(k)].chave < fprio -> v[F_DIR(k)].chave)
            maior_filho = F_DIR(k);
        
        if (fprio -> v[k].chave < fprio -> v[maior_filho].chave) {
            troca(&fprio -> v[k], &fprio -> v[maior_filho]);
            desce_no_heap(fprio, maior_filho);
        }
    }
}

