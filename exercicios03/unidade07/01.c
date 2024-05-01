#include <stdio.h>

double potencia_recursiva(double b, int n){
    if(n == 0){
        return 1;
    }
    return b * potencia_recursiva(b, n-1);
}

double potencia_iterativa(double b, int n){
    double c = 1;
    for(int i=0; i<n; i++){
        c *= b;
    }
    return c;
}

int main(){
    double base;
    int exp;
    scanf("%lf %d", &base, &exp);
    printf("%lf\n", potencia_iterativa(base, exp));
    printf("%lf\n", potencia_recursiva(base, exp));
}

//fazem a mesma quantidade de multiplicações
//recursivo usa mais memoria por criar varias variaveis e chamar a funcao varias vezes
//equanto o iterativo usa sempre a mesma