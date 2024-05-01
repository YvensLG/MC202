/*
Cria uma matriz de inteiros

Parâmetros:
    h (int), a altura da matriz
    w (int), a largura da matriz
    fill (int), o número que será colocado na matriz inteira
*/

int** criar_matriz(int h, int w, int fill);

/*
Libera uma matriz de inteiros

Parâmetros:
    matriz (int**), a matriz inteira
    n (int), a altura da matriz
*/

void liberar_matriz(int** matriz, int n);

/*
Pinta uma matriz de inteiros comparando com uma imagem a partir de um ponto dado

Parâmetros:
    img (struct imagem*), a imagem
    img_aux (int**), a matriz a ser pintada
    n (int), a "cor" a ser pintada
    i (int), a primeira coordenada do ponto dado
    j (int), a segunda coordenada do ponto dado
*/

void pintar(struct imagem *img, int **img_aux, int n, int i, int j);

/*
Calcula a distância dos vértices inicial e final em relação à matriz de adjacência dada

Parâmetros:
    adj (int**), a matriz de adjacência
    n (int), a quantidade de vértices do grafo
    inicial (int), o vértice inicial
    final (int), o vértice final
*/

int distancia(int **adj, int n, int inicial, int final);
