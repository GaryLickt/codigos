#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaração e leitura da matriz de notas
    float notas[10][3];
    
    printf("Digite as notas dos alunos:\n");
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("Nota do aluno %d na prova %d: ", i + 1, j + 1);
            scanf("%f", &notas[i][j]);
        }
    }

    // Inicialização dos arrays para armazenar as piores notas em cada prova
    float piores_notas[3];
    for (int i = 0; i < 3; ++i) {
        piores_notas[i] = notas[0][i];
    }

    // Determinação das piores notas em cada prova
    for (int i = 1; i < 10; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (notas[i][j] < piores_notas[j]) {
                piores_notas[j] = notas[i][j];
            }
        }
    }

    // Contagem do número de alunos com as piores notas em cada prova
    int alunos_piores_nota[3] = {0};
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (notas[i][j] == piores_notas[j]) {
                alunos_piores_nota[j]++;
                break;  // Contabilizar apenas uma vez por aluno
            }
        }
    }

    // Impressão dos resultados
    printf("\nNúmero de alunos com as piores notas em cada prova:\n");
    for (int i = 0; i < 3; ++i) {
        printf("Prova %d: %d aluno(s)\n", i + 1, alunos_piores_nota[i]);
    }

    return 0;
}