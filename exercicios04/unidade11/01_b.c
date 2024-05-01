#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada.h"

int main () {
    int n, m, x;
    no* lista1;
    lista1 = criar_lista();
    
    no* lista2;
    lista2 = criar_lista();

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        lista1 = adicionar_elemento(lista1 , x);
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &x);
        lista2 = adicionar_elemento(lista2 , x);
    }
    
    no* lista = uniao(lista1, lista2);

    imprime(lista);
    destruir_lista(lista);
    destruir_lista(lista1);
    destruir_lista(lista2);
    return 0;
}