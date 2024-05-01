typedef struct _no no;

/*
Struct que representa nó da lista ligada

dado (int) é o inteiro guardado no nó
prox (no*) diz quem é o próximo elemento da lista ligada
*/

struct _no{
    int dado;
    no* prox;
};

typedef struct _fila fila;

/*
Struct que representa uma fila

ini (no*) diz quem está no início da fila (representada por uma lista ligada)
fim (no*) diz quem está no fim da fila
*/

struct _fila{
    no* ini;
    no* fim;
};

/*
Cria uma lista ligada
*/

no* criar_lista();

/*
Destroi uma lista ligada

Parâmetros:
    lista (no*), a lista em questão
*/

void destruir_lista(no* lista);

/*
Cria uma fila
*/

fila* criar_fila();

/*
Adiciona um elemento à fila

Parâmetros:
    f (fila*), a fila em questão
    x (int), o elemento que será adicionado
*/

void push(fila* f, int x);

/*
Remove e retorna o elemento que está no inicio da fila

Parâmetros:
    f (fila*), a fila em questão
*/

int pop(fila* f);

/*
Destroi uma fila

Parâmetros:
    f (fila*), a fila em questão
*/

void destruir_fila(fila* f);