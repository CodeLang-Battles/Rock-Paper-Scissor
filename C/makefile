all: Rock-Paper-Scissor

Rock-Paper-Scissor: Rock-Paper-Scissor.o player.o
	gcc -Wall -g -o Rock-Paper-Scissor Rock-Paper-Scissor.o player.o

Rock-Paper-Scissor.o: Rock-Paper-Scissor.c player.h
	gcc -Wall -g -c Rock-Paper-Scissor.c -o Rock-Paper-Scissor.o

player.o: player.c player.h
	gcc -Wall -g -c player.c -o player.o

clean:
	rm -f *.o ./Rock-Paper-Scissor
