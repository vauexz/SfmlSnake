#include "variables.h"
#include <cstdlib>
#include <ctime>
#include "game.h"
#include "scoreboard.h"
int main() {
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Snake Game");

    sf::Font font;
    font.loadFromFile("font/Roboto-Black.ttf");
    Scoreboard scoreboard(SCOREBOARD_SIZE, {0,0}, font);

    sf::RectangleShape gameBoard(GAMEBOARD_SIZE);
    gameBoard.setPosition(OFFSET);
    gameBoard.setFillColor(sf::Color(100,30,200));
    
    sf::Texture fruitTexture;
    fruitTexture.loadFromFile("img/fruit.png");
    Game game(&scoreboard, &fruitTexture, sf::Vector2u(3,3), BLOCK_COUNT, BLOCK_SIZE, OFFSET, 1.0/MPS);
    window.setKeyRepeatEnabled(false);
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                window.close();
            if (e.type = sf::Event::KeyPressed)
                if (e.key.code == sf::Keyboard::G)
                    game.pause();
        }

        float deltaTime = clock.restart().asSeconds();
        game.tick(deltaTime);
        window.clear(sf::Color::Black);
        window.draw(gameBoard);
        game.draw(window);
        scoreboard.draw(window);
        window.display();
    }
    
    return 0;
}