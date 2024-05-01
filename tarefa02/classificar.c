#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

//struct para nome e sobrenome
struct pessoa{
	char nome[MAX];
	char sobrenome[MAX];
};

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

//faz bubble sort em pacientes, se qual=1, da prioridade ao nome, se qual=2, ao sobrenome
void bubble_sort(struct pessoa *pacientes, int n, int qual){
	int i, j;
	struct pessoa aux;

    for (i=0; i<n-1; i++){
        for (j=0; j<n-1; j++){
			int cmp_nome = strcmp(pacientes[j].nome, pacientes[j+1].nome);
			int cmp_sobrenome = strcmp(pacientes[j].sobrenome, pacientes[j+1].sobrenome);

			int troca1 = (qual == 1) && (cmp_nome > 0 || (cmp_nome == 0 && cmp_sobrenome > 0));
			int troca2 = (qual == 2) && (cmp_sobrenome > 0 || (cmp_sobrenome == 0 && cmp_nome > 0));

			if(troca1 || troca2){
				aux = pacientes[j];
				pacientes[j] = pacientes[j+1];
				pacientes[j+1] = aux;
			}
		}
	}
}

//se qual=1, imprime os pacientes com nome repetido, se qual=2, os com sobrenome repetido
void imprimir_repetidos(struct pessoa *pacientes, int n, int qual){
	int i;
	for(i=0; i<n; i++){
		int igual_ant = 1, igual_prox = 1;
		if(i != 0){
			if(qual == 1){
				igual_ant = strcmp(pacientes[i].nome, pacientes[i-1].nome);
			}
			if(qual == 2){
				igual_ant = strcmp(pacientes[i].sobrenome, pacientes[i-1].sobrenome);
			}
		}

		if(i != n-1){
			if(qual == 1){
				igual_prox = strcmp(pacientes[i].nome, pacientes[i+1].nome);
			}
			if(qual == 2){
				igual_prox = strcmp(pacientes[i].sobrenome, pacientes[i+1].sobrenome);
			}
		}

		if(igual_ant == 0 || igual_prox == 0){
			printf("%s_%s\n", pacientes[i].nome, pacientes[i].sobrenome);
		}
	}
}

int main(){
	//define variaveis
	int n, i;
	scanf("%d ", &n);
	
	char func[MAX], ler[MAX];
	struct pessoa *pacientes;
	
	scanf("%s", func);
	
	//"vetor" pacientes, com o nome das pessoas
	pacientes = malloc(n * sizeof(struct pessoa));

	if (pacientes == NULL) {
        printf("Nao ha memoria suficente!\n");
        exit(1);
    }
	
	//le o nome de cada um, separa e guarda em pacientes
	for(i=0; i<n; i++){
		strcpy(pacientes[i].nome, "");
		strcpy(pacientes[i].sobrenome, "");
		scanf("%s", ler);

		separar(ler, pacientes[i].nome, pacientes[i].sobrenome);
	}

	//resolve o problema em cada caso
	if(strcmp(func, "homonimos") == 0){
		bubble_sort(pacientes, n, 1);
		imprimir_repetidos(pacientes, n, 1);
	}
	else{
		bubble_sort(pacientes, n, 2);
		imprimir_repetidos(pacientes, n, 2);
	}
	
	free(pacientes);
	return 0;
}