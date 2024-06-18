# "Wilson's Algorithm" (Algoritmo de Wilson)

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
pygame.display.set_caption("Gerador de Labirintos - Wilson's Algorithm")
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

# Função para gerar o labirinto usando Wilson's Algorithm
def generate_maze():
    # Inicializar todas as células como paredes
    for y in range(ROWS):
        for x in range(COLS):
            grid[y][x] = 0
    
    # Escolher uma célula aleatória para começar o caminho
    start_x = random.randint(0, COLS - 1)
    start_y = random.randint(0, ROWS - 1)
    
    grid[start_y][start_x] = 1
    
    # Lista para manter o caminho aleatório atual
    current_path = [(start_x, start_y)]
    
    # Lista para todas as células visitadas
    visited_cells = set()
    visited_cells.add((start_x, start_y))
    
    # Loop até que todas as células sejam visitadas
    while len(visited_cells) < COLS * ROWS:
        # Escolher uma célula aleatória não visitada
        x, y = random.choice(list(set([(x, y) for y in range(ROWS) for x in range(COLS)]) - visited_cells))
        
        # Realizar um random walk começando dessa célula até alcançar uma célula visitada
        random_walk = [(x, y)]
        
        while (x, y) not in visited_cells:
            move_x, move_y = random.choice(moves)
            nx, ny = x + move_x, y + move_y
            
            if is_valid_cell(nx, ny):
                random_walk.append((nx, ny))
                x, y = nx, ny
        
        # Adicionar o caminho aleatório à lista de caminhos atuais
        current_path.extend(random_walk)
        
        # Adicionar todas as células no caminho aleatório à lista de células visitadas
        visited_cells.update(random_walk)
        
        # Desenhar a grade após cada iteração para visualização
        draw_grid()
        pygame.time.delay(30)  # Delay para visualização do processo

        # Aumentar gradualmente a taxa de completude para aumentar a probabilidade de parar
        completion_rate = min(1, len(visited_cells) / (COLS * ROWS))
        if stop_random == 0 and random.random() < completion_rate:
            break

        # Aumentar gradualmente a taxa de completude para aumentar a probabilidade de parar

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
                    generate_maze()

        draw_grid()
        clock.tick(60)

    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()
