#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "imagem.h"
#include "matriz.h"

/*
Foi usado um grafo para representar as regiões.
Cada região é um vértice do grafo.
Utilizei também uma matriz de adjacência para saber se vértices são vizinhos no grafo.
Se dá pra ir da região i para a j em 1 movimento, então, adj[i][j] = adj[j][i] = 1.
*/

int main() {
    int i, j;
    struct imagem *img = ler_imagem();
    int h = img -> h, w = img -> w;
    
    //matriz de regiões
    int **img_aux = criar_matriz(h, w, -2);
    int n = 2, m = 0;

    //encontra as regiões e dá nome para cada uma
    //2, 3, 4 ... se não brancas e 0, 1 se brancas
    for (i = 0; i < h; i++){
        for (j = 0; j < w; j++){
            if(img_aux[i][j] == -2 && img -> pix[i][j] != BRANCA){
                pintar(img, img_aux, n, i, j);
                n++;
            }
            else if(img_aux[i][j] == -2 && img -> pix[i][j] == BRANCA){
                pintar(img, img_aux, m, i, j);
                m++;
            }
        }
    }

    //matriz de adjacência
    int **adj = criar_matriz(n, n, 0);

    //se há dois números distintos lado-a-lado, eles são vizinhos do grafo
    for (i = 0; i < h; i++){
        for (j = 0; j < w; j++){
            if(i-1 >= 0 && img_aux[i][j] != img_aux[i-1][j]){
                int a = img_aux[i][j];
                int b = img_aux[i-1][j];
                adj[a][b] = 1;
                adj[b][a] = 1;
            }
            if(j-1 >= 0 && img_aux[i][j] != img_aux[i][j-1]){
                int a = img_aux[i][j];
                int b = img_aux[i][j-1];
                adj[a][b] = 1;
                adj[b][a] = 1;
            }
        }
    } 

    //encontra a distancia dos brancos (0 e 1)
    int k = distancia(adj, n, 0, 1);
    printf("Maria deve memorizar %d regioes.\n", k);

    //termina
    liberar_matriz(adj, n);
    liberar_matriz(img_aux, h);
    liberar_imagem(img);
    return 0;
}
