# "Selection Sort"

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
pygame.display.set_caption("Selection Sort Visualization")
clock = pygame.time.Clock()

# Função para desenhar as barras na tela
def draw_bars(arr, colors):
    screen.fill(BACKGROUND_COLOR)
    for i, height in enumerate(arr):
        pygame.draw.rect(screen, colors[i], (i * (BAR_WIDTH + GAP), SCREEN_HEIGHT - height, BAR_WIDTH, height))
    pygame.display.update()

# Função de Selection Sort
def selection_sort(arr, colors):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
        colors[i], colors[min_idx] = RED, GREEN  # Highlight the sorted bars and the currently found minimum
        draw_bars(arr, colors)
        colors[i] = GREEN  # Mark the sorted bars in green
        pygame.time.delay(50)  # Delay for visualization

# Função principal
def main():
    # Gerar um array aleatório de alturas para as barras
    heights = [random.randint(50, 500) for _ in range(NUM_BARS)]
    colors = [BAR_COLOR] * NUM_BARS

    draw_bars(heights, colors)

    running = True
    sorting = False
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_r:
                    # Reiniciar com um novo conjunto aleatório de alturas e cores
                    heights = [random.randint(50, 500) for _ in range(NUM_BARS)]
                    colors = [BAR_COLOR] * NUM_BARS
                    draw_bars(heights, colors)
                    sorting = True

        if sorting:
            selection_sort(heights, colors)
            sorting = False

    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()
