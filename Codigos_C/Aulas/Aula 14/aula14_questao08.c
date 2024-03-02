#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int size = 10; 
  int count = 0; 
  int* numbers = (int*) malloc(size * sizeof(int)); 
  if (numbers == NULL) {
    printf("Falha na alocação de memoria");
    return 0;
  }
  int num;
  while (1) {
    printf("Digite um numero (negativo para encerrar): ");
    scanf("%d", &num);
    if (num < 0) {
      break;
    }
    if (count >= size) {
      size *= 2;
      numbers = (int*) realloc(numbers, size * sizeof(int));
      if (numbers == NULL) {
        printf("Falha na realocação de memoria.");
        return 0;
      }
    }
    numbers[count] = num;
    count++;
  }
  for (int i = 0; i < count; i++) {
    printf("%d ", numbers[i]);
  }
  free(numbers);
  return 0;
}