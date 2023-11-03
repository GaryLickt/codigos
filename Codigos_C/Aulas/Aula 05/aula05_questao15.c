// 15. Desenvolva um programa que exiba todos os múltiplos de 3 no intervalo de 1 a 50 utilizando o while.
#include <stdio.h>
#include <stdlib.h>
int main() {
  int x = 1;
  while (x < 51) {
    if (x%3 == 0) {
      printf("%d\n",x);
    }
    x+=1;
  }
  return 0;
}