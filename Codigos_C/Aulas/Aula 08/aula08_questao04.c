#include <stdio.h>
#include <stdlib.h>

int imprimirNaturais(int N, int atual) {
    if (atual <= N) {
        printf("%d ", atual);
        imprimirNaturais(N, atual + 1);
    }
  return 0;
}

int main() {
    int N;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &N);

    if (N < 0) {
        printf("Por favor, digite um número inteiro positivo.\n");
    } else {
        printf("Números naturais de 0 até %d:\n", N);
        imprimirNaturais(N, 0);
        printf("\n");
    }

    return 0;
}