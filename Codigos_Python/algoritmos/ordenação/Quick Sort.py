# "Quick Sort"

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
YELLOW = (255, 255, 0)

# Inicialização do Pygame
pygame.init()
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Quick Sort Visualization")
clock = pygame.time.Clock()

# Função para desenhar as barras na tela
def draw_bars(arr, colors):
    screen.fill(BACKGROUND_COLOR)
    for i, height in enumerate(arr):
        pygame.draw.rect(screen, colors[i], (i * (BAR_WIDTH + GAP), SCREEN_HEIGHT - height, BAR_WIDTH, height))
    pygame.display.update()

# Função de Quick Sort
def quick_sort(arr, low, high, colors):
    if low < high:
        pi = partition(arr, low, high, colors)
        quick_sort(arr, low, pi - 1, colors)
        quick_sort(arr, pi + 1, high, colors)

def partition(arr, low, high, colors):
    pivot = arr[high]
    colors[high] = RED
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
            colors[i], colors[j] = YELLOW, YELLOW
            draw_bars(arr, colors)
            colors[i], colors[j] = BAR_COLOR, BAR_COLOR
            pygame.time.delay(10)
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    colors[i + 1] = GREEN
    draw_bars(arr, colors)
    colors[high] = BAR_COLOR
    pygame.time.delay(10)
    return i + 1

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
            quick_sort(heights, 0, len(heights) - 1, colors)
            sorting = False

    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()
