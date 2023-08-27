// 17. Elabore um programa que leia uma sequência de números inteiros do usuário e determine quantos números pares foram digitados antes do primeiro número ímpar.O programa deve parar de ler quando o usuário digitar o número 0 utilizando o while.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  int x,pares,numeroipa;
  bool numeroImpar = false;
  printf("Digite um numero (digite 0 para parar): ");
  scanf("%d",&x);
  pares = 0;
  while(x != 0) {
    if (x%2 != 0 && numeroImpar == false) {
      numeroImpar = true;
      numeroipa = x;
    }
    if (x%2==0 && numeroImpar == false) {
      pares+=1;
    }
    printf("Digite um numero (digite 0 para parar): ");
    scanf("%d",&x);
    
  }
  printf("Foram digitados %d antes do numero impar '%d'",pares,numeroipa);
  return 0;
}