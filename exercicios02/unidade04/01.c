#include <stdio.h>
#include "complexos.h"

int main() {
    complexo a, b, c;
    a = ler_complexo();
    b = ler_complexo();

    printf("modulos: %lf / %lf\n", modulo_complexo(a), modulo_complexo(b));

    printf("conjugados: ");
    c = conjugado_complexo(a);
    imprimir_complexo(c);
    printf(" / ");
    c = conjugado_complexo(b);
    imprimir_complexo(c);
    printf("\n");

    c = soma_complexo(a, b);
    printf("soma: ");
    imprimir_complexo(c);
    printf("\n");

    c = subtracao_complexo(a, b);
    printf("subtracao: ");
    imprimir_complexo(c);
    printf("\n");

    c = multiplicacao_complexo(a, b);
    printf("multiplicacao: ");
    imprimir_complexo(c);
    printf("\n");

    c = divisao_complexo(a, b);
    printf("divisao: ");
    imprimir_complexo(c);
    printf("\n");

    int n;
    scanf("%d", &n);

    printf("potencias: ");
    c = potencia_complexo(a, n);
    imprimir_complexo(c);
    printf(" / ");
    c = potencia_complexo(b, n);
    imprimir_complexo(c);
    printf("\n");

    return 0;
}