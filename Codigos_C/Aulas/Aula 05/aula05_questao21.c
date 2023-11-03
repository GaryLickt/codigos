// 21. Faça um programa que lê uma sequência de números inteiros do usuário e exibe a quantidade de números que possuem mais de três dígitos. O programa para de ler quando o usuário digita o número 0, utilizando o while
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int num, count = 0;
    
    printf("Digite uma sequência de números inteiros (0 para parar):\n");
    
    while (1) {
        printf("Digite um número: ");
        scanf("%d", &num);
        
        if (num == 0) {
            break;
        }
        
        // Conta os números com mais de três dígitos
        if (num >= 1000 || num <= -1000) {
            count++;
        }
    }
    
    printf("Quantidade de números com mais de três dígitos: %d\n", count);
    
    return 0;
}