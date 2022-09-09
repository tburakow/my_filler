# Importing pygame library.
from email.utils import encode_rfc2231
from xml.dom.pulldom import END_DOCUMENT
import pygame
import time
import os
from pygame import mixer
import pygame_menu as pgm

pygame.init() # initialize pygame
mixer.init() # initialize mixer 

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
GREEN = ( 0, 205, 0)
LGREEN = ( 50, 255, 0)
RED   = ( 255, 0, 0)
BLUE  = ( 0, 0, 150)
FIGK = ( 34, 87, 200)
ORANGE = ( 255, 191, 0)
ORANKI = ( 255, 230, 0)
PURPLE = ( 106, 13, 173)
PURPUL = ( 190, 50, 220)

# values for playyer scores
end_one = 0
end_two = 0 

# Opening a window
size = (1800, 1200)
screen = pygame.display.set_mode(size)

# loading menu background image
background_image = pgm.BaseImage(
    image_path=("title.png")
)
pygame.display.set_caption("The great visualizer -- by tburakow")

# loading title.
#title = pygame.image.load("title.png")

# update the screen.
#pygame.display.flip()

#drawing title on screen.
#screen.blit(title, (0, 0))
# creating theme for the menu:
myfont = pgm.font.FONT_8BIT
titlefont = pgm.font.FONT_COMIC_NEUE
tumetheme = pgm.Theme(background_color=(255, 255, 0, 0),
					title_background_color=(0, 0, 0, 0),
					title_font_shadow=True,
					widget_padding=25,
					title_font=titlefont,
					widget_font=myfont,
					widget_font_color=GREEN
					)
tumetheme.background_color = background_image
pgm.locals.POSITION_SOUTH

menu = pgm.Menu(
    height=1200,
    theme=tumetheme,
    title='SETUP',
    width=1800
)

# defining menu background
def main_background():
	background_image.draw(screen)


# function to present the end result of the game.
def print_end_result():
	# variable for text left alignment
	left = 580
	# variable for modifying y
	y_mod = 40

	#defining font for diplaying the player scores.
	displayfont = pygame.font.Font("/Library/Fonts/Trebuchet MS Bold.ttf", 32)

	#create the background for end result - box, and it's border.
	end_box = pygame.Rect(0, 0, 700, 400)
	end_box.center = (900, 620)
	end_box_edge = pygame.Rect(0, 0, 750, 450)
	end_box_edge.center = end_box.center

	#creating player one's end result text.
	end1 = ('Player 1 (\"{1}") score: \"{0}\"'.format(end_one, arr1[p1])) # creating the string
	end1_post = end1.replace('"', '') # removing the double quotes.
	end1_text = displayfont.render(end1_post, True, ORANGE) #create text object
	end1_rect = end1_text.get_rect() # create text rectangle
	end1_rect.left = (left) # distance from left edge
	end1_rect.top = (420 + y_mod) # distance from top edge

	#creating player two's end result text.
	end2 = ('Player 2 (\"{1}") score: \"{0}\"'.format(end_two, arr1[p2])) # creating the string
	end2_post = end2.replace('"', '') # removing the double quotes.
	end2_text = displayfont.render(end2_post, True, GREEN) #create text object
	end2_rect = end2_text.get_rect() # create text rectangle
	end2_rect.left = (left) # distance from left edge
	end2_rect.top = (520 + y_mod) # distance from top edge

	# creating winner text.
	if (end_one > end_two):
		win = ('Player 1 (\"{0}") wins!'.format(arr1[p1]))
	else:
		win = ('Player 2 (\"{0}") wins!'.format(arr1[p2]))
	win_post = win.replace('"', '') # removing the double quotes.
	win_text = displayfont.render(win_post, True, RED) #create text object
	win_rect = win_text.get_rect() # create text rectangle
	win_rect.left = (left) # distance from left edge
	win_rect.top = (620 + y_mod) # distance from top edge

	# creating "press any key to quit" text.
	end = ("Press 'return' to quit, or 'r' to replay.") # creating the string
	end_text = displayfont.render(end, True, WHITE) #create text object
	end_rect = end_text.get_rect() # create text rectangle
	end_rect.left = (left + 50) # distance from left edge
	end_rect.top = (700 + y_mod) # distance from top edge

	# drawing the box on screen
	pygame.draw.rect(screen, RED, end_box_edge)
	pygame.draw.rect(screen, BLACK, end_box)

	# drawing the text on screen
	screen.blit(end1_text, end1_rect)
	screen.blit(end2_text, end2_rect)
	screen.blit(end_text, end_rect)
	screen.blit(win_text, win_rect)

# function to detect the match has ended.
def check_for_end(line):
	global file1
	global end_one
	global end_two
	if line.find("fin") != -1:
		for z in line.split():
			if z.isdigit():
				end_one = (int(z))
		line = file1.readline().rstrip(':\n')
		for z in line.split():
			if z.isdigit():
				end_two = (int(z))
		return 1
	return 0

