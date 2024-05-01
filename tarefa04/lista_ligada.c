#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista_ligada.h"

no* criar_lista (){
    return NULL;
}

no* criar_no(char* txt, int n, no* next){
    no* novo = malloc(sizeof(no));

    novo -> dado = malloc(sizeof(char) * (strlen(txt) + 1));
    strcpy(novo -> dado, txt);

    novo -> negrito = n;

    novo -> prox = next;

    return novo;
}

void destruir_lista(no* lista) {
    no* atual = lista;
    no* next;
    while(1){
        next = atual -> prox;
        free(atual -> dado);
        free(atual);
        if(next != NULL){
            atual = next;
        }
        else{
            break;
        }
    }
}

void insere(no* texto, char* txt, int n){
    //insere no inicio (sempre tem pelo menos um elemento na lista)
    if(n == 0){
        char* tex = malloc( sizeof(char) * (strlen(txt) + strlen(texto -> dado) + 1) );
        strcpy(tex, txt);
        strcat(tex, texto -> dado);
        free(texto -> dado);

        texto -> dado = tex;
        return;
    }

    //posicao relativa do texto completo
    int pos = 0;

    // nó que iremos inserir 

    // acha onde iremos inserir o nó
    for(no* atual = texto; atual != NULL; atual = atual -> prox){
        char* txt_atual = atual -> dado;
        int tam = strlen(txt_atual);

        // passou do ponto
        if (pos >= n){
            break;
        }

        // nao achou
        else if(pos + tam < n);

        // achou e está no fim do intervalo
        else if(pos + tam == n){
            no* novo = criar_no(txt, 0, atual -> prox);
            atual -> prox = novo;

            if(novo -> prox != NULL){    
                unir_no(novo, novo -> prox);
            }else{
                unir_no(atual, novo);
            }
        }
        
        // achou e não está no fim do intervalo
        else{
            char* txt1 = malloc(sizeof(char) * (n - pos + 1));
            char* txt2 = malloc(sizeof(char) * (tam + pos - n + 1));

            for(int i=0; i < n-pos; i++){
                txt1[i] = txt_atual[i];
            }
            txt1[n-pos] = '\0';

            for(int i=0; i < tam + pos - n; i++){
                txt2[i] = txt_atual[n-pos+i];
            }
            txt2[tam+pos-n] = '\0';

            no* atual2 = criar_no(txt2, atual -> negrito, atual -> prox);
            free(txt2);
            
            no* novo = criar_no(txt, atual -> negrito, atual2);
            
            free(atual -> dado); 
            atual -> dado = txt1;
            atual -> prox = novo;
            
            unir_no(atual, novo);
            unir_no(atual, atual2);
        }
        
        pos += tam;
    }
    return;
}

