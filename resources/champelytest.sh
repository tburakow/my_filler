#!bin/sh
printf "Running champely small map. I am 'O'\n" >> champelytest
./filler_vm -p1 ../tburakow.filler -p2 players/champely.filler -v -f maps/map00 | grep '==' >> champelytest
printf "Test 2\n" >> champelytest
./filler_vm -p1 ../tburakow.filler -p2 players/champely.filler -v -f maps/map00 | grep '==' >> champelytest
printf "Test 3\n" >> champelytest
./filler_vm -p1 ../tburakow.filler -p2 players/champely.filler -v -f maps/map00 | grep '==' >> champelytest
printf "Test 4\n" >> champelytest
./filler_vm -p1 ../tburakow.filler -p2 players/champely.filler -v -f maps/map00 | grep '==' >> champelytest
printf "Test 5\n" >> champelytest
./filler_vm -p1 ../tburakow.filler -p2 players/champely.filler -v -f maps/map00 | grep '==' >> champelytest
printf "Running champely small map. I am 'X'\n" >> champelytest
./filler_vm -p2 ../tburakow.filler -p1 players/champely.filler -v -f maps/map00 | grep '==' >> champelytest
printf "Test 2\n" >> champelytest
./filler_vm -p2 ../tburakow.filler -p1 players/champely.filler -v -f maps/map00 | grep '==' >> champelytest
printf "Test 3\n" >> champelytest
./filler_vm -p2 ../tburakow.filler -p1 players/champely.filler -v -f maps/map00 | grep '==' >> champelytest
printf "Test 4\n" >> champelytest
./filler_vm -p2 ../tburakow.filler -p1 players/champely.filler -v -f maps/map00 | grep '==' >> champelytest
printf "Test 5\n" >> champelytest
./filler_vm -p2 ../tburakow.filler -p1 players/champely.filler -v -f maps/map00 | grep '==' >> champelytest

#champely medium map.

printf "\n\n" >> champelytest
printf "Running champely medium map. I am 'O'\n" >> champelytest
./filler_vm -p1 ../tburakow.filler -p2 players/champely.filler -v -f maps/map01 | grep '==' >> champelytest
printf "Test 2\n" >> champelytest
./filler_vm -p1 ../tburakow.filler -p2 players/champely.filler -v -f maps/map01 | grep '==' >> champelytest
printf "Test 3\n" >> champelytest
./filler_vm -p1 ../tburakow.filler -p2 players/champely.filler -v -f maps/map01 | grep '==' >> champelytest
printf "Test 4\n" >> champelytest
./filler_vm -p1 ../tburakow.filler -p2 players/champely.filler -v -f maps/map01 | grep '==' >> champelytest
printf "Test 5\n" >> champelytest
./filler_vm -p1 ../tburakow.filler -p2 players/champely.filler -v -f maps/map01 | grep '==' >> champelytest
printf "Running champely medium map. I am 'X'\n" >> champelytest
./filler_vm -p2 ../tburakow.filler -p1 players/champely.filler -v -f maps/map01 | grep '==' >> champelytest
printf "Test 2\n" >> champelytest
./filler_vm -p2 ../tburakow.filler -p1 players/champely.filler -v -f maps/map01 | grep '==' >> champelytest
printf "Test 3\n" >> champelytest
./filler_vm -p2 ../tburakow.filler -p1 players/champely.filler -v -f maps/map01 | grep '==' >> champelytest
printf "Test 4\n" >> champelytest
./filler_vm -p2 ../tburakow.filler -p1 players/champely.filler -v -f maps/map01 | grep '==' >> champelytest
printf "Test 5\n" >> champelytest
./filler_vm -p2 ../tburakow.filler -p1 players/champely.filler -v -f maps/map01 | grep '==' >> champelytest

#champely - Large map.

printf "\n\n" >> champelytest
printf "Running champely large map. I am 'O'\n" >> champelytest
./filler_vm -p1 ../tburakow.filler -p2 players/champely.filler -v -f maps/map02 | grep '==' >> champelytest
printf "Test 2\n" >> champelytest
./filler_vm -p1 ../tburakow.filler -p2 players/champely.filler -v -f maps/map02 | grep '==' >> champelytest
printf "Test 3\n" >> champelytest
./filler_vm -p1 ../tburakow.filler -p2 players/champely.filler -v -f maps/map02 | grep '==' >> champelytest
printf "Test 4\n" >> champelytest
./filler_vm -p1 ../tburakow.filler -p2 players/champely.filler -v -f maps/map02 | grep '==' >> champelytest
printf "Test 5\n" >> champelytest
./filler_vm -p1 ../tburakow.filler -p2 players/champely.filler -v -f maps/map02 | grep '==' >> champelytest
printf "Running champely large map. I am 'X'\n" >> champelytest
./filler_vm -p2 ../tburakow.filler -p1 players/champely.filler -v -f maps/map02 | grep '==' >> champelytest
printf "Test 2\n" >> champelytest
./filler_vm -p2 ../tburakow.filler -p1 players/champely.filler -v -f maps/map02 | grep '==' >> champelytest
printf "Test 3\n" >> champelytest
./filler_vm -p2 ../tburakow.filler -p1 players/champely.filler -v -f maps/map02 | grep '==' >> champelytest
printf "Test 4\n" >> champelytest
./filler_vm -p2 ../tburakow.filler -p1 players/champely.filler -v -f maps/map02 | grep '==' >> champelytest
printf "Test 5\n" >> champelytest
./filler_vm -p2 ../tburakow.filler -p1 players/champely.filler -v -f maps/map02 | grep '==' >> champelytest

