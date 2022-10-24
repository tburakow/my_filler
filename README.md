Filler is a project in which we were asked to create a player to battle other players for control of the board.
the game is played by placing the pieces supplied by the VM onto the board at the optimal location.
Following rules apply:
- The pieces supplied by the VM are of random size.
- The pieces have both empty and used squares.
- When placing the pieces, the players must place them in such a way that there is only a single overlap with
the player's own squares and no overlap with the enemy's.
- When neither player can place their supplied piece on the board, the game ends.
- The player with the most squares occupied wins.

The VM requires that the player supplies the coordinates of the upper-left corner of the piece, regardless of
these coordinates possibly being outside of the board. This is because only the used squares need to be inside the board.

The final iteration of my solution (player) creates a "heat map" which shows the proximity of each square to the closest
opponent-occupied square, and places the pieces accordingly. The way the heat map is generated also prevents the player
from placing pieces on parts of the map that the player has already isolated, as these are unaccessible to the opponent,
and can thus be left to be filled later.

I also created some adjustment functions of dubious benefits to combat a certain enemy (Carli). Empirical evidence suggests
a 5 - 10% increase in victories against Carli using these adjustments, so they stayed.

I've also created a visualizer for the game using python, but it's optimized to our school computers (Retina 5K, 27-inch, 2019).
With some tinkering it can be made to work on other setups as well.

What I learned wokring on this project:

- Multiple different approaches to calculating distances/proximity.
- To make/use more general purpose functions more often. This became apparent with the multiple solutions/iterations that
were needed to complete this project to my satisfaction.
- Some very basic Python.

How to use:

First we need to make the executable:
make

Then to run the VM:
./resources/filler_VM -p1 tburakow.filler -p2 ./resources/players/carli.filler -f /resources/maps/map01

This runs the VM with my player as player one (O) and my arch-enemy Carli as player two (X) the -f -flag designates that we are
using a file for the map, which we supply from the /maps -folder. map01 is the middle one of the three maps supplied.

to run the visualizer, navigate to /python_visual and run the visual.py file. The visualizer requires both pygame, and pygame_menu -libraries.
The visualizer launches a menu where you can choose both players and the map. When you choose "play", the game commences.
