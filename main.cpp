#include "variables.h"

/*
    
    g++ -c main.cpp && g++ main.o -o main -lsfml-graphics -lsfml-window -lsfml-system && ./main
*/


int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Snake Game");

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.display();

    }
    
    return 0;
}