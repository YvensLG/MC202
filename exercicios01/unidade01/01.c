#include <stdio.h>
int main(){
	int a;
	scanf("%d", &a);
	int b = a/100;
	int c = a%100;
	if((b+c)*(b+c) == a){
		printf("Esse numero eh massa!\n");
	}else{
		printf("Esse numero eh paia...\n");
	}
	return 0;
}
