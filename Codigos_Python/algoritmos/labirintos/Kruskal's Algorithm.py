# "Kruskal's Algorithm" (Algoritmo de Kruskal)

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
pygame.display.set_caption("Gerador de Labirintos - Kruskal's Algorithm")
clock = pygame.time.Clock()

# Lista para armazenar as arestas do labirinto
edges = []

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

# Função para verificar se duas células pertencem a diferentes conjuntos
def find(parent, i):
    if parent[i] == i:
        return i
    else:
        return find(parent, parent[i])

# Função para unir dois conjuntos de células
def union(parent, rank, x, y):
    root_x = find(parent, x)
    root_y = find(parent, y)

    if root_x != root_y:
        if rank[root_x] > rank[root_y]:
            parent[root_y] = root_x
        elif rank[root_x] < rank[root_y]:
            parent[root_x] = root_y
        else:
            parent[root_y] = root_x
            rank[root_x] += 1

# Função para gerar as arestas do labirinto
def generate_edges():
    edges = []
    for y in range(ROWS):
        for x in range(COLS):
            # Adiciona todas as arestas que podem ser adicionadas, incluindo as da borda
            if x > 0:
                edges.append(((x, y), (x - 1, y)))
            if x < COLS - 1:
                edges.append(((x, y), (x + 1, y)))
            if y > 0:
                edges.append(((x, y), (x, y - 1)))
            if y < ROWS - 1:
                edges.append(((x, y), (x, y + 1)))
    return edges

# Função principal para gerar o labirinto com Kruskal's Algorithm
def generate_maze():
    global edges

    parent = {}
    rank = {}
    for y in range(ROWS):
        for x in range(COLS):
            parent[(x, y)] = (x, y)
            rank[(x, y)] = 0

    edges = generate_edges()
    random.shuffle(edges)

    for edge in edges:
        (x1, y1), (x2, y2) = edge
        if find(parent, (x1, y1)) != find(parent, (x2, y2)):
            grid[y1][x1] = 1
            grid[y2][x2] = 1
            union(parent, rank, (x1, y1), (x2, y2))
            draw_grid()
            pygame.time.delay(30)

            # Calcular a taxa de completude atual do labirinto
            cells_visited = sum(sum(row) for row in grid)
            total_cells = COLS * ROWS
            current_completion = cells_visited / total_cells

            # Determinar a probabilidade de parar com base na taxa de completude
            if stop_random == 0 and random.random() < 0.1 * current_completion:
                break

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
