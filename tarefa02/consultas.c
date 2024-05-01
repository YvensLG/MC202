#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacientes.h"

int main(){
    //define variaveis que serao usadas
    int i, maxv, registrados=0;
    char codigos_cid[MAXtxt][MAXcod], doencas[MAXtxt][MAXseg];  //codigo cid e doenca respectiva
    char codigos_crm[MAXtxt][MAXcod], medicos[MAXtxt][MAXseg];  //codigo crm e medico respectivo
    char comando[10];

    scanf("%s %d", comando, &maxv);
    paciente *lista = malloc(maxv * sizeof(paciente));  //lista com todos os pacientes 

    if (lista == NULL) {
        printf("Nao ha memoria suficente!\n");
        exit(1);
    }

    //atualiza as variaveis
    int n_doencas = ler_dados(codigos_cid, doencas, "dados/doencas.txt");
    int n_medicos = ler_dados(codigos_crm, medicos, "dados/medicos.txt");

    //a cada linha lida, realiza um comando
    while(1){
        char nome[MAXnome], cid[MAXcod], crm[MAXcod];
        scanf("%s", comando);

        if(strcmp(comando, "registrar") == 0){
            scanf("%s %s %s", nome, cid, crm);
            registrar(lista, nome, cid, crm, &registrados);
        }

        else if(strcmp(comando, "remover") == 0){
            scanf("%s", nome);
            remover(lista, nome, registrados);
        }

        else if(strcmp(comando, "alterar") == 0){
            scanf("%s %s", nome, cid);
            alterar(lista, nome, cid, registrados);
        }

        else if(strcmp(comando, "fechar") == 0){
            break;
        }
    }

    //completa o registro de cada paciente: separa nome e sobrenome e adiciona o nome de seu medico e de sua doenca
    for(i = 0; i < registrados; i++){
        atualizar_nome(&(lista[i]));
        atualizar(&(lista[i].cid), &(lista[i].doenca), codigos_cid, doencas, n_doencas);
        atualizar(&(lista[i].crm), &(lista[i].medico), codigos_crm, medicos, n_medicos);
    }

    //organiza a lista
    bubble_sort(lista, registrados);
    
    //imprime o pedido
    for(i=0; i < registrados; i++){
        if(lista[i].removido){
            continue;
        }
        printf("%s_%s atendido por %s: %s\n", lista[i].nome, lista[i].sobrenome, lista[i].medico, lista[i].doenca);
    }

    free(lista);
    return 0;
}