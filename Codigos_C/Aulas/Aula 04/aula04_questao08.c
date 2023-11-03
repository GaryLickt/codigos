#include <stdio.h>
#include <stdlib.h>

int main() {
    char nome1[100], nome2[100];

    printf("Digite o nome da primeira pessoa: ");
    scanf("%s", nome1);

    printf("Digite o nome da segunda pessoa: ");
    scanf("%s", nome2);

    int tamanho_nome1 = strlen(nome1);
    int tamanho_nome2 = strlen(nome2);

    if (tamanho_nome1 > tamanho_nome2) {
        printf("A primeira pessoa (%s) possui o maior número de caracteres em seu nome.\n", nome1);
    } else if (tamanho_nome2 > tamanho_nome1) {
        printf("A segunda pessoa (%s) possui o maior número de caracteres em seu nome.\n", nome2);
    } else {
        printf("Ambas as pessoas possuem nomes com o mesmo número de caracteres.\n");
    }

    return 0;
}