#!bin/sh
printf "Running abanlin small map. I am 'O'\n" >> abanlintest
./filler_vm -p1 ../tburakow.filler -p2 players/abanlin.filler -v -f maps/map00 | grep '==' >> abanlintest
printf "Test 2\n" >> abanlintest
./filler_vm -p1 ../tburakow.filler -p2 players/abanlin.filler -v -f maps/map00 | grep '==' >> abanlintest
printf "Test 3\n" >> abanlintest
./filler_vm -p1 ../tburakow.filler -p2 players/abanlin.filler -v -f maps/map00 | grep '==' >> abanlintest
printf "Test 4\n" >> abanlintest
./filler_vm -p1 ../tburakow.filler -p2 players/abanlin.filler -v -f maps/map00 | grep '==' >> abanlintest
printf "Test 5\n" >> abanlintest
./filler_vm -p1 ../tburakow.filler -p2 players/abanlin.filler -v -f maps/map00 | grep '==' >> abanlintest
printf "Running abanlin small map. I am 'X'\n" >> abanlintest
./filler_vm -p2 ../tburakow.filler -p1 players/abanlin.filler -v -f maps/map00 | grep '==' >> abanlintest
printf "Test 2\n" >> abanlintest
./filler_vm -p2 ../tburakow.filler -p1 players/abanlin.filler -v -f maps/map00 | grep '==' >> abanlintest
printf "Test 3\n" >> abanlintest
./filler_vm -p2 ../tburakow.filler -p1 players/abanlin.filler -v -f maps/map00 | grep '==' >> abanlintest
printf "Test 4\n" >> abanlintest
./filler_vm -p2 ../tburakow.filler -p1 players/abanlin.filler -v -f maps/map00 | grep '==' >> abanlintest
printf "Test 5\n" >> abanlintest
./filler_vm -p2 ../tburakow.filler -p1 players/abanlin.filler -v -f maps/map00 | grep '==' >> abanlintest

#abanlin medium map.

printf "\n\n" >> abanlintest
printf "Running abanlin medium map. I am 'O'\n" >> abanlintest
./filler_vm -p1 ../tburakow.filler -p2 players/abanlin.filler -v -f maps/map01 | grep '==' >> abanlintest
printf "Test 2\n" >> abanlintest
./filler_vm -p1 ../tburakow.filler -p2 players/abanlin.filler -v -f maps/map01 | grep '==' >> abanlintest
printf "Test 3\n" >> abanlintest
./filler_vm -p1 ../tburakow.filler -p2 players/abanlin.filler -v -f maps/map01 | grep '==' >> abanlintest
printf "Test 4\n" >> abanlintest
./filler_vm -p1 ../tburakow.filler -p2 players/abanlin.filler -v -f maps/map01 | grep '==' >> abanlintest
printf "Test 5\n" >> abanlintest
./filler_vm -p1 ../tburakow.filler -p2 players/abanlin.filler -v -f maps/map01 | grep '==' >> abanlintest
printf "Running abanlin medium map. I am 'X'\n" >> abanlintest
./filler_vm -p2 ../tburakow.filler -p1 players/abanlin.filler -v -f maps/map01 | grep '==' >> abanlintest
printf "Test 2\n" >> abanlintest
./filler_vm -p2 ../tburakow.filler -p1 players/abanlin.filler -v -f maps/map01 | grep '==' >> abanlintest
printf "Test 3\n" >> abanlintest
./filler_vm -p2 ../tburakow.filler -p1 players/abanlin.filler -v -f maps/map01 | grep '==' >> abanlintest
printf "Test 4\n" >> abanlintest
./filler_vm -p2 ../tburakow.filler -p1 players/abanlin.filler -v -f maps/map01 | grep '==' >> abanlintest
printf "Test 5\n" >> abanlintest
./filler_vm -p2 ../tburakow.filler -p1 players/abanlin.filler -v -f maps/map01 | grep '==' >> abanlintest

#abanlin - Large map.

printf "\n\n" >> abanlintest
printf "Running abanlin large map. I am 'O'\n" >> abanlintest
./filler_vm -p1 ../tburakow.filler -p2 players/abanlin.filler -v -f maps/map02 | grep '==' >> abanlintest
printf "Test 2\n" >> abanlintest
./filler_vm -p1 ../tburakow.filler -p2 players/abanlin.filler -v -f maps/map02 | grep '==' >> abanlintest
printf "Test 3\n" >> abanlintest
./filler_vm -p1 ../tburakow.filler -p2 players/abanlin.filler -v -f maps/map02 | grep '==' >> abanlintest
printf "Test 4\n" >> abanlintest
./filler_vm -p1 ../tburakow.filler -p2 players/abanlin.filler -v -f maps/map02 | grep '==' >> abanlintest
printf "Test 5\n" >> abanlintest
./filler_vm -p1 ../tburakow.filler -p2 players/abanlin.filler -v -f maps/map02 | grep '==' >> abanlintest
printf "Running abanlin large map. I am 'X'\n" >> abanlintest
./filler_vm -p2 ../tburakow.filler -p1 players/abanlin.filler -v -f maps/map02 | grep '==' >> abanlintest
printf "Test 2\n" >> abanlintest
./filler_vm -p2 ../tburakow.filler -p1 players/abanlin.filler -v -f maps/map02 | grep '==' >> abanlintest
printf "Test 3\n" >> abanlintest
./filler_vm -p2 ../tburakow.filler -p1 players/abanlin.filler -v -f maps/map02 | grep '==' >> abanlintest
printf "Test 4\n" >> abanlintest
./filler_vm -p2 ../tburakow.filler -p1 players/abanlin.filler -v -f maps/map02 | grep '==' >> abanlintest
printf "Test 5\n" >> abanlintest
./filler_vm -p2 ../tburakow.filler -p1 players/abanlin.filler -v -f maps/map02 | grep '==' >> abanlintest

