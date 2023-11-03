// 5. Faça um programa que exiba os números de 1 a 100, substituindo os múltiplos de 3 pela palavra "Fizz" e os múltiplos de 5 pela palavra "Buzz".Para os números que são múltiplos de ambos,utilize a palavra "FizzBuzz".
#include <stdio.h>
#include <stdlib.h>
int main(){
  int count = 1;
  while (count < 100){
    if (count%5 == 0 &&  count%3 != 0) {
      printf("Buzz\n");
    }else if (count%3 == 0 &&  count%5 != 0) {
      printf("Fizz\n");
    }else if (count%5 == 0 &&  count%3 == 0) {
      printf("FizzBuzz\n");
    }else{
      printf("%d\n",count);
    }
    count+= 1;
  }
  return 0;
}