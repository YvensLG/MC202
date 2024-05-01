#define MAXN 200

typedef struct _cidade cidade;

/*
Struct que representa uma cidade

populacao (int) é a populacao da cidade
nome (char*) é o nome da cidade
*/

struct _cidade{
    int populacao;
    char nome[MAXN];
};

/*
Retorna o mínimo entre dois números

Parâmetros:
    a (int), o primeiro número
    b (int), o segundo número
*/

int min(int a, int b);

/*
Retorna o máximo entre dois números

Parâmetros:
    a (int), o primeiro número
    b (int), o segundo número
*/

int max(int a, int b);


/*
Atualiza uma matriz de distâncias utilizando o algoritmo Floyd Warshall

Parâmetros:
    dist (**int), dist[i][j] representa a distância mínima entre os vértices i e j de um grafo
    n (int), o número de vértices do grafo
*/

void floyd_warshall(int dist[MAXN][MAXN], int n);
