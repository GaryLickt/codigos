// 3. Elabore um programa que leia um número inteiro e exiba todos os seus divisores.
#include <stdio.h>
#include <stdlib.h>
int main(){
  int val;
  printf("Digite um numero inteiro: ");
  scanf("%d",&val);
  int pos = 1;
  int count = val * 10;
  while (pos < count) {
    int calc = val%pos;
    if (calc == 0) {
      printf("%d é um divisor de %d\n",pos,val);
    }
    pos = pos +1;
  }
  return 0;
}