import pygame
import pygame_menu as pgm
import os

pygame.init() # initialize pygame

# define logo
logo = pygame.image.load("./title.png")
# draw logo
pygame.display.set_icon(logo)

p1 = 0
p2 = 0
map_nro = 0

# defining the player and map lists.
arr1 = ["tburakow", "carli", "abanlin", "champely", "grati", "hcao", "superjeannot"]
arr2 = ["map00", "map01", "map02"]

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

# define menu window size
size = (1000, 800)
screen = pygame.display.set_mode(size)

# loading menu background image
background_image = pgm.BaseImage(
    image_path=("title.png")
)
pygame.display.set_caption("The great visualizer -- by tburakow")

# setting the font and menu theme.
myfont = pgm.font.FONT_8BIT
titlefont = pgm.font.FONT_COMIC_NEUE
tumetheme = pgm.Theme(background_color=(255, 255, 0, 0),
					title_background_color=(0, 0, 0, 0),
					title_font_shadow=True,
					widget_padding=25,
					title_font=titlefont,
					widget_font=myfont,
					widget_font_color=ORANGE
					)
tumetheme.background_color = background_image
pgm.locals.POSITION_SOUTH

#setting the menu size
menu = pgm.Menu(
    height=800,
    theme=tumetheme,
    title='SETUP',
    width=1000
)

# the run function. This launches the actual visualizer.
def run():
	command = "../resources/filler_vm -p1 ../resources/players/\"{0}\".filler -p2 ../resources/players/\"{1}\".filler -v -f ../resources/maps/\"{2}\" | python3 visual2.py".format(arr1[p1], arr1[p2], arr2[map_nro])
	os.system(command)
	pygame.quit()

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

# defining menu background
def main_background():
	background_image.draw(screen)

menu.add.selector('Player 1 :', [('tburakow', 0), ('carli', 1), ('abanlin', 2), ('champely', 3), ('grati', 4), ('hcao', 5), ('superjeannot', 6)], onchange=set_player_one)
menu.add.selector('Player 2 :', [('tburakow', 0), ('carli', 1), ('abanlin', 2), ('champely', 3), ('grati', 4), ('hcao', 5), ('superjeannot', 6)], onchange=set_player_two)
menu.add.selector('Map :', [('small(00)', 0), ('medium(01)', 1), ('large(02)', 2)], onchange=set_map)
menu.add.button('Play', run)
menu.add.button('Quit', pgm.events.EXIT)

menu.mainloop(screen)
