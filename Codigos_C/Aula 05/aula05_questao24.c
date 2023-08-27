// 24. Faça um programa que leia uma sequência de números inteiros do usuário e exiba quantos números são pares e quantos números são ímpares entre o primeiro e o último número digitado.O programa deve parar de ler quando o usuário digitar o número 0 utilizando o while.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int main() {
    int primeiro, ultimo, num;
    int pares = 0, impares = 0;
    
    printf("Digite uma sequência de números inteiros (0 para parar):\n");
    
    printf("Digite o primeiro número: ");
    scanf("%d", &primeiro);
    
    if (primeiro != 0) {
        ultimo = primeiro;
        
        while (1) {
            printf("Digite um número: ");
            scanf("%d", &num);
            
            if (num == 0) {
                break;
            }
            
            if (num % 2 == 0) {
                pares++;
            } else {
                impares++;
            }
            
            ultimo = num;
        }
        
        printf("Quantidade de números pares: %d\n", pares);
        printf("Quantidade de números ímpares: %d\n", impares);
    } else {
        printf("Nenhum número foi digitado.\n");
    }
    
    return 0;
}