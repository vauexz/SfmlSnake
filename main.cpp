#include "variables.h"
#include <cstdlib>
#include <ctime>
#include "game.h"
/*
    
    g++ -c main.cpp && g++ main.o -o main -lsfml-graphics -lsfml-window -lsfml-system && ./main
*/

/*
to fix
    snake chnage move direction
    pause game


*/
int main() {
    srand(time(NULL));

    sf::Texture apl;
    apl.loadFromFile("img/fruit.png");
    Game game(&apl, sf::Vector2u(3,3), sf::Vector2u(30,30), {20,20}, {0,0}, 1.0/7.0);
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Snake Game");
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                window.close();
        }


        float deltaTime = clock.restart().asSeconds();
        game.tick(deltaTime);
        window.clear(sf::Color::Black);
        game.draw(window);
        window.display();

    }
    
    return 0;
}