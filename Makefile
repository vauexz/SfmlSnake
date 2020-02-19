main: main.o fruit.o snake.o game.o scoreboard.o
	g++ main.o fruit.o snake.o game.o scoreboard.o\
		-o main \
		-lsfml-graphics -lsfml-window -lsfml-system
		make clean

main.o:
	g++ -c main.cpp

fruit.o:
	g++ -c fruit.cpp

snake.o:
	g++ -c snake.cpp

game.o:
	g++ -c game.cpp

scoreboard.o:
	g++ -c scoreboard.cpp

clean:
	rm *.o
