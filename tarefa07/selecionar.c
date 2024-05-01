#include <stdio.h>
#include "heap.h"
#define MAX 21

int main(){
    int tam;
    scanf("%d", &tam);

    //contém todos os elementos do inicio para a metade
    //heap de maximo
    fp* fila1 = criar_filaprio(tam);

    //contém todos os elementos da metade para o final
    //heap de minimo
    fp* fila2 = criar_filaprio(tam);

    for(int i=0; i<tam; i++){
        Item item;
        scanf("%s %d", item.nome, &item.chave);
        
        Item maior1 = fila1 -> v[0];
        Item maior2 = fila2 -> v[0];

        //em qual heap coloca o novo elemento
        if(fila2 -> n > 0 && item.chave > maior2.chave){
            item.chave = -item.chave;
            insere(fila2, item);

            maior2 = extrai_maximo(fila2);
            maior2.chave = -maior2.chave;
            insere(fila1, maior2);
        }else{
            insere(fila1, item);
        }

        //se a diferença dos heaps for 2, passa um elmento pro outro heap
        if(fila1 -> n - fila2 -> n == 2){
            Item maior = extrai_maximo(fila1);
            maior.chave = -maior.chave;
            insere(fila2, maior);
        }

        maior1 = fila1 -> v[0];
        maior2 = fila2 -> v[0];

        //encontra a mediana dependendo do tamanho dos heaps
        if(fila1 -> n == fila2 -> n){
            printf("%s: %d\n", maior1.nome, maior1.chave);
            printf("%s: %d\n", maior2.nome, -maior2.chave);
        }
        else{
            printf("%s: %d\n", maior1.nome, maior1.chave);
        }
    }

    //destroi os heaps
    destruir_filaprio(fila1);
    destruir_filaprio(fila2);
}