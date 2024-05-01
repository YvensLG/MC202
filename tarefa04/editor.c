#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista_ligada.h"

int main(){
    no* texto;
    texto = criar_lista();

    while(1){
        char func[9];
        scanf("%s", func);

        if(strcmp(func, "INSERIR") == 0){
            int n;
            char c[130];
            scanf("%d", &n);
            scanf(" '%[^']'", c);
            
            if(texto == NULL){
                texto = adicionar_elemento(texto, c);
            }
            else{
                insere(texto, c, n);
            }
        }

        else if(strcmp(func, "DESTACAR") == 0){
            int n, m;
            scanf("%d %d", &n, &m);
            destacar(texto, n, m);
        }

        else{
            imprime(texto);
            destruir_lista(texto);
            break;
        }
    }

    return 0;
}