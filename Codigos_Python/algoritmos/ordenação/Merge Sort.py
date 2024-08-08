# "Merge Sort"

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
HIGHLIGHT_COLOR = (255, 0, 0)
GREEN = (0, 255, 0)

# Inicialização do Pygame
pygame.init()
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Merge Sort Visualization")
clock = pygame.time.Clock()

# Função para desenhar as barras na tela
def draw_bars(arr, colors):
    screen.fill(BACKGROUND_COLOR)
    for i, height in enumerate(arr):
        pygame.draw.rect(screen, colors[i], (i * (BAR_WIDTH + GAP), SCREEN_HEIGHT - height, BAR_WIDTH, height))
    pygame.display.update()

# Função de Merge Sort
def merge_sort(arr, colors, start, end):
    if end - start > 1:
        mid = (start + end) // 2
        merge_sort(arr, colors, start, mid)
        merge_sort(arr, colors, mid, end)
        merge(arr, colors, start, mid, end)

def merge(arr, colors, start, mid, end):
    left = arr[start:mid]
    right = arr[mid:end]
    left_colors = colors[start:mid]
    right_colors = colors[mid:end]

    k = start
    i = 0
    j = 0
    while start + i < mid and mid + j < end:
        if left[i] <= right[j]:
            arr[k] = left[i]
            colors[k] = left_colors[i]
            i += 1
        else:
            arr[k] = right[j]
            colors[k] = right_colors[j]
            j += 1
        k += 1

    while start + i < mid:
        arr[k] = left[i]
        colors[k] = left_colors[i]
        i += 1
        k += 1

    while mid + j < end:
        arr[k] = right[j]
        colors[k] = right_colors[j]
        j += 1
        k += 1

    draw_bars(arr, colors)
    pygame.time.delay(50)  # Delay para visualização

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
                    merge_sort(heights, colors, 0, len(heights))

    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()
