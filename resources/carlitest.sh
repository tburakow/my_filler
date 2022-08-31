#!bin/sh
printf "Running carli small map. I am 'O'\n" >> carlitest
./filler_vm -p1 ../tburakow.filler -p2 players/carli.filler -v -f maps/map00 | grep '==' >> carlitest
printf "Test 2\n" >> carlitest
./filler_vm -p1 ../tburakow.filler -p2 players/carli.filler -v -f maps/map00 | grep '==' >> carlitest
printf "Test 3\n" >> carlitest
./filler_vm -p1 ../tburakow.filler -p2 players/carli.filler -v -f maps/map00 | grep '==' >> carlitest
printf "Test 4\n" >> carlitest
./filler_vm -p1 ../tburakow.filler -p2 players/carli.filler -v -f maps/map00 | grep '==' >> carlitest
printf "Test 5\n" >> carlitest
./filler_vm -p1 ../tburakow.filler -p2 players/carli.filler -v -f maps/map00 | grep '==' >> carlitest
printf "Running carli small map. I am 'X'\n" >> carlitest
./filler_vm -p2 ../tburakow.filler -p1 players/carli.filler -v -f maps/map00 | grep '==' >> carlitest
printf "Test 2\n" >> carlitest
./filler_vm -p2 ../tburakow.filler -p1 players/carli.filler -v -f maps/map00 | grep '==' >> carlitest
printf "Test 3\n" >> carlitest
./filler_vm -p2 ../tburakow.filler -p1 players/carli.filler -v -f maps/map00 | grep '==' >> carlitest
printf "Test 4\n" >> carlitest
./filler_vm -p2 ../tburakow.filler -p1 players/carli.filler -v -f maps/map00 | grep '==' >> carlitest
printf "Test 5\n" >> carlitest
./filler_vm -p2 ../tburakow.filler -p1 players/carli.filler -v -f maps/map00 | grep '==' >> carlitest

#Carli medium map.

printf "\n\n" >> carlitest
printf "Running carli medium map. I am 'O'\n" >> carlitest
./filler_vm -p1 ../tburakow.filler -p2 players/carli.filler -v -f maps/map01 | grep '==' >> carlitest
printf "Test 2\n" >> carlitest
./filler_vm -p1 ../tburakow.filler -p2 players/carli.filler -v -f maps/map01 | grep '==' >> carlitest
printf "Test 3\n" >> carlitest
./filler_vm -p1 ../tburakow.filler -p2 players/carli.filler -v -f maps/map01 | grep '==' >> carlitest
printf "Test 4\n" >> carlitest
./filler_vm -p1 ../tburakow.filler -p2 players/carli.filler -v -f maps/map01 | grep '==' >> carlitest
printf "Test 5\n" >> carlitest
./filler_vm -p1 ../tburakow.filler -p2 players/carli.filler -v -f maps/map01 | grep '==' >> carlitest
printf "Running carli medium map. I am 'X'\n" >> carlitest
./filler_vm -p2 ../tburakow.filler -p1 players/carli.filler -v -f maps/map01 | grep '==' >> carlitest
printf "Test 2\n" >> carlitest
./filler_vm -p2 ../tburakow.filler -p1 players/carli.filler -v -f maps/map01 | grep '==' >> carlitest
printf "Test 3\n" >> carlitest
./filler_vm -p2 ../tburakow.filler -p1 players/carli.filler -v -f maps/map01 | grep '==' >> carlitest
printf "Test 4\n" >> carlitest
./filler_vm -p2 ../tburakow.filler -p1 players/carli.filler -v -f maps/map01 | grep '==' >> carlitest
printf "Test 5\n" >> carlitest
./filler_vm -p2 ../tburakow.filler -p1 players/carli.filler -v -f maps/map01 | grep '==' >> carlitest

#Carli - Large map.

printf "\n\n" >> carlitest
printf "Running carli large map. I am 'O'\n" >> carlitest
./filler_vm -p1 ../tburakow.filler -p2 players/carli.filler -v -f maps/map02 | grep '==' >> carlitest
printf "Test 2\n" >> carlitest
./filler_vm -p1 ../tburakow.filler -p2 players/carli.filler -v -f maps/map02 | grep '==' >> carlitest
printf "Test 3\n" >> carlitest
./filler_vm -p1 ../tburakow.filler -p2 players/carli.filler -v -f maps/map02 | grep '==' >> carlitest
printf "Test 4\n" >> carlitest
./filler_vm -p1 ../tburakow.filler -p2 players/carli.filler -v -f maps/map02 | grep '==' >> carlitest
printf "Test 5\n" >> carlitest
./filler_vm -p1 ../tburakow.filler -p2 players/carli.filler -v -f maps/map02 | grep '==' >> carlitest
printf "Running carli large map. I am 'X'\n" >> carlitest
./filler_vm -p2 ../tburakow.filler -p1 players/carli.filler -v -f maps/map02 | grep '==' >> carlitest
printf "Test 2\n" >> carlitest
./filler_vm -p2 ../tburakow.filler -p1 players/carli.filler -v -f maps/map02 | grep '==' >> carlitest
printf "Test 3\n" >> carlitest
./filler_vm -p2 ../tburakow.filler -p1 players/carli.filler -v -f maps/map02 | grep '==' >> carlitest
printf "Test 4\n" >> carlitest
./filler_vm -p2 ../tburakow.filler -p1 players/carli.filler -v -f maps/map02 | grep '==' >> carlitest
printf "Test 5\n" >> carlitest
./filler_vm -p2 ../tburakow.filler -p1 players/carli.filler -v -f maps/map02 | grep '==' >> carlitest

