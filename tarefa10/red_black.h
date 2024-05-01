#define MAX 21

enum cor {VERMELHO , PRETO};
typedef struct _no_rb no_rb;

/*
Struct que representa nó da red-black tree

chave (char*) é a string que "nomeia" o nó
num (int) é o inteiro que representa o nó no grafo
cor (enum cor) é a cor do nó
esq (no_rb*) é o filho esquerdo do nó
dir (no_rb*) é o filho direito do nó
*/

struct _no_rb{
    char* chave;
    int num;
    enum cor cor;
    no_rb* esq;
    no_rb* dir;
};

/*
Diz se um nó é vermelho

Parâmetros:
    x (no_rb*), o nó da red-black
*/

int ehVermelho(no_rb* x);

/*
Diz se um nó é preto

Parâmetros:
    x (no_rb*), o nó da red-black
*/

int ehPreto(no_rb* x);

/*
Rotaciona uma árvore para esquerda

Parâmetros:
    raiz (no_rb*), a raiz da red-black
*/

no_rb* rotaciona_para_esquerda(no_rb* raiz);

/*
Rotaciona uma árvore para direita

Parâmetros:
    raiz (no_rb*), a raiz da red-black
*/

no_rb* rotaciona_para_direita(no_rb* raiz);

/*
Sobe a cor vermelha na árvore

Parâmetros:
    raiz (no_rb*), a raiz da red-black
*/

void sobe_vermelho(no_rb* raiz);

/*
Inserir um valor na red-black

Parâmetros:
    raiz (no_rb*), a raiz da red-black
    chave (char*), a chave que vamos inserir
    num (int), o número que acompanha a chave
*/

no_rb* inserir_rec(no_rb* raiz, char* chave, int num);
no_rb* inserir(no_rb* raiz, char* chave, int num);

/*
Busca um nó da red-black a partir de sua chave

Parâmetros:
    raiz (no_rb*), a raiz da red-black
    chave (char*), a chave a ser buscada
*/

no_rb* buscar(no_rb* raiz, char* chave);

/*
Destroi uma red-black tree

Parâmetros:
    raiz (no_rb*), a árvore que queremos destruir
*/

void destruir_rb(no_rb* raiz);