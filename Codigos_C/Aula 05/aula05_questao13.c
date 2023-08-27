// 13. Faça um programa que leia um número inteiro e exiba a soma dos seus dígitos elevados ao cubo utilizando o while.
#include <stdio.h>
#include <stdlib.h>
int main() {
  int numero, soma = 0;

    
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    
    int temp = numero;
    while (temp != 0) {
        int digito = temp%10;
        soma += pow((double) digito,(double) 3);
        temp /= 10;
    }

    
    printf("A soma dos digitos de %d elevados ao cubo eh: %d\n", numero, soma);

  return 0;
}