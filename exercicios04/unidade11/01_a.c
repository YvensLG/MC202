#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada.h"

int main () {
    int n, x;
    scanf("%d", &n);
    no* lista;
    lista = criar_lista();

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        lista = adicionar_elemento_ordem(lista , x);
    }
    
    imprime(lista);
    destruir_lista(lista);
    return 0;
}