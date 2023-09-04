#include <stdio.h>
#include <stdlib.h>

int main() {
  int x;
  printf("Digite um numero entre 1 e 7: ");
  scanf("%d",&x);
  switch(x){
    case 1: printf("O dia da semana de numero 1 é o Domingo.\n");break;
    case 2: printf("O dia da semana de numero 2 é a Segunda-feira.\n");break;
    case 3: printf("O dia da semana de numero 3 é a Terça-feira.\n");break;
    case 4: printf("O dia da semana de numero 4 é a Quarta-feira.\n");break;
    case 5: printf("O dia da semana de numero 5 é a Quinta-feira.\n");break;
    case 6: printf("O dia da semana de numero 6 é a Sexta-feira.\n");break;
    case 7: printf("O dia da semana de numero 5 é o Sabado.\n");break;
  }
  return 0;
}