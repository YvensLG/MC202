#include <stdio.h>

#define MAX 100

//le matriz a com m linhas e n colunas
void ler_matriz(int a[][MAX], int m, int n){
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}
}

//ve se (i, j) é o unico minimo de sua linha
int minimo_linha(int a[][MAX], int n, int i, int j){
	for(int k=0; k<n; k++){
		if(a[i][j] >= a[i][k] && k != j){
			return 0;
		}
	}
	return 1;
}

//ve se (i, j) é o unico maximo de sua coluna
int maximo_coluna(int a[][MAX], int m, int i, int j){
	for(int k=0; k<m; k++){
		if(a[i][j] <= a[k][j] && k != i){
			return 0;
		}
	}
	return 1;
}

int main(){
	//le variaveis
	int m, n, a[MAX][MAX];
	scanf("%d %d", &m, &n);
	ler_matriz(a, m, n);
	
	//percorre a matriz e analisa todos os pontos
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(minimo_linha(a, n, i, j) && maximo_coluna(a, m, i, j)){
				printf("(%d, %d) eh ponto de sela com valor %d\n", i, j, a[i][j]);
				return 0;
			}
		}
	}
	
	printf("nao existe ponto de sela\n");
	return 0;
}
