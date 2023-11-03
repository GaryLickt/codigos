#include <stdio.h>
#include <stdlib.h>

int main() {
    char estadoCivil[20];

    printf("Digite seu estado civil: ");
    scanf("%s", estadoCivil);

    // Converte o estado civil para letras minúsculas para facilitar a comparação.
    for (int i = 0; estadoCivil[i]; i++) {
        estadoCivil[i] = tolower(estadoCivil[i]);
    }

    // Usando a estrutura switch/case para verificar o estado civil.
    switch (estadoCivil[0]) {
        case 's':
            printf("Você é solteiro(a).\n");
            break;
        case 'c':
            printf("Você é casado(a).\n");
            break;
        case 'd':
            printf("Você é divorciado(a).\n");
            break;
        case 'v':
            printf("Você é viúvo(a).\n");
            break;
        default:
            printf("Estado civil inválido.\n");
    }

    return 0;
}