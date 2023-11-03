// 22. Solicite ao usuário que insira dois números decimais e calcule o resto da divisão entre eles.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  double numero1, numero2;

  printf("Digite o primeiro número decimal: ");
  scanf("%lf", &numero1);

  printf("Digite o segundo número decimal: ");
  scanf("%lf", &numero2);

    
  int inteiro1 = (int)numero1;
  int inteiro2 = (int)numero2;

    
  int resto = inteiro1 % inteiro2;

  printf("O resto da divisão entre %d e %d é: %d\n", inteiro1, inteiro2, resto);

    return 0;
}