void destacar(no* texto, int n, int m){
    //posicao relativa do texto completo
    int pos = 0;

    //nó anterior ao atual (como o primeiro nao tem anterior, começamos com NULL)
    no* ant = NULL;

    for(no* atual = texto; atual != NULL; atual = atual -> prox){
        char* txt_atual = atual -> dado;
        int tam = strlen(txt_atual);

        //se o intervalo passou do último ponto destacado
        if(pos >= m){
            break;
        }

        //se ainda não estamos em um intervalo que será destacado
        else if(pos + tam <= n);

        //se o intervalo de atual ta contido em [n, m), tudo será destacado
        else if(pos + tam - 1 < m && pos >= n){
            atual -> negrito = 1;
            if(ant != NULL && ant -> negrito == 1){
                unir_no(ant, atual);
            }
        }

        //se o intervalo atual contem [n, m), so o meio será destacado
        else if(pos + tam - 1 >= m && pos < n){
            if(atual -> negrito != 1){
                char* txt1 = malloc(sizeof(char) * (n - pos + 1));
                char* txt2 = malloc(sizeof(char) * (m - n + 1));
                char* txt3 = malloc(sizeof(char) * (tam - m + pos + 1));

                int i = 0;
                for(; i < n-pos; i++){
                    txt1[i] = txt_atual[i];
                }
                txt1[i] = '\0';

                for(; i < m - pos; i++){
                    txt2[i - (n - pos)] = txt_atual[i];
                }
                txt2[i - (n - pos)] = '\0';

                for(; i < tam; i++){
                    txt3[i - (m - pos)] = txt_atual[i];
                }
                txt3[i - (m - pos)] = '\0';

                no* atual2 = criar_no(txt3, 0, atual -> prox);
                no* novo = criar_no(txt2, 1, atual2);

                free(txt3);
                free(txt2);
                free(txt_atual);

                atual -> dado = txt1;
                atual -> prox = novo;
            }
        }

        //se somente m esta no intervalo
        else if(pos + tam - 1 >= m && pos >= n){
            if(atual -> negrito != 1){
                char* txt1 = malloc(sizeof(char) * (m - pos + 1));
                char* txt2 = malloc(sizeof(char) * (pos + tam - m + 1));

                int i = 0;
                for(; i < m-pos; i++){
                    txt1[i] = txt_atual[i];
                }
                txt1[i] = '\0';

                for(; i < tam; i++){
                    txt2[i - (m - pos)] = txt_atual[i];
                }
                txt2[tam + pos - m] = '\0';

                no* novo = criar_no(txt2, 0, atual -> prox);

                free(txt_atual);
                free(txt2);

                atual -> dado = txt1;
                atual -> negrito = 1;
                atual -> prox = novo;
        
                if(ant != NULL && ant -> negrito == 1){
                    unir_no(ant, atual);
                    atual = ant; //variavel do for
                }
            }
        }

        //se somente n esta no intervalo
        else if(pos + tam - 1 < m && pos < n){
            if(atual -> negrito != 1){
                char* txt1 = malloc(sizeof(char) * (n - pos + 1));
                char* txt2 = malloc(sizeof(char) * (pos + tam - n + 1));

                int i = 0;
                for(; i < n-pos; i++){
                    txt1[i] = txt_atual[i];
                }
                txt1[i] = '\0';

                for(; i < tam; i++){
                    txt2[i - (n - pos)] = txt_atual[i];
                }
                txt2[tam + pos - n] = '\0';
                
                no* novo = criar_no(txt2, 1, atual -> prox);
                
                free(txt_atual);
                free(txt2);
                
                atual -> dado = txt1;
                atual -> negrito = 0;
                atual -> prox = novo;

                atual = novo; //variavel do for

                //talvez juntemos com o proximo elemento
                if(pos + tam == m){
                    if(atual -> prox != NULL && atual -> prox -> negrito == 1){
                        unir_no(atual, atual -> prox);
                    }
                }
            }
        }

        pos += tam;
        ant = atual;
    }
    return;
}

no* adicionar_elemento (no* lista , char* x) {
    no* novo;
    novo = malloc(sizeof(no));
    novo -> dado = malloc(sizeof(char) * (strlen(x) + 1));
    strcpy(novo -> dado, x); 
    novo -> negrito = 0;
    novo -> prox = lista;
    return novo;
}

void imprime(no* lista) {
    no* atual;
    for (atual = lista; atual != NULL; atual = atual -> prox){
        if(atual -> negrito == 0){
            printf("NORMAL '");
        }else{
            printf("NEGRITO '");
        }

        printf("%s'\n\n", atual -> dado);
    }
    printf("\n");
}

void unir_no(no* no1, no* no2){
    no1 -> prox = no2 -> prox;
    char* txt1 = no1 -> dado;
    char* txt2 = no2 -> dado;

    char* subs = malloc(sizeof(char) * (strlen(txt1) + strlen(txt2) + 1));
    strcpy(subs, txt1);
    strcat(subs, txt2);

    free(txt1);
    no1 -> dado = subs;
    
    free(txt2);
    
    free(no2);
}