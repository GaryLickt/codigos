#include <stdio.h>
#include <stdlib.h>

int main() {
  float sal, por;
  printf("Digite seu salario: ");
  scanf("%f",&sal);

  if (sal > 1500){
    por = (sal * 10)/100;
  }else{
    por = (sal * 15)/100;
  }
  printf("O Aumento do seu salario sera de: R$%.2f",por);
  
  return 0;
}