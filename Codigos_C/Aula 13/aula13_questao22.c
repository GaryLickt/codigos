#include <stdio.h>
#include <stdlib.h>

int main() {
  char str[100];
  float valorTotal, valorComDesconto;

  // Solicita o nome da mercadoria
  printf("Digite o nome da mercadoria: ");
  scanf("%s", str);

  // Solicita o valor total da mercadoria
  printf("Digite o valor total da mercadoria: ");
  scanf("%f", &valorTotal);

  // Calcula o valor com desconto (10% de desconto para pagamento à vista)
  valorComDesconto = valorTotal - (valorTotal * 0.10);

  // Imprime os resultados
  printf("\nDetalhes da compra:\n");
  printf("Nome da mercadoria: %s\n", str);
  printf("Valor total: R$ %.2f\n", valorTotal);
  printf("Desconto (10%%): R$ %.2f\n", valorTotal * 0.10);
  printf("Valor a ser pago à vista: R$ %.2f\n", valorComDesconto);

  return 0;
}

