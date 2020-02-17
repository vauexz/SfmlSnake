main: main.o fruit.o snake.o
	g++ main.o fruit.o snake.o\
		-o main \
		-lsfml-graphics -lsfml-window -lsfml-system
	make clean

main.o:
	g++ -c main.cpp

fruit.o:
	g++ -c fruit.cpp

snake.o:
	g++ -c snake.cpp

clean:
	rm *.o
