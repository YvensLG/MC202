#include <stdio.h>

int main(){
	int a, n, i;
	
	printf("Quantos numeros?\n");
	scanf("%d", &n);
	
	printf("Digite uma lista:\n");
	
	scanf("%d", &a);
	int min = a, max = a;
	
	for(i=0; i<n-1; i++){
		scanf("%d", &a);
		if(a > max){
			max = a;
		}
		if(a < min){
			min = a;
		}
	}
	
	printf("Diferenca absoluta eh %d", max - min);
	return 0;
}
