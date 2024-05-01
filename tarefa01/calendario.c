#include <stdio.h>

#define dia 0
#define mes 1
#define ano 2

//troca n de uma base para base 10
int trocar_base(int n, int base){
	int pot = 1, result = 0;
	while(n>0){
		result += (n%10)*pot;
		n = n/10;
		pot *= base;
	}
	return result;
}

//somar s na data e devolver a data final
void somar_dias(int d[], int s, int maxdia, int maxmes){
	d[dia] += s;
	if(d[dia] > maxdia){
		d[mes] += d[dia] / maxdia;
		d[dia] = d[dia] % maxdia;
		if(d[dia] == 0){
			d[dia] += maxdia;
			d[mes] --;
		}
	}
	
	if(d[mes] > maxmes){
		d[ano] += d[mes] / maxmes;
		d[mes] = d[mes] % maxmes;
		if(d[mes] == 0){
			d[mes] += maxmes;
			d[ano] --;
		}
	}
}	

int main(){
	//le variaveis
	char c;
	int data[3];
	scanf("%d %c %d %c %d", &data[dia], &c ,&data[mes], &c, &data[ano]);
	
	int maxdia, maxmes;
	scanf("%d %d", &maxdia, &maxmes);
	
	int falta_b6;
	scanf("%d", &falta_b6);
	
	int falta = trocar_base (falta_b6, 6);
	
	//calcula data final e a imprime
	somar_dias(data, falta, maxdia, maxmes);
				
	printf("%d/%d/%d", data[dia], data[mes], data[ano]);
	
	return 0;
}
