// 14.Faça um programa que exiba os números ímpares de 1 a 100 utilizando o while.
#include <stdio.h>
#include <stdlib.h>
int main() {
  int x = 1;
  while (x < 101) {
    if (x%2 == 1) {
      printf("%d\n",x);
    }
    x+=1;
  }
  return 0;
}