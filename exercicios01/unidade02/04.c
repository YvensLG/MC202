#include <stdio.h>

int calcular_det(int matriz[3][3]){
	int i, soma = 0;
	
	for(i=0; i<3; i++){
		soma += matriz[0][i%3] * matriz[1][(i+1)%3] * matriz[2][(i+2)%3];
		soma -= matriz[2][i%3] * matriz[1][(i+1)%3] * matriz[0][(i+2)%3];
	}
	
	return soma;
}

int main(){
	int i, j;
	int matriz[3][3];
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			scanf("%d", &matriz[i][j]);
		}
	}
	
	printf("%d\n", calcular_det(matriz));
	
	return 0;
}
