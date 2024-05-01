#include <stdio.h>
#include <string.h>
#define MAX 100

void imprimir_ate(char s[], char a){
    for(int i=0; i<strlen(s); i++){
        if(s[i] == a) break;
        printf("%c", s[i]);
    }
    printf("\n");
}

int main(){
    char s[MAX], a;
    scanf("%s ", s);
    scanf("%c", &a);
    imprimir_ate(s, a);
}