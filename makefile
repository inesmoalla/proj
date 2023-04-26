prog: game.o main.o
	gcc game.o main.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf 
main.o:main.c
	gcc -c main.c -g
fonction.o:game.c
	gcc -c game.c -g
