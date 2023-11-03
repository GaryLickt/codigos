// 8. Elabore um programa que calcule a soma dos números de 1 a 100 utilizando o while.
#include <stdio.h>
#include <stdlib.h>
int main() {
  int num = 1;
  int count = 1;
  while(count < 101) {
    printf("%d + %d = %d\n",num,count,num+count);
    num += count;
    count += 1;
  }
  return 0;
}