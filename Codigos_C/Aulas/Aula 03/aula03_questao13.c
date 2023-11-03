// 13. Receba uma string digitada pelo usuário e imprima o seu tamanho (número de caracteres).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char minhaString[100];

    printf("Digite uma string: ");
    scanf("%s", minhaString);

    int tamanho = strlen(minhaString);

    printf("O tamanho da string é: %d\n", tamanho);

    return 0;
}
