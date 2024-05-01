#include <stdio.h>

/*
para calcular b^n, basta calcular b^(n/2)
se n é par, b^n = b^(n/2) * b^(n/2)
se n é ímpar, b^n = b * b^(n/2) * b^(n/2)

Assim, fazemos, no máximo O(lg(n)) operações
*/

double potencia_recursiva(double b, int n){
    if(n == 0){
        return 1;
    }
    double k = potencia_recursiva(b, n/2);

    k = k * k;

    if(n % 2 == 0){
        return k;
    }

    else {
        return b * k;
    }
}

/*
Se n é ímpar, pot = pot * b:
    assim como no caso anterior b^n = b * b^(n/2) * b^(n/2), se n é ímpar
n = n/2, para dividir o n na metade
b = b*b, para compensar a divisão do n

Fica mais claro olhando o expoente na base 2:
Exemplo n = 10101 (base 2)

(b, n , pot) = (b^1, 10101, 1)
(b, n , pot) = (b^10, 1010, b^1)
(b, n , pot) = (b^100, 101, b^1)
(b, n , pot) = (b^1000, 10, b^101)
(b, n , pot) = (b^10000, 1, b^101)
(b, n , pot) = (b^100000, 0, b^10101)
*/

double potencia_iterativa(double b, int n){
    double pot = 1;

    while(n > 0){
        if(n % 2 == 1){
            pot = pot * b;
        }

        n = n/2;
        b = b * b;
    }

    return pot;
}

int main(){
    double base;
    int exp;
    
    scanf("%lf %d", &base, &exp);
    printf("%lf\n", potencia_iterativa(base, exp));
    printf("%lf\n", potencia_recursiva(base, exp));
}