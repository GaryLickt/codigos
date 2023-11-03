// 3. Solicite ao usuário seu nome e imprima uma mensagem de boas-vindas na tela.
#include <stdio.h>
#include <stdlib.h>
int main(){
  printf("Digite seu nome\n");
    char nome[20];
    scanf("%s",&nome);
    printf("Bem-vindo %s\n",nome);
  return 0;
}
