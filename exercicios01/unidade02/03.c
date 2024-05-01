#include <stdio.h>
#define MAX 30

void calcular_trans(int transposta[MAX][MAX], int matriz[MAX][MAX], int n, int m){
	int i, j;
	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			transposta[j][i] = matriz[i][j];
		}
	}
}

int main(){
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	
	int matriz[MAX][MAX];
	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			scanf("%d", &matriz[i][j]);
		}
	}
	
	int transposta[MAX][MAX];
	calcular_trans(transposta, matriz, n, m);
	
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("%d ", transposta[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
