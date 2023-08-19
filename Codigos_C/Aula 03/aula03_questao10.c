// 10. Solicite ao usuário uma sequência de números separados por espaço e exiba quantos números foram digitados.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero;
    int contador = 0;

    printf("Digite uma sequência de números separados por espaço:\n");
    // recado: Enquanto a entrada for algum valor inteiro, o loop vai continuar infinitamente
    while (scanf("%d", &numero) == 1) {
        contador++;
    }

    printf("Foram digitados %d números na sequência.\n", contador);

    return 0;
}
