#include <stdio.h>
#include <stdlib.h>

int main() {
  char str[5][50];
  float consumos[5];

  // Preenche os vetores com os str e consumos
  for (int i = 0; i < 5; ++i) {
      printf("Digite o modelo do carro %d: ", i + 1);
      scanf("%s", str[i]);

      printf("Digite o consumo do carro %d (km por litro): ", i + 1);
      scanf("%f", &consumos[i]);
  }

  // Encontra o modelo mais econômico
  float menorConsumo = consumos[0];
  int indiceMaisEconomico = 0;
  for (int i = 1; i < 5; ++i) {
      if (consumos[i] < menorConsumo) {
          menorConsumo = consumos[i];
          indiceMaisEconomico = i;
      }
  }

  // Imprime o modelo mais econômico
  printf("O modelo mais econômico é: %s\n", str[indiceMaisEconomico]);

  printf("Consumo para percorrer 1000 km:\n");
  for (int i = 0; i < 5; ++i) {
      float litros = 1000 / consumos[i];
      printf("%s: %.2f litros\n", str[i], litros);
  }

  return 0;
}

