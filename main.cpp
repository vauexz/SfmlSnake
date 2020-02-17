#include "variables.h"
#include "fruit.h"
#include "snake.h"
#include <cstdlib>
#include <ctime>
/*
    
    g++ -c main.cpp && g++ main.o -o main -lsfml-graphics -lsfml-window -lsfml-system && ./main
*/


int main() {
    srand(time(NULL));

    sf::Texture apl;
    apl.loadFromFile("img/fruit.png");
    Fruit apple(&apl, sf::Vector2u(3,3), sf::Vector2f(50,50), {12,12}, {0,0});
    Snake snake(sf::Vector2u(6,6), sf::Vector2f(50,50), sf::Vector2f(0,0));
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Snake Game");
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            apple.respawn();
        }

        float deltaTime = clock.restart().asSeconds();
        snake.move(deltaTime);
        window.clear(sf::Color::Black);
        apple.draw(window);
        snake.draw(window);
        window.display();

    }
    
    return 0;
}