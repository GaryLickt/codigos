#include <stdio.h>
#include <stdlib.h>

int somaDobro(int *a, int *b) {
    *a = 2 * (*a);
    *b = 2 * (*b);
    return *a + *b;
}

int main() {
    int numeroA, numeroB;

    
    printf("Digite o valor de A: ");
    scanf("%d", &numeroA);

    printf("Digite o valor de B: ");
    scanf("%d", &numeroB);

    
    int resultado = somaDobro(&numeroA, &numeroB);

    
    printf("O dobro de A agora é: %d\n", numeroA);
    printf("O dobro de B agora é: %d\n", numeroB);
    printf("A soma do dobro de A e B é: %d\n", resultado);

    return 0;
}
