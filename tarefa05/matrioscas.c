#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    int n, x;
    int valido = 1;
    scanf("%d", &n);
    pilha* p = criar_pilha();
    
    //guarda otamanho de cada boneca
    int* tam = malloc(sizeof(int) * (n+1));

    //guarda se uma boneca já foi analisada
    int* feito = malloc(sizeof(int) * (n+1));

    //guarda o peso de cada boneca
    int* peso = malloc(sizeof(int) * (n+1));
    
    for(int i = 0; i <= n; i++){
        tam[i] = 0;
        feito[i] = 0;
        peso[i] = 0;
    }

    while(scanf("%d", &x) != EOF){
        //boneca termina
        if(x < 0){
            //boneca termina corretamente
            if(p -> topo != NULL && p -> topo -> dado == -x){
                //atualiza feito, tam e peso
                int t = pop(p);
                feito[t] = 1;
                
                if(p -> topo != NULL){
                    int k = p -> topo -> dado;
                    if(!feito[k]){
                        tam[k] ++;
                        peso[k] += t;
                    }
                }
            }
            //boneca não termina corretamente
            else{
                valido = 0;
            }
        }

        //boneca inicia
        else{
            push(p, x);
        }
    }


    //se a pilha não ficou vazia no fim do processamento
    if(p -> topo != NULL){
        valido = 0;
    }
    
    //se alguma boneca não tem o peso certo
    for(int i = 1; i <= n; i++){
        if(peso[i] != i-1 && peso[i] != 0){
            valido = 0;
        }
    }

    //imprime o pedido no problema
    if(!valido){
        printf("sequencia invalida\n");
    }
    else{
        for(int i = 1; i <= n; i++){
            if(feito[i]){
                printf("%d contem %d bonecas\n", i, tam[i]);
            }
        }
    }

    //desaloca memoria
    destruir_pilha(p);
    free(tam);
    free(feito);
    free(peso);
    return 0;
}