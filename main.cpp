#include "variables.h"
#include "game.h"
#include "scoreboard.h"
#include "gameboard.h"
int main() {
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Snake Game", sf::Style::Default ^ sf::Style::Resize);

    sf::Texture cellTexture;
    cellTexture.loadFromFile("img/cell.png");
    Gameboard gameboard(OFFSET, BLOCK_SIZE, BLOCK_COUNT, &cellTexture);

    sf::Font font;
    font.loadFromFile("font/Roboto-Black.ttf");
    Scoreboard scoreboard(SCOREBOARD_SIZE, {0,0}, font, "highscores/highscores.dat");

    sf::Texture fruitTexture;
    fruitTexture.loadFromFile("img/fruit.png");
    Game game(&scoreboard, &fruitTexture, sf::Vector2u(3,3), BLOCK_COUNT, BLOCK_SIZE, OFFSET, 1.0/MPS, font);
    sf::Clock clock;
    window.setKeyRepeatEnabled(false);

    int i = 0;
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            switch (e.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed: 
                    if (game.getStatus() == GameStatus::PlayerNameInput)
                        game.inputLetter(e.key.code);
                    else if (e.key.code == sf::Keyboard::P)
                            game.pause();
                    break;
            }
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