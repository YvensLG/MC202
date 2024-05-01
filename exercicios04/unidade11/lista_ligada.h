typedef struct _no no;

struct _no{
    int dado;
    no* prox;
};

no* criar_lista ();

void destruir_lista(no *lista);

no* adicionar_elemento (no* lista , int x);

no* adicionar_elemento_ordem (no* lista , int x);

int esta_na_lista(int n, no* lista);

no* uniao (no* lista1 , no* lista2);

no* uniao_ordenada (no* lista1 , no* lista2);

void imprime(no* lista);
