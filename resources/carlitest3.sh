#!bin/sh
# Script for 5 gamesplayer
# Enter player name and game size (0, 1 or 2)

ME="tburakow"
TRACE=../resources/filler.trace
MYWIN=0
ENEMYWIN=0
GAMES=1

echo Write player name:
read pname

echo Write map size - 0, 1 or 2:
read size

if ((size < 0 || size > 2)); then
    echo "Wrong size"
    exit 1
fi

cd resources
while [ $GAMES -le 25 ]
do
    if [ $(expr $GAMES % 2) == "0" ]
    then
        ./filler_vm -f ./maps/map0$size -p1 players/$pname.filler -p2 ../tburakow.filler -q
    else
        ./filler_vm -f ./maps/map0$size -p1 players/$pname.filler -p2 ../tburakow.filler -q
    fi
    if (cat $TRACE | grep $ME)
    then
        let MYWIN+=1
    else
        let ENEMYWIN+=1
    fi
    GAMES=$(( $GAMES + 1 ))
done
echo $ME: $MYWIN
echo $pname: $ENEMYWIN