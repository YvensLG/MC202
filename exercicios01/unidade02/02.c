#include <stdio.h>
#define MAX 30

int simetrica(int matriz[MAX][MAX], int n, int m){
	int i, j;
	if(n != m) return 0;
	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			if(matriz[i][j] != matriz[j][i]){
				return 0;
			}
		}
	}
	
	return 1;
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
	
	if(simetrica(matriz, n, m)){
		printf("Eh simetrica\n");
	}else{
		printf("Nao eh simetrica\n");
	}
	
	return 0;
}
