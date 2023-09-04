#include <stdio.h>
#include <stdlib.h>

int main() {
    char caractere;

    printf("Digite um caractere: ");
    scanf(" %c", &caractere);  

    
    if ((caractere >= 'a' && caractere <= 'z') || (caractere >= 'A' && caractere <= 'Z')) {
        
        if (caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u' ||
            caractere == 'A' || caractere == 'E' || caractere == 'I' || caractere == 'O' || caractere == 'U') {
            printf("O caractere '%c' é uma vogal.\n", caractere);
        } else {
            printf("O caractere '%c' é uma consoante.\n", caractere);
        }
    } else {
        
        printf("O caractere '%c' não é uma letra.\n", caractere);
    }

    return 0;
}