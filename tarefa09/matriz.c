#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"
#include "fila.h"

int** criar_matriz(int h, int w, int fill){
    int **matriz;
    assert(matriz = malloc(sizeof(*matriz) * h));
    for (int i = 0; i < h; i++) {
        assert(matriz[i] = malloc(sizeof(**matriz) * w));
    }

    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            matriz[i][j] = fill;
        }
    }

    return matriz;
}

void liberar_matriz(int** matriz, int n){
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void pintar(struct imagem *img, int **img_aux, int n, int i, int j){
    img_aux[i][j] = n;
    int **pix = img -> pix;

    if(i-1 >= 0){
        if(pix[i][j] == pix[i-1][j] && img_aux[i-1][j] == -2){
            pintar(img, img_aux, n, i-1, j);
        }
    }
    if(i+1 <= img -> h - 1){
        if(pix[i][j] == pix[i+1][j] && img_aux[i+1][j] == -2){
            pintar(img, img_aux, n, i+1, j);
        }
    }
    if(j-1 >= 0){
        if(pix[i][j] == pix[i][j-1] && img_aux[i][j-1] == -2){
            pintar(img, img_aux, n, i, j-1);
        }
    }
    if(j+1 <= img ->w - 1){
        if(pix[i][j] == pix[i][j+1] && img_aux[i][j+1] == -2){
            pintar(img, img_aux, n, i, j+1);
        }
    }
}

int distancia(int **adj, int n, int inicial, int final){
    int *dist;
    dist = malloc(sizeof(dist) * (n));
    dist[0] = 0;
    for(int i=1; i<n; i++){
        dist[i] = -1;
    }

    fila* f = criar_fila();
    push(f, inicial);

    while(f -> fim != NULL){
        int ini = pop(f);

        for(int i=0; i<n; i++){
            if(adj[ini][i] == 1 && dist[i] == -1){
                dist[i] = dist[ini] + 1;
                push(f, i);
            }
        }
    }

    int k = dist[final] - 1;

    destruir_fila(f);
    free(dist);
    return k;
}