// 11. Crie um programa que leia uma sequência de números inteiros do usuário e exiba o maior e o menor valor digitado.O programa deve parar de ler quando o usuário digitar o número 0 utilizando o while.
#include <stdio.h>
#include <stdlib.h>
int main() {
    int num, maior, menor;
    int primeiroNumero = 1; // Flag para identificar o primeiro número
    
    printf("Digite uma sequência de números inteiros (0 para parar):\n");
    
    while (1) {
        printf("Digite um número: ");
        scanf("%d", &num);
        
        if (primeiroNumero) {
            maior = menor = num;
            primeiroNumero = 0;
        } else {
            if (num == 0) {
                break;
            }
            
            if (num > maior) {
                maior = num;
            }
            
            if (num < menor) {
                menor = num;
            }
        }
    }
    
    printf("Maior valor digitado: %d\n", maior);
    printf("Menor valor digitado: %d\n", menor);
    
    return 0;
}