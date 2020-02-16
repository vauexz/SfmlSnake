main: main.o fruit.o
	g++ main.o fruit.o \
		-o main \
		-lsfml-graphics -lsfml-window -lsfml-system
	make clean

main.o:
	g++ -c main.cpp

fruit.o:
	g++ -c fruit.cpp

clean:
	rm *.o
