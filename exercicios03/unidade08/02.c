#include <stdio.h>
#include <stdlib.h>

/*
a funcao realiza backtracking para resolver o problema das n damas
entrada: inteiro n: número de damas
saída: quantidade de tabuleiros onde as n damas não se atacam
*/

void damas(int n) {
    int k=0;
    /*
    o vetor v das rainhas
    v[m] indica em que linha
    a rainha da coluna m está 
    */ 
    int *v;
    v = malloc(n * sizeof(int));
    
    //quantidade de damas fixas
    int m = 0;

    //nenhuma dama foi colocada inicialmente
    for(int i=0; i<n; i++){
        v[i] = -1;
    }

    while(1){
        //colocamos a dama da posição m uma linha acima
        v[m]++;

        //se passou da quantidade de linhas
        //      acaba, se m=0
        //      senão, voltamos a dama para posição -1 e voltamos a olhar para dama anterior
        if(v[m] == n){
            if(m == 0) break;
            v[m] = -1;
            m--;
            continue;
        }

        //se a dama colocada está na diagonal principal ou secundaria ou linha
        //realocamos a dama para uma linha acima
        char a = 0;
        for(int i=0; i<m; i++){
            a = v[m] == v[i];
            a = a || (v[m] == m - i + v[i]);
            a = a || (v[m] == i - m + v[i]);
            if(a){
                break;
            }
        }
        if(a) continue;
        m++;

        //se tudo deu certo e chegamos ao final
        //aumentamos o número total
        //diminuimos m para contar as outras opções
        if(m == n){
            /*
            for(int i=0; i<n; i++){
                printf("%d ", v[i] + 1);
            }
            printf("\n");
            */
            k++;
            m--;
        }
    }
    free(v);

    //imprime o total de possíveis tabuleiros com n damas
    printf("%d\n", k);
}


int main(){
    int n;
    scanf("%d", &n);
    damas(n);
}