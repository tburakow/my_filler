# Importing pygame library.
import pygame
import pygame_menu as pgm
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

p1 = 1
p2 = 1
map = 1

menu = pgm.Menu(
    height=800,
    theme=pgm.themes.THEME_SOLARIZED,
    title='SETUP',
    width=1080
)

def set_player_one(value, player):
    p1 = value
    pass

def set_player_two(value, player):
    p2 = value
    pass

def set_map(value, map):
    map = value
    pass

def start_visual():
	# Loop until window closed.
	carryOn = True

	# screen update speed
	clock = pygame.time.Clock()

	while carryOn:
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				carryOn = False
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

menu.add.selector('Player 1 :', [('tburakow', 1), ('carli', 2)], onchange=set_player_one)
menu.add.selector('Player 2 :', [('tburakow', 1), ('carli', 2)], onchange=set_player_two)
menu.add.selector('Map :', [('small', 1), ('medium', 2), ('large', 3)], onchange=set_map)
menu.add.button('Play', start_visual)
menu.add.button('Quit', pgm.events.EXIT)

menu.mainloop(screen)

""" while carryOn:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            carryOn = False
        
        #Put start logic here. Choose players etc.
        
        #Put the loop stuff here.
		

        #draw graphics starts here.
        screen.fill(WHITE)
        pygame.draw.rect(screen, RED, [55, 200, 100, 70], 0)
        pygame.draw.line(screen, BLUE, [0, 0], [100, 100], 5)
        pygame.draw.ellipse(screen, FIGK, [20,20,200,100], 2)

        #updating screen
        pygame.display.flip()

        #framerate
        clock.tick(60) """


        