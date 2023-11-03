// 4. Desenvolva um programa que calcule a média de altura de 5 pessoas.
#include <stdio.h>
#include <stdlib.h>
int main(){
  float al,media;
  int cont;
  cont = 0;
  media = 0;
  while (cont < 5) {
    printf("Insira a altura da pessoa %d em metros: ",cont+1);
    scanf("%f",&al);
    media += al;
    cont += 1;
  }
  media = media / cont+1;
  printf("A media da altura entre as 5 pessoas foi de %f\n",media);
  return 0;
}