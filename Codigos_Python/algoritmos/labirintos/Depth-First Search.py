# "Depth-First Search" (Algoritmo)

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
pygame.display.set_caption("Gerador de Labirintos - DFS")
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

# Função para gerar o labirinto usando DFS
def generate_maze(x, y):
    stack = [(x, y)]
    grid[y][x] = 1
    total_cells = COLS * ROWS
    cells_visited = 1
    completion_rate = 0.1  # Taxa inicial de completude do labirinto para parar

    while stack:
        current = stack.pop()
        x, y = current
        valid_moves = []

        for move in moves:
            nx, ny = x + move[1], y + move[0]
            if is_valid_cell(nx, ny):
                valid_moves.append((nx, ny))

        random.shuffle(valid_moves)  # Embaralha as direções para obter aleatoriedade

        for move in valid_moves:
            nx, ny = move
            if not grid[ny][nx]:  # Se a célula não foi visitada
                grid[ny][nx] = 1
                stack.append((nx, ny))
                cells_visited += 1
                draw_grid()
                pygame.time.delay(30)  # Delay para visualização do processo

                # Calcular a taxa de completude atual do labirinto
                current_completion = cells_visited / total_cells

                # Determinar a probabilidade de parar com base na taxa de completude
                if stop_random == 0 and random.random() < completion_rate * current_completion:
                    return  # Encerrar a geração do labirinto se a probabilidade for atendida

        # Aumentar gradualmente a taxa de completude para aumentar a probabilidade de parar
        completion_rate += 0.001

# Função principal
def main():
    a = random.randrange(0, COLS)
    b = random.randrange(0, ROWS)
    generate_maze(a, b)

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
                    a = random.randrange(0, COLS)
                    b = random.randrange(0, ROWS)
                    generate_maze(a, b)

        draw_grid()
        clock.tick(60)

    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()
