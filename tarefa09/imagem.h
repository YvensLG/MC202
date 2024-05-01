#define PRETA 0
#define BRANCA 0xFFFFFF

/*
Struct que representa uma imagem

w (int) é a largura da imagem
h (int) é a altura da imagem
pix (int**) é a matriz de pixels
*/

struct imagem {
    int w, h;
    int **pix;
};

/*
Lê um arquivo .ppm e retorna a imagem
*/

struct imagem *ler_imagem();

/*
Libera a imagem

Parâmetros:
    img (struct imagem*), a imagem em questão
*/

void liberar_imagem(struct imagem *img);