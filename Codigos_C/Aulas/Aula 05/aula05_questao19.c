// 19. Faça um programa que leia uma sequência de números inteiros do usuário e exiba quantos números são divisíveis por 2, quantos são divisíveis por 3 e quantos são divisíveis por 5.O programa deve parar de ler quando o usuário digitar o número 0 utilizando o while.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  int x,por2,por3,por5,por23,por35,por25;
  printf("Digite um numero (digite 0 para parar): ");
  scanf("%d",&x);
  por2 = 0;
  por3 = 0;
  por5 = 0;
  por23 = 0;
  por25 = 0;
  por35 = 0;
  while(x != 0) {
    if (x%3==0 && x%2!=0 && x%5!=0) {
      por3+=1;
    }else if (x%5==0 && x%2!=0 && x%3!=0) {
      por5+=1;
    }else if (x%2==0 && x%3!=0 && x%5!=0) {
      por2+=1;
    }else if (x%5==0 && x%2==0 && x%3!=0) {
      por25+=1;
    }else if (x%3==0 && x%2==0 && x%5!=0) {
      por23+=1;
    }else if (x%5==0 && x%3==0 && x%2!=0) {
      por35+=1;
    }
    printf("Digite um numero (digite 0 para parar): ");
    scanf("%d",&x);
    
  }
  printf("Foram digitados %d numeros divisíveis somente por 2\n",por2);
  printf("Foram digitados %d numeros divisíveis somente por 3\n",por3);
  printf("Foram digitados %d numeros divisíveis somente por 5\n",por5);
  printf("Foram digitados %d numeros divisíveis somente por 2 e 3\n",por23);
  printf("Foram digitados %d numeros divisíveis somente por 2 e 5\n",por25);
  printf("Foram digitados %d numeros divisíveis somente por 3 e 5\n",por35);
  return 0;
}