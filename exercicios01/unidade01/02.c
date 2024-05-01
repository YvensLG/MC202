#include <stdio.h>

int reverso(int a){
	int b = 0;
	while(a != 0){
		b *= 10;
		b += a%10;
		a /= 10;
	}
	return b;
}

int main(){
	int a;
	scanf("%d", &a);
	int b = reverso(a);
	if(a == b){
		printf("Eh palindromo!\n");
	}else{
		printf("Nao eh palindromo...\n");
	}
	return 0;
}
