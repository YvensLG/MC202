#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"

struct imagem *ler_imagem() {
    struct imagem *img;
    char peek;
    int i, j, r, g, b;
    assert(img = malloc(sizeof(*img)));
    scanf("P3 ");
    while ((peek = getchar()) == '#'){
        scanf("%*[^\r\n]%*[\r\n]");
    }
    ungetc(peek, stdin);
    assert(scanf("%d %d %*d", &img->w, &img->h) == 2);
    assert(img->pix = malloc(sizeof(*img->pix) * img->h));
    for (i = 0; i < img->h; i++) {
        assert(img->pix[i] = malloc(sizeof(**img->pix) * img->w));
        for (j = 0; j < img->w; j++) {
            assert(scanf("%d%d%d", &r, &g, &b) == 3);
            img->pix[i][j] = (r << 16) + (g << 8) + b;
        }
    }
    return img;
}

void liberar_imagem(struct imagem *img) {
    int i;
    for (i = 0; i < img -> h; i++){
        free(img -> pix[i]);
    }
    free(img -> pix);
    free(img);
}
