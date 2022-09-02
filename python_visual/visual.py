# Importing pygame library.
import pygame
pygame.init()

#defining colors
BLACK = ( 0, 0, 0)
WHITE = ( 255, 255, 255)
GREEN = ( 0, 255, 0)
RED   = ( 255, 0, 0)
BLUE  = ( 0, 0, 255)
FIGK = ( 34, 87, 200)

# Opening a window
size = (1920, 1280)
screen = pygame.display.set_mode(size)
pygame.display.set_caption("The great visualizer")

# Loop until window closed.
carryOn = True

# screen update speed
clock = pygame.time.Clock