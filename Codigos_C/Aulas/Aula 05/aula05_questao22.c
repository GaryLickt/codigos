// 22. Desenvolva um programa que leia uma sequência de números inteiros do usuário e exiba a média dos números que estão entre 50 e 100.O programa deve parar de ler quando o usuário digitar o número 0 utilizando o while.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int num, total = 0, count = 0;
    
    printf("Digite uma sequência de números inteiros (0 para parar):\n");
    
    while (1) {
        printf("Digite um número: ");
        scanf("%d", &num);
        
        if (num == 0) {
            break;
        }
        
        if (num >= 50 && num <= 100) {
            total += num;
            count++;
        }
    }
    
    if (count > 0) {
        double media = (double)total / count;
        printf("Média dos números entre 50 e 100: %.2lf\n", media);
    } else {
        printf("Nenhum número entre 50 e 100 foi digitado.\n");
    }
    
    return 0;
}