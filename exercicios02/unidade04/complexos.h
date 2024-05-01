typedef struct{
    double real;
    double imag;
} complexo;

complexo novo_complexo(double real, double imag);

complexo ler_complexo();

void imprimir_complexo(complexo a);

double modulo_complexo(complexo a);

complexo conjugado_complexo(complexo a);

complexo soma_complexo(complexo a, complexo b);

complexo subtracao_complexo(complexo a, complexo b);

complexo multiplicacao_complexo(complexo a, complexo b);

complexo divisao_complexo(complexo a, complexo b);

complexo potencia_complexo(complexo a, int n);