#include <stdio.h>
#include <stdlib.h>

int calcularSoma(int *a, int b) {
    *a = *a + b;
  return 0;
}

int main() {
    int numeroA, numeroB;

    printf("Digite o valor de A: ");
    scanf("%d", &numeroA);

    printf("Digite o valor de B: ");
    scanf("%d", &numeroB);

    calcularSoma(&numeroA, numeroB);

    printf("Valor de A após a soma: %d\n", numeroA);
    printf("Valor de B: %d\n", numeroB);

    return 0;
}
