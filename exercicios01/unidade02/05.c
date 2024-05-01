#include <stdio.h>
#define MAX 30

int calcular_prod(int produto[][MAX], int v1[][MAX], int n1, int m1, int v2[][MAX], int n2, int m2){
	int i, j, k;
	
	if(m1 != n2){
		return 0;
	}
	
	for(i=0; i<n1; i++){
		for(j=0; j<m2; j++){
			int s=0;
			for(k=0; k<n2; k++){
				s += v1[i][k]*v2[k][j];
			}
			produto[i][j] = s;
		}
	}
	
	return 1;
}

int main(){
	int i, j;
	int n1, m1;
	scanf("%d %d", &n1, &m1);
	
	int v1[MAX][MAX];
	
	for(i=0; i<n1; i++){
		for(j=0; j<m1; j++){
			scanf("%d", &v1[i][j]);
		}
	}
	
	int n2, m2;
	scanf("%d %d", &n2, &m2);
	
	int v2[MAX][MAX];
	
	for(i=0; i<n2; i++){
		for(j=0; j<m2; j++){
			scanf("%d", &v2[i][j]);
		}
	}
		
	int produto[MAX][MAX];
	if(!calcular_prod(produto, v1, n1, m1, v2, n2, m2)){
		printf("dimesoes invalidas");
		return 0;
	}
	
	for(i=0; i<n1; i++){
		for(j=0; j<m2; j++){
			printf("%d ", produto[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
