#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arvore.h"
#define MAX 11

int main(){
    char chave[MAX];
    char sinal;
    no_rb* conjunto = NULL;

    //enquanto lemos variáveis
    while(scanf("%s ", chave) != EOF){
        //se o sinal após a variável não é um '=', o laço acaba
        scanf("%c ", &sinal);
        if(sinal != '='){
            break;
        }
        
        //cria uma árvore que representará a expressão da variável
        no* arv = ler_expressao();

        //insere a variável e sua expressão em um conjunto (red-black tree)
        conjunto = inserir(conjunto, chave, arv);
    }

    //busca a árvore da última variável (a que queremos achar o valor)
    no* arv = buscar(conjunto, chave) -> arv;

    //encontra o valor e imprime
    remove_variaveis(arv, conjunto);
    printf("%s\n", arv -> dado);

    //destroi a red-black
    destruir_rb(conjunto);
}