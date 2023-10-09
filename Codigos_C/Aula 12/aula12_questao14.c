// Nota: Professor, tentei fazer o codigo por conta propria, porem não estava chegando a lugar nenhum, então peguei o codigo que o senhor disponibilizou na aula passada
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber()
{
  int number = rand() % 100;
  // printf("%d\n", number);
  return number;
}

int findNumber(int array[], int arrayLenght, int element)
{
  for (int index = 0; index < arrayLenght; index++)
  {
    int currentElement = array[index];
    if (currentElement == element)
    {
      return index;
    }
  }

  return -1;
}

int main()
{
  srand(time(NULL));

  int matriz[5][5];

  for (int row = 0; row < 5; row++)
  {
    for (int column = 0; column < 5; column++)
    {
      matriz[row][column] = generateRandomNumber();
    }
  }

  for (int row = 0; row < 5; row++)
  {
    for (int column = 0; column < 5; column++)
    {
      printf("%d ", matriz[row][column]);
    }
    printf("\n");
  }

  return 0;
}
