# Importing pygame library.
import pygame
import time
import os
import sys
import pygame_menu as pgm
pygame.init()

#initial setup of global variables to match menu defaults
p1 = 0
p2 = 0
map_nro = 0
#initial setup of global variable map_size
map_size = []

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

menu = pgm.Menu(
    height=800,
    theme=pgm.themes.THEME_SOLARIZED,
    title='SETUP',
    width=1080
)
# function to read the firt lines from stdin and parse for map size etc.
def get_map_size():
	x = 0
	# loop until we have reached string with "Plateau" 
	while x != 1:
		# read a line from stdin
		line = sys.stdin.readline()
		print(line)
		# if we find string which contains the word "Plateau"
		if (line.find("Plateau")):
			#access global variable map_size
			global map_size
			#for loop to split and append the string into map_size
			for z in line.split():
				if z.isdigit():
					map_size.append(int(z))
			x = 1
	pass

# function to define player one 
def set_player_one(value, player):
	# access global variable p1
	global p1
	# set global variable p1
	p1 = player
	#print(p1)
	pass

# function to define player two
def set_player_two(value, player):
	# access global variable p2
	global p2
	# set global variable p2
	p2 = player
	#print(p2)
	pass

# function to define map
def set_map(value, map):
	#access global variable map_nro
	global map_nro
	# set global variable map_nro
	map_nro = map
	#print(map_nro)
	pass

def start_visual():
	# Loop until window closed.
	carryOn = True

	# screen update speed
	clock = pygame.time.Clock()

	# arrays for players and maps
	arr1 = ["tburakow", "carli", "abanlin", "champely", "grati", "hcao", "superjeannot"]
	arr2 = ["map00", "map01", "map02"]

	# create the command
	command = "../resources/filler_vm -p1 ../resources/players/\"{0}\".filler -p2 ../resources/players/\"{1}\".filler -v -f ../resources/maps/\"{2}\"".format(arr1[p1], arr1[p2], arr2[map_nro])

	# run the filler_vm
	os.system(command)

	time.sleep(0.1)
	# getting the correct map size from the initial output
	get_map_size()

	#pygame -loop
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

menu.add.selector('Player 1 :', [('tburakow', 0), ('carli', 1), ('abanlin', 2), ('champely', 3), ('grati', 4), ('hcao', 5), ('superjeannot', 6)], onchange=set_player_one)
menu.add.selector('Player 1 :', [('tburakow', 0), ('carli', 1), ('abanlin', 2), ('champely', 3), ('grati', 4), ('hcao', 5), ('superjeannot', 6)], onchange=set_player_two)
menu.add.selector('Map :', [('small', 0), ('medium', 1), ('large', 2)], onchange=set_map)
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


        