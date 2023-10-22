#include <stdio.h>
#include <stdlib.h>

int main() {
  char date[11];
  int day, month, year;

  printf("Digite uma data no formato DD/MM/AAAA: ");
  fgets(date, sizeof(date), stdin);

  if (sscanf(date, "%2d/%2d/%4d", &day, &month, &year) != 3) {
      printf("Formato de Data incorreto, use DD/MM/AAAA.\n");
      return 1;
  }

  if (date[2] != '/' || date[5] != '/') {
      printf("Formato de Data incorreto, use DD/MM/AAAA.\n");
      return 1;
  }

  if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1) {
      printf("Data invalida, use valores numericos.\n");
      return 1;
  }

  printf("Dia: %d\n", day);
  printf("Mês: %d\n", month);
  printf("Ano: %d\n", year);

  return 0;
}

