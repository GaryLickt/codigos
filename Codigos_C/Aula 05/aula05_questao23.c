// 23. Elabore um programa que leia uma sequência de números inteiros do usuário e exiba o menor valor digitado que seja positivo e ímpar.O programa deve parar de ler quando o usuário digitar o número 0 utilizando o while.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int main() {
    int num, menor = INT_MAX;
    
    printf("Digite uma sequência de números inteiros (0 para parar):\n");
    
    while (1) {
        printf("Digite um número: ");
        scanf("%d", &num);
        
        if (num == 0) {
            break;
        }
        
        if (num > 0 && num % 2 == 1 && num < menor) {
            menor = num;
        }
    }
    
    if (menor != INT_MAX) {
        printf("Menor valor positivo e ímpar digitado: %d\n", menor);
    } else {
        printf("Nenhum valor positivo e ímpar foi digitado.\n");
    }
    
    return 0;
}