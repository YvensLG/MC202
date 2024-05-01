typedef struct _no no;

/*
Struct que representa nó da árvore binária

dado (char*) é a string guardada no nó

esq (no*) é o filho esquerdo do nó
dir (no*) é o filho direito do nó
pai (no*) é o pai do nó
*/

struct _no{
    char* dado;
    no* esq;
    no* dir;
    no* pai;
};

/*
Cria uma árvore (ou sub árvore) binária 

Parâmetros:
    pai (no*), o endereço do seu pai
*/

no* criar_arvore(no* pai);

/*
Lê expressão dada no problema e armazena na árvore binária 

Parâmetros:
    arv (no*), o endereço da árvore
*/

no* ler_expressao();

/*
Destroi uma árvore binária

Parâmetros:
    arv (no*), a árvore em questão
*/

void destruir_arvore(no* arv);

/*
Imprime uma árvore binária (nesse caso, imprimirá assim como o problema pede)

Parâmetros:
    arv (no*), a árvore em questão
*/

void imprimir_arvore(no* arv);

/*
Otimiza a expressão representada pela árvore binária

Parâmetros:
    arv (no*), a árvore em questão
*/

void otimizar_arvore(no* arv);

// red black:

enum cor {VERMELHO , PRETO};
typedef struct _no_rb no_rb;

/*
Struct que representa nó da red-black tree

chave (char*) é a string que "nomeia" o nó
cor (enum cor) é a cor do nó
esq (no_rb*) é o filho esquerdo do nó
dir (no_rb*) é o filho direito do nó
arv (no*) é a arvore binária (expressão numérica) guardada no nó da red-black
*/

struct _no_rb{
    char* chave;
    enum cor cor;
    no_rb* esq;
    no_rb* dir;
    no* arv;
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
    arv (no*), a árvore binária (expressão numérica) que será inserida junto à chave
*/

no_rb* inserir_rec(no_rb* raiz, char* chave, no* arv);
no_rb* inserir(no_rb* raiz, char* chave, no* arv);

/*
Busca um nó da red-black a partir de sua chave

Parâmetros:
    raiz (no_rb*), a raiz da red-black
    chave (char*), a chave a ser buscada
*/

no_rb* buscar(no_rb* raiz, char* chave);

/*
Olha para uma árvore e remove suas variáveis recursivamente fazendo buscas na red-black

Parâmetros:
    conjunto (no_rb*), o conjunto de variávies armazenadas em uma red-black
    arv (no*), a árvore (expressão numérica) da qual queremos remover as variáveis
*/

void remove_variaveis(no* arv, no_rb* conjunto);

/*
Destroi uma red-black tree

Parâmetros:
    raiz (no_rb*), a árvore que queremos destruir
*/

void destruir_rb(no_rb* raiz);