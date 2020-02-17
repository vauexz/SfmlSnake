#include "variables.h"
#include <cstdlib>
#include <ctime>
#include "game.h"

/*
    TO DO:
        SCORE BOARD
        GAME BOARD
        TRY TO FIX MOVE

*/

int main() {
    srand(time(NULL));
    sf::Texture ground;
    ground.loadFromFile("img/ground.png");
    sf::RectangleShape gameBoard(GAME_BOARD_SIZE);
    gameBoard.setPosition(OFFSET);
    gameBoard.setTexture(&ground);

    sf::RectangleShape scoreBoard(SCORE_BOARD_SIZE);
    scoreBoard.setPosition({0, 0});
    scoreBoard.setFillColor(sf::Color::Magenta);

    sf::Texture apl;
    apl.loadFromFile("img/fruit.png");
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Snake Game");
    Game game(&apl, sf::Vector2u(3,3), BLOCK_COUNT, BLOCK_SIZE, OFFSET, 1.0/MPS);

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
        window.draw(gameBoard);
        game.draw(window);
        window.draw(scoreBoard);
        window.display();

    }
    
    return 0;
}