# "Insertion Sort"

import pygame
import sys
import random

# Configurações da tela
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
BAR_WIDTH = 5
GAP = 1
NUM_BARS = SCREEN_WIDTH // (BAR_WIDTH + GAP)
BAR_COLOR = (0, 128, 255)
BACKGROUND_COLOR = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)

# Inicialização do Pygame
pygame.init()
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Insertion Sort Visualization")
clock = pygame.time.Clock()

# Função para desenhar as barras na tela
def draw_bars(arr, colors):
    screen.fill(BACKGROUND_COLOR)
    for i, height in enumerate(arr):
        pygame.draw.rect(screen, colors[i], (i * (BAR_WIDTH + GAP), SCREEN_HEIGHT - height, BAR_WIDTH, height))
    pygame.display.update()

# Função de Insertion Sort
def insertion_sort(arr, colors):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        # Mudar a cor da barra atual para vermelho
        colors[i] = RED
        draw_bars(arr, colors)
        pygame.time.delay(50)
        
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            colors[j + 1] = RED
            draw_bars(arr, colors)
            pygame.time.delay(50)
            colors[j + 1] = BAR_COLOR
            j -= 1
        arr[j + 1] = key
        # Marcar a barra colocada na posição correta como verde
        colors[i] = GREEN
        draw_bars(arr, colors)
        pygame.time.delay(50)
    
    # Marcar todas as barras como verdes após a ordenação
    for i in range(len(arr)):
        colors[i] = GREEN
        draw_bars(arr, colors)
        pygame.time.delay(10)

# Função principal
def main():
    # Gerar um array aleatório de alturas para as barras
    heights = [random.randint(50, 500) for _ in range(NUM_BARS)]
    colors = [BAR_COLOR] * NUM_BARS

    draw_bars(heights, colors)

    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_r:
                    # Reiniciar com um novo conjunto aleatório de alturas
                    heights = [random.randint(50, 500) for _ in range(NUM_BARS)]
                    colors = [BAR_COLOR] * NUM_BARS
                    draw_bars(heights, colors)
                    insertion_sort(heights, colors)

    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()
