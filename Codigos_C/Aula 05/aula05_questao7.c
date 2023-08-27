// 7. Faça um programa que leia um número inteiro e exiba o número invertido. Por exemplo, se o número lido for 123,o programa deve exibir 321.
#include <stdio.h>
#include <stdlib.h>
int main() {
    int num, reversed = 0;
    
    printf("Digite um número inteiro: ");
    scanf("%d", &num);
    
    while (num != 0) {
        int remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    
    printf("Número invertido: %d\n", reversed);
    
    return 0;
}