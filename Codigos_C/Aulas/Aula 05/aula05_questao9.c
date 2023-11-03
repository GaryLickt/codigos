// 9. Faça um programa que calcule o produto dos números de 1 a 5 utilizando o while.
#include <stdio.h>
#include <stdlib.h>
int main() {
  int num = 1;
  int count = 2;
  while(count < 6) {
    printf("%d * %d = %d\n",num,count,num*count);
    num *= count;
    count += 1;
  }
  return 0;
}