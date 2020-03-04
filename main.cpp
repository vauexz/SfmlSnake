#include "variables.h"
#include <cstdlib>
#include <ctime>
#include "game.h"
#include "scoreboard.h"
#include "gameboard.h"
int main() {
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Snake Game");

    sf::Texture cellTexture;
    cellTexture.loadFromFile("img/cell.png");
    Gameboard gameboard(OFFSET, BLOCK_SIZE, BLOCK_COUNT, &cellTexture);

    sf::Font font;
    font.loadFromFile("font/Roboto-Black.ttf");
    Scoreboard scoreboard(SCOREBOARD_SIZE, {0,0}, font);

    sf::Texture fruitTexture;
    fruitTexture.loadFromFile("img/fruit.png");
    Game game(&scoreboard, &fruitTexture, sf::Vector2u(3,3), BLOCK_COUNT, BLOCK_SIZE, OFFSET, 1.0/MPS);
    sf::Clock clock;
    window.setKeyRepeatEnabled(false);

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                window.close();
            if (e.type = sf::Event::KeyPressed)
                if (e.key.code == sf::Keyboard::P)
                    game.pause();
        }

        float deltaTime = clock.restart().asSeconds();
        game.tick(deltaTime);
        window.clear(sf::Color::Black);
        gameboard.draw(window);
        game.draw(window);
        scoreboard.draw(window);
        window.display();
    }
    
    return 0;
}