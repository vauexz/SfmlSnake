main: main.o fruit.o snake.o game.o scoreboard.o gameboard.o leaderboard.o
	g++ main.o fruit.o snake.o game.o scoreboard.o gameboard.o leaderboard.o\
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

gameboard.o:
	g++ -c gameboard.cpp

leaderboard.o:
	g++ -c leaderboard.cpp

clean:
	rm *.o
