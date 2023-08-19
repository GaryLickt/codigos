// 11. Receba o nome de um animal digitado pelo usuário e exiba uma mensagem informando qual animal foi digitado.
#include <stdio.h>
#include <stdlib.h>

int main() {
    char nomeAnimal[50];

    printf("Digite o nome de um animal: ");
    scanf("%s", nomeAnimal); 

    printf("Você digitou o animal '%s'\n",nomeAnimal);

    return 0;
}

