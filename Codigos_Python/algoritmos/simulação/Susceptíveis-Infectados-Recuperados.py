# "Susceptíveis-Infectados-Recuperados"

import pygame
import random
import sys

# Definindo algumas cores
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)

# Tamanho da tela
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600

# Número inicial de indivíduos na população
POPULATION_SIZE = 500

# Taxa de contato (probabilidade de transmissão)
CONTACT_RATE = 0.2

# Taxa de recuperação (probabilidade de recuperação por unidade de tempo)
RECOVERY_RATE = 0.01

# Taxa de nascimento e morte (simulação de fluxo populacional)
BIRTH_DEATH_RATE = 0.005

# Taxa de vacinação (probabilidade de um indivíduo ser imune)
VACCINATION_RATE = 0.3

# Tamanho dos indivíduos na simulação (raio do círculo)
INDIVIDUAL_SIZE = 5

# Inicializar Pygame
pygame.init()
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Modelo SIR - Propagação de Doenças")
clock = pygame.time.Clock()

# Classe para representar um indivíduo na simulação
class Individual:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.state = 'S'  # Inicialmente suscetível
        self.days_infected = 0  # Contador de dias desde a infecção

    def draw(self):
        if self.state == 'S':
            pygame.draw.circle(screen, BLUE, (self.x, self.y), INDIVIDUAL_SIZE)
        elif self.state == 'I':
            pygame.draw.circle(screen, RED, (self.x, self.y), INDIVIDUAL_SIZE)
        elif self.state == 'R':
            pygame.draw.circle(screen, GREEN, (self.x, self.y), INDIVIDUAL_SIZE)
        elif self.state == 'D':
            pygame.draw.circle(screen, BLACK, (self.x, self.y), INDIVIDUAL_SIZE)

    def infect(self):
        if self.state == 'S' and random.random() < CONTACT_RATE:
            self.state = 'I'  # Suscetível se torna infectado

    def recover_or_die(self):
        if self.state == 'I':
            if random.random() < RECOVERY_RATE:
                self.state = 'R'  # Infectado se recupera
            else:
                self.days_infected += 1
                if self.days_infected > 14:  # Indivíduo morre após 14 dias de infecção
                    self.state = 'D'

    def vaccinate(self):
        if random.random() < VACCINATION_RATE and self.state != 'D':
            self.state = 'R'  # Indivíduo suscetível é vacinado e se torna recuperado

# Função para reiniciar a simulação
def reset_simulation():
    global population
    population = [Individual(random.randint(0, SCREEN_WIDTH), random.randint(0, SCREEN_HEIGHT)) for _ in range(POPULATION_SIZE)]

# Inicializar a população inicial
reset_simulation()

# Função principal
def main():
    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_r:
                    reset_simulation()

        # Lógica da simulação
        for individual in population:
            individual.infect()
            individual.recover_or_die()
            individual.vaccinate()

        # Desenhar na tela
        screen.fill(WHITE)
        for individual in population:
            individual.draw()

        pygame.display.flip()
        clock.tick(1)  # Atualizar a cada 1 frames por segundo

    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()
