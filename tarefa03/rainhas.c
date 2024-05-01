#include <stdio.h>
#include <stdlib.h>
#define MAX 10

/*
Struct que representará o tabuleiro

board representa o tabuleiro em si, '.' é espaço vazio, 'r', rainha e 'p' peão

linha representa, em módulo, a quantidade de rainhas em cada linha
se <0, a última peça colocada foi uma rainha, se >0, foi um peão

coluna é o análogo de linha, mas para colunas

diag1 é o análogo de linha, mas para diagonais principais

diag2 é o análogo de linha, mas para diagonais secundárias
*/

typedef struct{
	char board[MAX][MAX];
    int linha[MAX];
    int coluna[MAX];
    int diag1[2*MAX];
    int diag2[2*MAX];
} tabuleiro;

/*
Preenche uma matriz com caracteres k

Parâmetros:
    board (char[][]): A matriz
    n (int): A largura/altura da matriz
    k (char): O caractere que vai ser preenchido na matriz
*/

void preencher_tab(char board[MAX][MAX], int n, char k){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            board[i][j] = k;
        }
    }
}

/*
Imprime uma matriz

Parâmetros:
    board (char[][]): A matriz
    n (int): A largura/altura da matriz
*/

void imprimir_tab(char board[MAX][MAX], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

/*
Inicializa o tabuleiro com todas as posições vazias

Parâmetros:
    tab (tabuleiro): O tabuleiro
*/

void inicializar(tabuleiro* tab){
    preencher_tab(tab -> board, MAX, '.');

    for(int i=0; i < MAX; i++){
        tab -> linha[i] = 0;
        tab -> coluna[i] = 0;
    }
    
    for(int i=0; i < 2 * MAX; i++){
        tab -> diag1[i] = 0;
        tab -> diag2[i] = 0;
    }  
}

/*
Checa se pode colocar uma rainha na posição (x, y) do tabuleiro sem ser atacada

Parâmetros:
    tab (tabuleiro): O tabuleiro que contém as peças
    n (int): A largura/altura do tabuleiro
    x (int): A linha onde está a peça
    y (int): A coluna onde está a peça

Saída:
    checar (int): 1 se for possível, 0 se não
*/

int checar(tabuleiro* tab, int n, int x, int y){
    if(tab -> linha[x] > 0){
        return 0;
    }
    if(tab -> coluna[y] > 0){
        return 0;
    }
    if(tab -> diag1[n-1 + y - x] > 0){
        return 0;
    }
    if(tab -> diag2[x + y] > 0){
        return 0;
    }
    
    return 1;
}

/*
Atualiza linha, coluna e diagonais do tabuleiro colocando a peça k na posição (x, y)

Parâmetros:
    tab (tabuleiro): O tabuleiro que contém as peças
    n (int): A largura/altura do tabuleiro
    k (char): 'p' para peão ou 'r' para rainha
    x (int): A linha onde a peça será colocada
    y (int): A coluna onde a peça será colocada
*/
void atualizar(tabuleiro* tab, int n, char k, int x, int y){
    if(k == 'r'){
        tab -> linha[x] = abs(tab -> linha[x]) + 1;
        tab -> coluna[y] = abs(tab -> coluna[y]) + 1;
        tab -> diag1[n-1 + y - x] = abs(tab -> diag1[n-1 + y - x]) + 1;
        tab -> diag2[x + y] = abs(tab -> diag2[x + y]) + 1; 
    }
    if(k == 'p'){
        tab -> linha[x] = -abs(tab -> linha[x]);
        tab -> coluna[y] = -abs(tab -> coluna[y]);
        tab -> diag1[n-1 + y - x] = -abs(tab -> diag1[n-1 + y - x]);
        tab -> diag2[x + y] = -abs(tab -> diag2[x + y]); 
    }
}

/*
Diz se é possível completar um tabuleiro feito até a posição anterior a (x,y)
usando p peões e r rainhas

Parâmetros:
    tab (tabuleiro): O tabuleiro que contém as peças
    n (int): A largura/altura do tabuleiro
    p (int): O número de peões disponível
    r (int): O número de rainhas disponível
    x (int): A linha onde a próxima peça será colocada
    y (int): A coluna onde a próxima peça será colocada

Saída:
    resolve (int): 1 se for possível, 0 se não
*/

int resolve(tabuleiro* tab, int n, int p, int r, int x, int y){
    //Se r<0 ou p<0, o tabuleiro não funciona
    if(p < 0 || r < 0){
        return 0;
    }

    //se a primeira coluna não tem rainhas até a sua metade, o tabuleiro não funciona
    if(tab -> coluna[0] == 0){
        if(y > 0 || (y == 0 && x > (n+1)/2)){
            return 0;
        }
    }
    
    //se x passou da borda do tabuleiro, olhamos para próxima coluna (y++)
    if(x == n){
        x = 0;
        y ++;

        //olha se é possível colocar r rainhas no tabuleiro incompleto que sobra
        if(r > ((n+1)/2) * ((n-y+1)/2)){
            return 0;
        }

        //olha se é possível colocar p peões no tabuleiro incompleto que sobra
        if(p + r > n * (n-y) || p < r-n){
            return 0;
        }
    }

    //se y passou da borda do tabuleiro, o tabuleiro acabou e fazemos a checagem final
    if(y == n){
        if(p == 0 && r == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    //tenta colocar uma rainha
    tab -> board[x][y] = 'r';
    if(checar(tab, n, x, y)){
        int a = tab -> linha[x];
        int b = tab -> coluna[y];
        int c = tab -> diag1[n-1 + y - x];
        int d = tab -> diag2[x + y];
    
        atualizar(tab, n, 'r', x, y);

        if(resolve(tab, n, p, r-1, x+1, y)){
            return 1;
        }

        tab -> linha[x] = a;
        tab -> coluna[y] = b;
        tab -> diag1[n-1 + y - x] = c;
        tab -> diag2[x + y] = d; 
    }
    //se tiver peça actacando a posição (x,y), pode ter um peão
    else{
        tab -> board[x][y] = 'p';

        int a = tab -> linha[x];
        int b = tab -> coluna[y];
        int c = tab -> diag1[n-1 + y - x];
        int d = tab -> diag2[x + y];
        
        atualizar(tab, n, 'p', x, y);

        if(resolve(tab, n, p-1, r, x+1, y)){
            return 1;
        }

        tab -> linha[x] = a;
        tab -> coluna[y] = b;
        tab -> diag1[n-1 + y - x] = c;
        tab -> diag2[x + y] = d;
    }

    //tentamos colocar um espaço vazio
    tab -> board[x][y] = '.';
    if(resolve(tab, n, p, r, x+1, y)){
        return 1;
    }

    //caso dê tudo errado
    return 0;
}

/*
Imprime o número mínimo de peões necessários para completar um tabuleiro n x n usando
m rainhas, e um exemplo de tabuleiro. Se não for possível, imprime -1.

Parâmetros:
    tab (tabuleiro): O tabuleiro que será analisado
    n (int): A largura/altura do tabuleiro
    m (int): O número de rainhas disponível
*/
void damas(tabuleiro* tab, int n, int m){
    //único caso que não é possível
    int a = (n + 1)/2;
    if(m > a*a){
        printf("-1\n");
        return;
    }

    //testa todas as possíveis quantidades de peões
    int p;
    for(p = m - n; p <= n*n - m; p++){
        if(resolve(tab, n, p, m, 0, 0)){
            break;
        }
    }

    //imprime quantos peões e a tabela quando acha um que funciona
    printf("%d\n", p);
    imprimir_tab(tab -> board, n);

    return;
}

int main(){
    //lê e define variáveis
    int m, n;
    tabuleiro tab;

    scanf("%d %d", &m, &n);
    inicializar(&tab);

    //responde o problema
    damas(&tab, n, m);

    return 0;
}