#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "complexos.h"

complexo novo_complexo(double real, double imag){
    complexo c;
    c.real = real;
    c.imag = imag;
    return c;
}

complexo ler_complexo(){
    complexo c;
    scanf("%lf %lf", &c.real, &c.imag);
    return c;
}

void imprimir_complexo(complexo a){
    printf("(%lf) + i(%lf)", a.real, a.imag);
}

double modulo_complexo(complexo a){
    double mod;
    mod = sqrt(a.real * a.real + a.imag * a.imag);
    return mod;
}

complexo conjugado_complexo(complexo a){
    complexo c;
    c.real = a.real;
    c.imag = -a.imag;
    return c;
}

complexo soma_complexo(complexo a, complexo b){
    complexo c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

complexo subtracao_complexo(complexo a, complexo b){
    complexo c;
    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;
    return c;
}

complexo multiplicacao_complexo(complexo a, complexo b){
    complexo c;
    c.real = a.real * b.real - a.imag * b.imag;
    c.imag = a.real * b.imag + a.imag * b.real;
    return c;
}

complexo divisao_complexo(complexo a, complexo b){
    complexo c;
    complexo d = conjugado_complexo(b);
    double mod = modulo_complexo(b);

    c = multiplicacao_complexo(a, d);

    if(mod == 0){
        printf("divisao por 0\n");
        assert(0);
    }

    c.real /= (mod*mod);
    c.imag /= (mod*mod);
    return c;
}

complexo potencia_complexo(complexo a, int n){
    complexo c;
    c.real = 1;
    c.imag = 0;
    for(int i=0; i<n; i++){
        c = multiplicacao_complexo(a, c);
    }
    return c;
}