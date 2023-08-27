// 10. Crie um programa que exiba a tabuada do 9 utilizando o while.
#include <stdio.h>
#include <stdlib.h>
int main() {
  int count = 1;
  while(count < 11) {
    printf("9 x %d = %d\n",count,9*count);
    count+=1;
  }
  return 0;
}