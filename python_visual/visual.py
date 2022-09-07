# Importing pygame library.
import pygame
import time
import os
import pygame_menu as pgm
pygame.init()

#initial setup of global variables to match menu defaults
p1 = 0
p2 = 0
map_nro = 0

#initial setup of global variable map_size
map_size = []

# defining the player and map lists.
arr1 = ["tburakow", "carli", "abanlin", "champely", "grati", "hcao", "superjeannot"]
arr2 = ["map00", "map01", "map02"]

# setup of global variable file1, this variable will eventually contain all the game progression.
file1 = 0

#defining colors
BLACK = ( 0, 0, 0)
WHITE = ( 255, 255, 255)
GREEN = ( 0, 255, 0)
RED   = ( 255, 0, 0)
BLUE  = ( 0, 0, 255)
FIGK = ( 34, 87, 200)
ORANGE = ( 255, 191, 0)
ORANKI = ( 255, 230, 0)
PURPLE = ( 106, 13, 173)
PURPUL = ( 150, 50, 200)

# Opening a window
size = (1800, 1200)
screen = pygame.display.set_mode(size)
pygame.display.set_caption("The great visualizer -- by tburakow")

menu = pgm.Menu(
    height=800,
    theme=pgm.themes.THEME_SOLARIZED,
    title='SETUP',
    width=1080
)

# function to get the current map
def parse_and_read_map():
	# creating the correct size squares.
	square_h = bg_h / map_size[0] # we divide the map(background) area with the number of squares each way
	square_w = bg_w / map_size[1]
	square = pygame.Rect(0, 0, square_w, square_h, border_radius=5)
	global file1
	line = file1.readline().rstrip(':\n')
	while (line.find("Plateau") == -1): # read lines of file until we reach 
		line = file1.readline().rstrip(':\n')
	x = 0
	while x < map_size[0]:
		line = file1.readline().rstrip(':\n')
		sans_digits = ''.join([i for i in line if not i.isdigit()]) #iterate through the string removing numbers.
		y = 0
		while y < map_size[1]:
			if sans_digits.find('X', y, y + 1) != -1:
				square.left = (900 - bg_w / 2) + (y * square_w)
				square.top = (620 - bg_h / 2) + (x * square_h)
				pygame.draw.rect(screen, PURPLE, square)
			if sans_digits.find('x', y, y + 1) != -1:
				square.left = (900 - bg_w / 2) + (y  * square_w)
				square.top = (620 - bg_h / 2) + (x * square_h)
				pygame.draw.rect(screen, PURPUL, square)
			if sans_digits.find('O', y, y + 1) != -1:
				square.left = (900 - bg_w / 2) + (y * square_w)
				square.top = (620 - bg_h / 2) + (x  * square_h)
				pygame.draw.rect(screen, ORANGE, square)
			if sans_digits.find('o', y, y + 1) != -1:
				square.left = (900 - bg_w / 2) + (y * square_w)
				square.top = (620 - bg_h / 2) + (x * square_h)
				pygame.draw.rect(screen, ORANKI, square)
			y += 1
		#the_map = arr.array('b', [])
		#the_map[x] = sans_digits
		x += 1
	return


# function to read the firt lines from stdin and parse for map size etc.
def get_map_size():
	x = 0
	global file1
	file1 = open('temp_text', 'r')
	# loop until we have reached string with "Plateau" 
	while x < 10:
		# read a line from stdin
		line = file1.readline().rstrip(':\n')
		# if we find string which contains the word "Plateau"
		if (line.find("Plateau") != -1):
			#access global variable map_size
			global map_size
			#for loop to split and append the string into map_size
			for z in line.split():
				if z.isdigit():
					map_size.append(int(z))
			
		x += 1		
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

	# create the command
	command = "../resources/filler_vm -p1 ../resources/players/\"{0}\".filler -p2 ../resources/players/\"{1}\".filler -v -f ../resources/maps/\"{2}\" > temp_text".format(arr1[p1], arr1[p2], arr2[map_nro])

	# run the filler_vm
	os.system(command)

	time.sleep(0.1)
	# getting the correct map size from the initial output
	get_map_size()

	print(map_size)

	# Setting up variable speed, default setting : 1
	speed = 80

	#pygame -loop
	while carryOn:
		global bg_h
		global bg_w
		#draw graphics starts here.
		screen.fill(WHITE)
		pygame.draw.rect(screen, BLACK, [50, 40, 1700, 1100], 0, border_radius=20)

		#defining font for diplaying the players and map.
		displayfont = pygame.font.Font("/Library/Fonts/Trebuchet MS Bold.ttf", 32)

		# creating the player 1 text to print on screen
		p1_pre = ('Player 1: \"{0}\"'.format(arr1[p1])) # creating the string
		p1_post = p1_pre.replace('"', '') # removing the double quotes.
		p1_text = displayfont.render(p1_post, True, ORANGE) #create text object
		p1_rect = p1_text.get_rect() # create text rectangle
		p1_rect.left = (100) # distance from left edge
		p1_rect.top = (80) # distance from top edge

		# creating player 2 text to print on screen
		p2_pre = ('Player 2: \"{0}\"'.format(arr1[p2])) # creating the string
		p2_post = p2_pre.replace('"', '') # removing the double quotes.
		p2_text = displayfont.render(p2_post, True, PURPLE) #create text object
		p2_rect = p2_text.get_rect() # create text rectangle
		p2_rect.right = (1700) # distance from right edge
		p2_rect.top = (80) # distance from top edge

		# creating map info on screen.
		map_pre = ('\"{0}\"'.format(arr2[map_nro])) # creating the string
		map_post = map_pre.replace('"', '') # removing the double quotes.
		map_text = displayfont.render(map_post, True, GREEN) #create text object
		map_rect = map_text.get_rect() # create text rectangle
		map_rect.center = (900, 80) # position of center of object

		# creating map bg
		if map_size[0] > map_size[1]: # if map is higher than it is wide. We set height at max.
			bg_h = 1000
			bg_w = bg_h * (map_size[1] / map_size[0])
		else: # if map is wider than it is high. We set width at max.
			bg_w = 1000
			bg_h = bg_w * (map_size[0] / map_size[1])
		map_bg = pygame.Rect(0, 0, bg_w, bg_h)
		map_bg.center = (900, 620)
		map_bg_bord = pygame.Rect(0, 0, bg_w + 40, bg_h + 40, border_radius=15) #this second one is a border for the actual bg.
		map_bg_bord.center = (900, 620)

		# creating the correct size squares.
		square_h = bg_h / map_size[0] # we divide the map(background) area with the number of squares each way
		square_w = bg_w / map_size[1]
		square = pygame.Rect(0, 0, square_w, square_h, border_radius=5)
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				command = "rm temp_text"
				carryOn = False

		# placing the texts on screen.
		screen.blit(p1_text, p1_rect)
		screen.blit(p2_text, p2_rect)
		screen.blit(map_text, map_rect)

		# drawing the map background on screen, border first.
		pygame.draw.rect(screen, RED, map_bg_bord)
		pygame.draw.rect(screen, BLUE, map_bg)

		# keystrokes to control the speed. 0 = pause, 9 = full speed. 
		
		# check if match ended 

		# fetching the map situation.
		parse_and_read_map()

		#time.sleep(0.5 / speed)
		# check if match ended 


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




        