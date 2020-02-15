#include "variables.h"
#include "fruit.h"
#include <cstdlib>
#include <ctime>
/*
    
    g++ -c main.cpp && g++ main.o -o main -lsfml-graphics -lsfml-window -lsfml-system && ./main
*/


int main() {
    srand(time(NULL));

    sf::Texture apl;
    apl.loadFromFile("img/fruit.png");
    Fruit apple(&apl, sf::Vector2u(3,3), sf::Vector2f(50,50), {12,12});
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Snake Game");
    apple.setPosition(sf::Vector2f(300,300));
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            apple.respawn();
        }

        window.clear(sf::Color::Black);
        window.draw(apple.getFruit());
        window.display();

    }
    
    return 0;
}