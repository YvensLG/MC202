#define MAX 21

typedef struct _Item Item;

/*
Struct que representa um item (caixa de alimentos)

nome (char*) é a string que contém o nome do item (fruta)
chave (int*) é o inteiro que representa o peso do item
*/

struct _Item{
    char nome[MAX];
    int chave;
};

typedef struct _FP fp;

/*
Struct que representa a heap a ser usada

v (Item*) é o vetor de itens que estão na heap
n (int) é a quantidade de elementos na heap atualmente
tamanho (int) é o tamanho máximo da heap
*/

struct _FP{
    Item *v;
    int n;
    int tamanho;
};

/*
Troca os valores de duas variávies Item 

Parâmetros:
    a (Item*) a primeira variável
    b (Item*) a segunda variável
*/

void troca(Item* a, Item* b);

/*
Cria uma Heap

Parâmetros:
    tam (int) o tamanho máximo da heap
*/

fp* criar_filaprio(int tam);

/*
Destroi uma Heap

Parâmetros:
    fprio (fp*) a heap a ser destruida
*/

void destruir_filaprio(fp* fprio);

/*
Insere um elemento na Heap

Parâmetros:
    fprio (fp*) a heap a ser usada
    item (Item) o item a ser adicionado na heap
*/

void insere(fp* fprio, Item item);

/*
Leva um elemento que está na base do Heap para cima, seguindo a ordem da estrutura

Parâmetros:
    fprio (fp*) a heap a ser usada
    k (int) a posição do elemento
*/

void sobe_no_heap(fp* fprio, int k);

/*
Remove e devolve o máximo (primeiro elemento) de uma Heap

Parâmetros:
    fprio (fp*) a heap a ser usada
*/

Item extrai_maximo(fp* fprio);

/*
Leva um elemento que está no topo do Heap para baixo, seguindo a ordem da estrutura

Parâmetros:
    fprio (fp*) a heap a ser usada
    k (int) a posição do elemento
*/

void desce_no_heap(fp* fprio, int k);