# function to iterate through map rows and print squares accordingly.
def parse_and_draw_map():
	# creating the correct size squares.
	square_h = bg_h / map_size[0] # we divide the map(background) area with the number of squares each way
	square_w = bg_w / map_size[1]
	square = pygame.Rect(0, 0, square_w, square_h, border_radius=0)
	# creating the smaller squares inside the "virtual" squares to prevent squares "fuzing" on screen.
	s2_h = square_h - square_h / 10
	s2_w = square_w - square_w / 10
	s2 = pygame.Rect(0, 0, s2_w, s2_h, border_radius=s2_w * 2)
	global file1
	line = file1.readline().rstrip(':\n')
	while (line.find("0123") == -1): # read lines of file until we reach the map actual
		if check_for_end(line) == 1:
			print_end_result()
			return(2)
		line = file1.readline().rstrip(':\n')
	x = 0
	while x < map_size[0]: # while we are within the height (row count) or the map.
		line = file1.readline().rstrip(':\n')
		sans_digits = ''.join([i for i in line if not i.isdigit() or not ' ']) #iterate through the string removing numbers.
		y = 0
		while y < map_size[1]: # while we are within the width (column count) of the map
			if sans_digits[1:].find('X', y, y + 1) != -1: # search starting from index 1
				square.left = (900 - bg_w / 2) + (y * square_w)
				#print(y, y * square_w)
				square.top = (620 - bg_h / 2) + (x * square_h)
				#print(x * square_h)
				s2.center = square.center
				pygame.draw.rect(screen, BLUE, square) # printing the "virtual" square.
				pygame.draw.rect(screen, GREEN, s2) # printing the actual square.
			if sans_digits[1:].find('x', y, y + 1) != -1: # search starting from index 1
				square.left = (900 - bg_w / 2) + (y  * square_w)
				#print(y, y * square_w)
				square.top = (620 - bg_h / 2) + (x * square_h)
				#print(x * square_h)
				s2.center = square.center
				pygame.draw.rect(screen, BLUE, square) # printing the "virtual" square.
				pygame.draw.rect(screen, LGREEN, s2) # printing the actual square.
			if sans_digits[1:].find('O', y, y + 1) != -1:  # search starting from index 1
				square.left = (900 - bg_w / 2) + (y * square_w)
				#print(y, y * square_w)
				square.top = (620 - bg_h / 2) + (x  * square_h)
				#print(x * square_h)
				s2.center = square.center
				pygame.draw.rect(screen, BLUE, square) # printing the "virtual" square.
				pygame.draw.rect(screen, ORANGE, s2) # printing the actual square.
			if sans_digits[1:].find('o', y, y + 1) != -1:  # search starting from index 1
				square.left = (900 - bg_w / 2) + (y * square_w)
				#print(y, y * square_w)
				square.top = (620 - bg_h / 2) + (x * square_h)
				#print(x * square_h)
				s2.center = square.center
				pygame.draw.rect(screen, BLUE, square) # printing the "virtual" square.
				pygame.draw.rect(screen, ORANKI, s2) # printing the actual square.
			y += 1
		#the_map = arr.array('b', [])
		#the_map[x] = sans_digits
		x += 1
		# check if the game has ended
	line = file1.readline().rstrip(':\n')
	if check_for_end(line) == 1:
		print_end_result()
		return(2)
	return (1)


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

def run():
	start_visual(0)

