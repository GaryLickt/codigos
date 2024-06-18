# "Prim's Algorithm" (Algoritmo de Prim)

import pygame
import random
import sys

# Definindo algumas cores
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GREEN = (0, 255, 0)

stop_random = 0

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
pygame.display.set_caption("Gerador de Labirintos - Prim's Algorithm")
clock = pygame.time.Clock()

# Criar a grade
grid = []
for y in range(ROWS):
    row = []
    for x in range(COLS):
        row.append(0)
    grid.append(row)

# Movimentos possíveis (cima, baixo, esquerda, direita)
moves = [(-1, 0), (1, 0), (0, -1), (0, 1)]

# Função para verificar se uma célula está dentro da grade e não foi visitada
def is_valid_cell(x, y):
    return 0 <= x < COLS and 0 <= y < ROWS and grid[y][x] == 0

# Função para desenhar a grade
def draw_grid():
    screen.fill(BLACK)
    for y in range(ROWS):
        for x in range(COLS):
            if grid[y][x] == 1:
                pygame.draw.rect(screen, GREEN, (x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE))
    pygame.display.flip()

# Função para gerar o labirinto usando Prim's Algorithm
def generate_maze():
    # Inicialização do algoritmo de Prim
    start_x = random.randrange(COLS)
    start_y = random.randrange(ROWS)

    # Conjunto de células já incluídas no labirinto
    in_maze = set()
    in_maze.add((start_x, start_y))
    grid[start_y][start_x] = 1

    # Fila de bordas (edges) a serem escolhidas
    edges = []

    # Adicionar bordas iniciais ao redor da célula inicial
    for move in moves:
        nx, ny = start_x + move[0], start_y + move[1]
        if is_valid_cell(nx, ny):
            edges.append(((start_x, start_y), (nx, ny)))

    # Taxa inicial de completude do labirinto para parar
    total_cells = COLS * ROWS
    cells_visited = len(in_maze)
    completion_rate = 0.1

    while edges:
        # Escolher aleatoriamente uma borda
        edge = random.choice(edges)
        current, next_cell = edge

        if next_cell not in in_maze:
            # Adicionar a próxima célula ao labirinto
            grid[next_cell[1]][next_cell[0]] = 1
            in_maze.add(next_cell)
            cells_visited += 1
            draw_grid()
            pygame.time.delay(30)  # Delay para visualização do processo

            # Adicionar novas bordas ao redor da célula adicionada
            for move in moves:
                nx, ny = next_cell[0] + move[0], next_cell[1] + move[1]
                if is_valid_cell(nx, ny) and (nx, ny) not in in_maze:
                    edges.append((next_cell, (nx, ny)))

            # Calcular a taxa de completude atual do labirinto
            current_completion = cells_visited / total_cells

            # Determinar a probabilidade de parar com base na taxa de completude
            if stop_random == 0 and random.random() < completion_rate * current_completion:
                break  # Encerrar a geração do labirinto

        edges.remove(edge)

        # Aumentar gradualmente a taxa de completude para aumentar a probabilidade de parar
        completion_rate += 0.001

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
