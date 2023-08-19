// 31. Receba uma string contendo um endereço de e-mail e concatene-a com uma mensagem de agradecimento personalizada.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char email[100];
  printf("Insira seu email:\n");
  scanf("%s",&email);
  printf("Obrigado por cadastrar seu email '%s', entraremos em contato em breve!\n",email);
  return 0;
}
