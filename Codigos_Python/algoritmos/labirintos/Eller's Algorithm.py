# "Eller's Algorithm" (Algoritmo de Eller)

import pygame
import random
import sys

# Definindo algumas cores
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GREEN = (0, 255, 0)

# Tamanho da tela
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
CELL_SIZE = 20

# Número de células na grade
COLS = SCREEN_WIDTH // CELL_SIZE
ROWS = SCREEN_HEIGHT // CELL_SIZE

# Inicializar Pygame
pygame.init()
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Gerador de Labirintos - Eller's Algorithm")
clock = pygame.time.Clock()

# Criar a grade
grid = []
for y in range(ROWS):
    row = []
    for x in range(COLS):
        row.append(0)
    grid.append(row)

# Função para desenhar a grade
def draw_grid():
    screen.fill(BLACK)
    for y in range(ROWS):
        for x in range(COLS):
            if grid[y][x] == 1:
                pygame.draw.rect(screen, GREEN, (x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE))
    pygame.display.flip()

# Função para gerar o labirinto usando Eller's Algorithm
def generate_maze():
    # Começa com cada célula em um conjunto diferente
    sets = [[(x, y)] for y in range(ROWS) for x in range(COLS)]
    current_set = 1  # Identificador do conjunto atual

    for y in range(ROWS):
        # Inicializa os conjuntos da linha atual
        sets_in_row = []

        # Atribui um conjunto para cada célula na linha
        for x in range(COLS):
            sets_in_row.append((x, y, current_set))
            grid[y][x] = current_set

        # Realiza conexões horizontais aleatórias entre conjuntos diferentes
        for x in range(COLS - 1):
            if random.random() < 0.3 or grid[y][x] != grid[y][x + 1]:
                # Conectar células se elas estão em conjuntos diferentes
                grid[y][x + 1] = grid[y][x]
            else:
                # Criar um novo conjunto
                current_set += 1
                grid[y][x + 1] = current_set

        # Determina aleatoriamente se continua para a próxima linha
        if y < ROWS - 1 and random.random() < 0.7:
            # Fusão de conjuntos verticalmente
            for x in range(COLS):
                if random.random() < 0.8:
                    # Conectar com o conjunto abaixo
                    sets[grid[y + 1][x] - 1].extend(sets[grid[y][x] - 1])
                    for cell in sets[grid[y][x] - 1]:
                        grid[cell[1]][cell[0]] = grid[y + 1][x]
            current_set += 1  # Próximo conjunto

        draw_grid()
        pygame.time.delay(30)  # Delay para visualização do processo

# Função principal
def main():
    generate_maze()

    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_r:
                    # Reiniciar o labirinto
                    for y in range(ROWS):
                        for x in range(COLS):
                            grid[y][x] = 0
                    generate_maze()

        draw_grid()
        clock.tick(60)

    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()
