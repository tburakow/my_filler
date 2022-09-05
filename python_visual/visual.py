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
pygame.display.set_caption("The great visualizer -- by tburakow")

# Loop until window closed.
carryOn = True

# screen update speed
clock = pygame.time.Clock()

def start_visual(map_rows, map_cols):

    rows, cols = map_rows, map_cols
    arr = [[0]*cols]*rows
    
    import sys
    for line in sys.stdin:

    print(f'{line}')


while carryOn:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            carryOn = False
        
        #Put start logic here. Choose players etc.

        #Put the loop stuff here.
        start_visual()

        #draw graphics starts here.
        screen.fill(WHITE)
        pygame.draw.rect(screen, RED, [55, 200, 100, 70], 0)
        pygame.draw.line(screen, BLUE, [0, 0], [100, 100], 5)
        pygame.draw.ellipse(screen, FIGK, [20,20,200,100], 2)

        #updating screen
        pygame.display.flip()

        #framerate
        clock.tick(60)



#exit pygame
pygame.quit()
        