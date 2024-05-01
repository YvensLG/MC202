#include <stdio.h>

#define MAX 50

//ler o vetor
void scanv(int v[], int n){
	for(int i=0; i<n; i++){
		scanf("%d", &v[i]);
	}
}

//imprimir o vetor
void printv(int v[], int n){
	for(int i=0; i<n; i++){
		printf("%d ", v[i]);
	}
	printf("\n");
}

//v = diferenca(v1, v2) e devolve o tamanho de v
int diferenca(int v1[], int n, int v2[], int m, int v[]){
	int i=0, j=0, k=0;
	
	//pegar sempre o minimo dentre v1 e v2 e se forem iguais, pula
	while(1){
        if(i == n && j == m) break;
        else if(j == m){
        	v[k] = v1[i];
            i++;
            k++;
            continue;
		}
		else if(i == n){
        	v[k] = v2[j];
            j++;
            k++;
            continue;
		}
        
        if(v1[i]<v2[j]){
            v[k] = v1[i];
            i++;
            k++;
        }
        else if(v1[i]>v2[j]){
            v[k] = v2[j];
            j++;
            k++;
        }else{
            i++;
            j++;
        }
    }
    
	return k;	
}

int main(){
	//le variaveis
    int n, m, tamanho;
    scanf("%d %d", &n, &m);

    int v1[MAX], v2[MAX], v[2*MAX];
    scanv(v1, n);
	scanv(v2, m);
	
	//acha a diferenca e a imprime
	tamanho = diferenca(v1, n, v2, m, v);
	
    printv(v, tamanho);
    
    return 0;
}
