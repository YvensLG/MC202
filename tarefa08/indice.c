#include "indice.h"
#include "utils.h"

#include <string.h>
#include <assert.h>
#include <stdlib.h>

//modulo primo usado no hash
#define MOD 10000019

/*
Utilizei uma lista ligada que contém vários períodos do texto

prox (p_no_hash) é o ponteiro que aponta para o próximo período
ant (p_no_hash) é o ponteiro que aponta para o período anterior
str (char*) é a string que contém o período
n (int) é um número auxiliar que evita repetição de períodos na lista
*/

typedef struct no_hash *p_no_hash;

struct no_hash {
    p_no_hash prox;
    p_no_hash ant;
    char *str;
    int n;
};

/*
A estrutura indice contém um vetor com a quantidade de elementos igual ao máximo que um hash pode ter.
na lista_hash[i] são guardados todos os períodos que contém uma palavra de hash i.
*/

struct indice {
    p_no_hash lista_hash[MOD];
};

/*
Função de hashing utilizando o método de divisão para uma string
Escolhi esse método pois acredito ser o mais prático
E escolhendo um primo relativamente grande, a chance de terem palavras com o mesmo hash são mínimas

Parâmetros:
    s (char*) a string a ser transformada em inteiro
*/

int hash(char* s){
    int x = 0;
    for(int i=0; i<strlen(s); i++){
        x = (x * 256 + s[i]) % MOD;
    }
    return (x + MOD) % MOD;
}

/*
Função que cria o nó de uma lista ligada p_no_hash

Parâmetros:
    s (char*) a string guardada no nó
    a (int) o inteiro que representa o período guardado
*/

p_no_hash nova_lista(char* s, int a){
    p_no_hash novo;
    novo = malloc(sizeof(struct no_hash));

    novo -> str = malloc(strlen(s) + 1);
    strcpy(novo -> str, s);
    novo -> n = a;

    novo -> prox = NULL;
    novo -> ant = NULL;

    return novo;
}

p_indice criar_indice(char *nome_arquivo) {
    //le a lista
    int numero_periodos;
    p_no_str lista = ler_lista_periodos(nome_arquivo, &numero_periodos);

    //inicializa o indice
    p_indice indice = malloc(sizeof(struct indice));
    assert(indice);
    for(int i=0; i<MOD; i++){
        indice -> lista_hash[i] = NULL;
    }

    //percorre todos os períodos
    int a = 0;
    for(p_no_str i = lista; i != NULL; i = i -> prox, a++){
        char* str = i -> str;

        //extrai as palavras do período
        p_no_str periodo = extrair_palavras(str);

        //para cada palavra do período, se ela tem hashing i, guarda o período na posição i do vetor
        for(p_no_str j = periodo; j != NULL; j = j -> prox){
            int n = hash(j -> str);

            //se já adicionamos esse período no vetor
            if(indice -> lista_hash[n] != NULL && indice -> lista_hash[n] -> ant -> n == a){
                continue;
            }

            p_no_hash novo = nova_lista(str, a);

            //se o vetor está vazio
            if(indice -> lista_hash[n] == NULL){
                novo -> prox = novo;
                novo -> ant = novo;
                indice -> lista_hash[n] = novo;
            }
            //se não está vazio
            else{
                p_no_hash first = indice -> lista_hash[n];
                novo -> prox = first;
                novo -> ant = first -> ant;
                first -> ant -> prox = novo; 
                first -> ant = novo;
            }
        }

        liberar_lista_str(periodo);
    }

    liberar_lista_str(lista);
    return indice;
}

void liberar_indice(p_indice indice) {
    for(int i=0; i<MOD; i++){
        if(indice -> lista_hash[i] == NULL){
            free(indice -> lista_hash[i]);
            continue;
        }
        p_no_hash lista = indice -> lista_hash[i] -> prox;
        while (lista != indice -> lista_hash[i]){
            p_no_hash tmp = lista;
            lista = lista->prox;
            free(tmp->str);
            free(tmp);
        }
        free(lista->str);
        free(lista);
    }
    free(indice);
}

int consultar_indice(
    p_indice indice,
    char *consulta,
    void(callback)(char *periodo, int numero_ocorrencia)) //
{
    int numero_ocorrencia = 0;
    p_no_str palavras_consulta = extrair_palavras(consulta);

    //procura é o hash da primeira palavra da consulta
    int procura = hash(palavras_consulta -> str);
    
    //todos os periodos que têm a palavra procura
    p_no_hash periodo = indice -> lista_hash[procura];
    
    //se não há períodos com a palavra
    if(periodo == NULL){
        liberar_lista_str(palavras_consulta);
        return 0;
    }

    //extrai as palavras do primeiro período
    p_no_str palavras_periodo = extrair_palavras(periodo -> str);

    //se está no primeiro período aumenta as ocorrencias
    if (corresponde(palavras_consulta, palavras_periodo)){
        numero_ocorrencia += 1;
        callback(periodo -> str, numero_ocorrencia);
    }

    liberar_lista_str(palavras_periodo);

    //para todos os outros períodos faça o mesmo procedimento
    for (periodo = periodo -> prox; periodo != indice -> lista_hash[procura]; periodo = periodo->prox) {
        p_no_str palavras_periodo = extrair_palavras(periodo -> str);

        if (corresponde(palavras_consulta, palavras_periodo)){
            numero_ocorrencia += 1;
            callback(periodo -> str, numero_ocorrencia);
        }

        liberar_lista_str(palavras_periodo);
    }

    liberar_lista_str(palavras_consulta);
    return numero_ocorrencia;
}
