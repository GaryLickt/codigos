// 12. Crie um programa que leia uma sequência de números inteiros do usuário e exiba a média dos números digitados.O programa deve parar de ler quando o usuário digitar o número -1 utilizando o while.
#include <stdio.h>
#include <stdlib.h>
int main() {
    int num, total = 0, count = 0;
    
    printf("Digite uma sequência de números inteiros (-1 para parar):\n");
    
    while (1) {
        printf("Digite um número: ");
        scanf("%d", &num);
        
        if (num == -1) {
            break;
        }
        
        total += num;
        count++;
    }
    
    if (count > 0) {
        double media = (double)total / count;
        printf("Média dos números digitados: %.2lf\n", media);
    } else {
        printf("Nenhum número foi digitado.\n");
    }
    
    return 0;
}