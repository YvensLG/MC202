#define MAXnome 31
#define MAXseg 101
#define MAXcod 7
#define MAXtxt 120

typedef struct{
    char nome[MAXnome], sobrenome[MAXnome];

    char cid[MAXcod];
    char doenca[MAXseg];

    char crm[MAXcod];
    char medico[MAXseg];

    int removido;
} paciente;

int ler_dados(char codigos[][MAXcod], char equiv[][MAXseg], char abrir[]);

void separar(char ler[], char primeiro[], char segundo[]);

void bubble_sort(paciente *lista, int n);

void registrar(paciente *lista, char nome[], char cid[], char crm[], int *registrados);

void remover(paciente *lista, char nome[], int registrados);

void alterar(paciente *lista, char nome[], char cid[], int registrados);

void atualizar(char cod[][MAXcod], char med[][MAXseg], char codigos[][MAXcod], char equiv[][MAXseg], int n);

void atualizar_nome(paciente *lista);