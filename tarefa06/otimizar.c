#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arvore.h"

int main(){
    //inicia nossa árvore lendo a expressão dada
    no* arv = ler_expressao();

    //otimiza árvore
    otimizar_arvore(arv);

    //imprime
    imprimir_arvore(arv);
    printf("\n");

    destruir_arvore(arv);
}