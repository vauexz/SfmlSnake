main: main.o player.o animation.o
	g++ main.o player.o animation.o -o main -lsfml-graphics -lsfml-window -lsfml-system
	make clean

main.o:
	g++ -c main.cpp

player.o:
	g++ -c player.cpp

animation.o:
	g++ -c animation.cpp

clean:
	rm *.o
