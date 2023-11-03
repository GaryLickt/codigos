#include <stdio.h>
#include <stdlib.h>

int trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  return 0;
}

int main() {
    int numero1, numero2;

    
    printf("Digite o valor do primeiro número: ");
    scanf("%d", &numero1);

    printf("Digite o valor do segundo número: ");
    scanf("%d", &numero2);

    printf("Valores antes da troca:\n");
    printf("Primeiro número: %d\n", numero1);
    printf("Segundo número: %d\n", numero2);

    trocar(&numero1, &numero2);

    printf("Valores após a troca:\n");
    printf("Primeiro número: %d\n", numero1);
    printf("Segundo número: %d\n", numero2);

    return 0;
}