def start_visual(re):
	# Loop until window closed.
	carryOn = True

	clock = pygame.time.Clock()

	# loading music.
	mixer.music.load("meadow_fog.mp3")
	# setting initial music volume.
	mixer.music.set_volume(0.2)

	# create the command
	command = "../resources/filler_vm -p1 ../resources/players/\"{0}\".filler -p2 ../resources/players/\"{1}\".filler -v -f ../resources/maps/\"{2}\" > temp_text".format(arr1[p1], arr1[p2], arr2[map_nro])

	# run the filler_vm if not a re-run if not re-run.
	if re != 1:
		os.system(command)

	time.sleep(0.1)
	# getting the correct map size from the initial output
	get_map_size()

	# play music
	blast = True
	while blast == True:
		mixer.music.play(-1)
		break

	# Setting up variable speed, default setting : 10
	speed = 20

	#pygame -loop
	while carryOn:
		global bg_h
		global bg_w
		#draw graphics starts here.
		screen.fill(WHITE)
		pygame.draw.rect(screen, BLACK, [50, 40, 1700, 1100], 0, border_radius=20)

		# defining font for diplaying the players and map.
		displayfont = pygame.font.Font("/Library/Fonts/Trebuchet MS Bold.ttf", 32)

		# defining font for diplaying the info.
		infofont = pygame.font.Font("/Library/Fonts/Trebuchet MS Bold.ttf", 20)

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
		p2_text = displayfont.render(p2_post, True, GREEN) #create text object
		p2_rect = p2_text.get_rect() # create text rectangle
		p2_rect.right = (1700) # distance from right edge
		p2_rect.top = (80) # distance from top edge

		# creating map info on screen.
		map_pre = ('\"{0}\"'.format(arr2[map_nro])) # creating the string
		map_post = map_pre.replace('"', '') # removing the double quotes.
		map_text = displayfont.render(map_post, True, RED) #create text object
		map_rect = map_text.get_rect() # create text rectangle
		map_rect.center = (900, 80) # position of center of object

		# creating the info1 text to print on screen
		info_pre = ("1 to 9 to control speed.") # creating the string
		info_text = infofont.render(info_pre, True, WHITE) #create text object
		info_rect = info_text.get_rect() # create text rectangle
		info_rect.left = (100) # distance from left edge
		info_rect.top = (300) # distance from top edge

		# creating the info2 text to print on screen
		info2_pre = ("press 'M' to mute.") # creating the string
		info2_text = infofont.render(info2_pre, True, WHITE) #create text object
		info2_rect = info2_text.get_rect() # create text rectangle
		info2_rect.left = (100) # distance from left edge
		info2_rect.top = (360) # distance from top edge

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

		# for loop checking for keystrokes
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				command = "rm temp_text" # set command to remove the temporary text file (temp_text)
				os.system(command) # run command to remove the temporary text file (temp_text)
				carryOn = False
			# keystrokes to control the speed. 1 = slowest, 9 = full speed.
			if event.type == pygame.KEYDOWN:
				if event.key == pygame.K_1:
					speed = 2
				if event.key == pygame.K_2:
					speed = 4
				if event.key == pygame.K_3:
					speed = 6
				if event.key == pygame.K_4:
					speed = 8
				if event.key == pygame.K_5:
					speed = 15
				if event.key == pygame.K_6:
					speed = 20
				if event.key == pygame.K_7:
					speed = 50
				if event.key == pygame.K_8:
					speed == 100
				if event.key == pygame.K_9:
					speed = 1000
				if event.key == pygame.K_m:
					mixer.music.set_volume(1)
				if event.key == pygame.K_n:
					mixer.music.set_volume(0)

		# placing the texts on screen.
		screen.blit(p1_text, p1_rect)
		screen.blit(p2_text, p2_rect)
		screen.blit(map_text, map_rect)
		screen.blit(info_text, info_rect)
		screen.blit(info2_text, info2_rect)

		# drawing the map background on screen, border first.
		pygame.draw.rect(screen, RED, map_bg_bord)
		pygame.draw.rect(screen, BLUE, map_bg)

		# parsing and drawing the map.
		if parse_and_draw_map() == 2:
			pygame.display.flip()
			pause = True
			while pause:
				for event in pygame.event.get():
					if event.type == pygame.KEYDOWN:
						if event.key == pygame.K_RETURN or event.key == pygame.K_ESCAPE:
							command = "rm temp_text" # set command to remove the temporary text file (temp_text)
							os.system(command) # run command to remove the temporary text file (temp_text)
							pause = False
							carryOn = False
						if event.key == pygame.K_r:
							pause = False
							start_visual(1)
						if event.key == pygame.K_m:
							mixer.music.set_volume(1)
						if event.key == pygame.K_n:
							mixer.music.set_volume(0)
				#command = "rm temp_text" # set command to remove the temporary text file (temp_text)
				#os.system(command) # run command to remove the temporary text file (temp_text)
			#while 1:
				#if event.type == pygame.KEYDOWN:
					#command = "rm temp_text" # set command to remove the temporary text file (temp_text)
					#os.system(command) # run command to remove the temporary text file (temp_text)
					#carryOn = False
					#break

		# sleep to slow down
		time.sleep(1 / speed)

		#updating screen
		pygame.display.flip()

		#framerate
		clock.tick(60)

	#exit pygame
	pygame.quit()


menu.add.selector('Player 1 :', [('tburakow', 0), ('carli', 1), ('abanlin', 2), ('champely', 3), ('grati', 4), ('hcao', 5), ('superjeannot', 6)], onchange=set_player_one)
menu.add.selector('Player 2 :', [('tburakow', 0), ('carli', 1), ('abanlin', 2), ('champely', 3), ('grati', 4), ('hcao', 5), ('superjeannot', 6)], onchange=set_player_two)
menu.add.selector('Map :', [('small(00)', 0), ('medium(01)', 1), ('large(02)', 2)], onchange=set_map)
menu.add.button('Play', run)
menu.add.button('Quit', pgm.events.EXIT)

menu.mainloop(screen)




        