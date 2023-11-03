#include <stdio.h>
#include <stdlib.h>

int main() {
    char diaSemana[20];

    printf("Digite o dia da semana (por extenso): ");
    scanf("%s", diaSemana);

    // Converte o dia da semana para letras minúsculas para facilitar a comparação.
    for (int i = 0; diaSemana[i]; i++) {
        diaSemana[i] = tolower(diaSemana[i]);
    }

    // Verifica se é um dia útil ou um fim de semana.
    if (strcmp(diaSemana, "segunda-feira") == 0 || strcmp(diaSemana, "terça-feira") == 0 ||
        strcmp(diaSemana, "quarta-feira") == 0 || strcmp(diaSemana, "quinta-feira") == 0 ||
        strcmp(diaSemana, "sexta-feira") == 0) {
        printf("%s é um dia útil.\n", diaSemana);
    } else if (strcmp(diaSemana, "sábado") == 0 || strcmp(diaSemana, "domingo") == 0) {
        printf("%s é um fim de semana.\n", diaSemana);
    } else {
        printf("Dia da semana inválido.\n");
    }

    return 0;
}