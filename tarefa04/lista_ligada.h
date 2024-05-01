typedef struct _no no;

/*
Struct que representa nó da lista ligada

dado (char*) é a string guardada no nó

negrito (int) (1 ou 0) diz se a string está ou não em negrito

prox (no*) diz quem é o próximo elemento da lista ligada
*/

struct _no{
    char* dado;
    int negrito;
    no* prox;
};

/*
Cria uma lista
*/

no* criar_lista ();

/*
Cria um nó com as informações dadas

Parâmetros:
    txt (char*), o dado do nó
    n (int), o estado de negrito do nó
    next (no*), o prox do nó
*/


no* criar_no(char* txt, int n, no* next);

/*
Destroi uma lista

Parâmetros:
    lista (no*), a lista ligada
*/

void destruir_lista(no *lista);

/*
Insere um texto dado em algum lugar do texto completo

Parâmetros:
    texto (no*), a lista ligada que representa o texto completo
    txt (char*), o texto que será inserido na posição
    n (int), a posição na qual o texto será inserido
*/

void insere(no* texto, char* txt, int n);

/*
Deixa uma certa parte do texto em negrito

Parâmetros:
    texto (no*), a lista ligada que representa o texto completo
    n (int), a posição na qual o trecho se inicia
    m (int), a posição na qual o trecho termina
*/

void destacar(no* texto, int n, int m);

/*
Adiciona um elemento ao início de uma lista ligada

Parâmetros:
    lista (no*), uma lista ligada
    c (char*), o texto que será adicionado
*/

no* adicionar_elemento (no* lista , char* x);

/*
Imprime uma lista ligada

Parâmetros:
    lista (no*), uma lista ligada
*/

void imprime(no* lista);

/*
Une dois nós seguidos de uma lista (no2 'entra' no no1)

Parâmetros:
    no1 (no*), um no da lista
    no2 (no*), o no vizinho de no1
*/

void unir_no(no* no1, no* no2);