// 2. Faça um programa que exiba a soma dos dígitos de um número inteiro fornecido pelo usuário.
#include <stdio.h>
#include <stdlib.h>
int main(){
  int numero, soma = 0;

    
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    
    int temp = numero;
    while (temp != 0) {
        int digito = temp % 10;
        soma += digito;
        temp /= 10;
    }

    
    printf("A soma dos digitos de %d eh: %d\n", numero, soma);

  return 0;
}