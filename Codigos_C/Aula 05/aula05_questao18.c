// 18. Crie um programa que leia uma sequência de números inteiros do usuário e exiba quantos números pares e quantos números ímpares foram digitados.O programa deve parar de ler quando o usuário digitar o número 0 utilizando o while.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  int x,pares,impares;
  printf("Digite um numero (digite 0 para parar): ");
  scanf("%d",&x);
  pares = 0;
  impares = 0;
  while(x != 0) {
    if (x%2 != 0) {
      impares+=1;
    }
    if (x%2==0) {
      pares+=1;
    }
    printf("Digite um numero (digite 0 para parar): ");
    scanf("%d",&x);
    
  }
  printf("Foram digitados %d numeros pares, e %d numeros impares\n'",pares,impares);
  return 0;
}