#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "red_black.h"
#include "util.h"
#define INF 1000000000

int main(){
    //quantidade de cidades
    int n;
    scanf("%d", &n);
    
    //mapeia números a cidades
    no_rb* map = NULL;
    //mapeia cidades a números
    cidade city[MAXN];
    
    //inicializa matriz de distância do grafo
    int dist[MAXN][MAXN];
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++){
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    //lê a entrada e atualiza os mapeamentos
    char s[MAX];
    int a;
    for(int i=0; i<n; i++){
        scanf("%s %d", s, &a);
        map = inserir(map, s, i);
        city[i].populacao = a;
        strcpy(city[i].nome, s);
    }

    //lê a entrada e atualiza as distâncias entre cidades vizinhas
    int m, d;
    scanf("%d", &m);
    char s1[MAX], s2[MAX];
    for(int i=0; i<m; i++){
        scanf("%s %s %d", s1, s2, &d);

        int map1 = buscar(map, s1) -> num;
        int map2 = buscar(map, s2) -> num;

        dist[map1][map2] = d;
        dist[map2][map1] = d;
    }
    
    //completa a matriz de distâncias com o algoritmo Floyd Warshall
    floyd_warshall(dist, n);

    //achamos o melhor par de cidades
    int maxi, I, J, M = INF, P = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            //máxima distancia escolhidas duas cidades
            maxi = -1;
            for(int k=0; k<n; k++){
                maxi = max(maxi, min(dist[i][k], dist[j][k]));
            }

            //escolhe o mínimo maxi
            if((maxi < M) || (maxi == M && city[i].populacao + city[j].populacao > P)){
                I = i;
                J = j;
                M = maxi;
                P = city[i].populacao + city[j].populacao;
            }
        }
    }

    //imprime o pedido
    printf("Centros de distribuicao: %s e %s\n", city[I].nome, city[J].nome);
    printf("Distancia de atendimento: %d\n", M);

    destruir_rb(map);
    return 0;
}
