main: main.o fruit.o snake.o game.o
	g++ main.o fruit.o snake.o game.o \
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

clean:
	rm *.o
