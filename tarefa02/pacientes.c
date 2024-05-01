#include <stdio.h>
#include <string.h>
#include "pacientes.h"

//abre o arquivo dado, separa o vetor com os codigos e com a doenca/medico respectivo, alem de retornar a quantidade de linhas
int ler_dados(char codigos[][MAXcod], char equiv[][MAXseg], char abrir[]){
    int n;
    FILE *fd = fopen(abrir, "r");

    fscanf(fd, "%d", &n);
    
    for (int i=0; i < n; i++) {
        fscanf(fd, "%s  %[^\n]", codigos[i], equiv[i]);
    }

    fclose(fd);
    return n;
}

//registra o nome, o cid e o crm de um paciente na lista
//se houver algum anterior que foi removido, substitui a sua posicao
//se nao, adiciona uma nova e atualiza a quantidade total de pessoas registradas
void registrar(paciente *lista, char nome[], char cid[], char crm[], int *registrados){
    int i;
    for(i=0; i <= *registrados; i++){
        if(i == *registrados){
            *registrados += 1;
            break;
        }
        else if(lista[i].removido){
            break;
        }
    }
            
    strcpy(lista[i].nome, nome);
    strcpy(lista[i].cid, cid);
    strcpy(lista[i].crm, crm);
    lista[i].removido = 0;
}

//remove o paciente com dado nome da lista (atualiza seu .removido)
void remover(paciente *lista, char nome[], int registrados){
    int i;
    for(i=0; i < registrados; i++){
        if(strcmp(lista[i].nome, nome) == 0){
            lista[i].removido = 1;
            break;
        }
    }
}

//altera o cid de certo paciente com dado nome na lista
void alterar(paciente *lista, char nome[], char cid[], int registrados){
    int i;
    for(i=0; i<registrados; i++){
        if(strcmp(lista[i].nome, nome) == 0){
            strcpy(lista[i].cid, cid);
            break;
        }
    }
}

//separa o nome do paciente em nome e sobrenome
void atualizar_nome(paciente *p){
    char primeiro[MAXnome], segundo[MAXnome];
    separar(p -> nome, primeiro, segundo);
    strcpy(p -> nome, primeiro);
    strcpy(p -> sobrenome, segundo);
}

//separar primeiro e segundo nomes de uma string (ler)
void separar(char ler[], char primeiro[], char segundo[]){
	int i = -1, j = -1;
	do{
        i++;
		primeiro[i] = ler[i];
        if(primeiro[i] == '_'){
            primeiro[i] = '\0';
        }
	}while(ler[i] != '_');
	i++;
	
	do{
        j++;
		segundo[j] = ler[i+j];
	}while(ler[i+j] != '\0');
}

//adiciona o medico/doenca equivalente ao codigo dado com respeito as listas lidas
void atualizar(char cod[][MAXcod], char eq[][MAXseg], char codigos[][MAXcod], char equiv[][MAXseg], int n){
    for(int i=0; i<n; i++){
        if(strcmp(codigos[i], *cod) == 0){
            strcpy(*eq, equiv[i]);
        }
    }
}

//organiza a lista de pacientes em relação ao seu nome e em seguida ao seu sobrenome
void bubble_sort(paciente *lista, int n){
	int i, j;
	paciente aux;

    for (i=0; i<n-1; i++){
        for (j=0; j<n-1; j++){
			int cmp_nome = strcmp(lista[j].nome, lista[j+1].nome);
			int cmp_sobrenome = strcmp(lista[j].sobrenome, lista[j+1].sobrenome);
            
			if(cmp_nome > 0 || (cmp_nome == 0 && cmp_sobrenome > 0)){
				aux = lista[j];
				lista[j] = lista[j+1];
				lista[j+1] = aux;
			}
		}
	}
}
