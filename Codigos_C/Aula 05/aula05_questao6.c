// 6. Elabore um programa que leia um número inteiro e exiba a soma dos dígitos pares desse número.
#include <stdio.h>
#include <stdlib.h>
int main(){
  int numero, soma = 0;

    
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    
    int temp = numero;
    while (temp != 0) {
        int digito = temp % 10;
        if (digito%2 == 0) {
        soma += digito;
        }
        temp /= 10;
    }

    
    printf("A soma dos digitos pares de %d eh: %d\n", numero, soma);

  return 0;
}