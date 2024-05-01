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

typedef struct _pilha pilha;

/*
Struct que representa uma pilha

topo (no*) diz quem está no topo da pilha (representada por uma lista ligada)
*/

struct _pilha{
    no* topo;
};

/*
Cria uma lista ligada
*/

no* criar_lista();

/*
Cria uma pilha
*/

pilha* criar_pilha();

/*
Adiciona um elemento ao topo de uma pilha

Parâmetros:
    p (pilha*), a pilha em questão
    x (int), o elemento que será adicionado
*/

void push(pilha* p, int x);

/*
Remove e retorna um elemento que está no topo de uma pilha

Parâmetros:
    p (pilha*), a pilha em questão
*/

int pop(pilha* p);


/*
Destroi uma pilha

Parâmetros:
    p (pilha*), a pilha em questão
*/

void destruir_pilha(pilha* p);