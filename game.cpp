#include "game.h"

Game::Game(sf::Texture* texture, sf::Vector2u imageCount, sf::Vector2u blockCount, sf::Vector2f blockSize, sf::Vector2f offset, float tickTime) 
:   fruit(texture, imageCount, blockSize, blockCount, offset),
    snake(sf::Vector2i(blockCount.x / 2, blockCount.y / 2), blockSize, offset) {
    
    totalTime = 0.0f;
    this->tickTime = tickTime;
    this->blockCount = blockCount;
    gameStatus = GameStatus::InProgress;
}

void Game::tick(float deltaTime) {
    
    //to fix
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        if (gameStatus == GameStatus::InProgress)
            gameStatus = GameStatus::Paused;
        else if (gameStatus == GameStatus::Paused)
            gameStatus = GameStatus::InProgress;


    if (gameStatus == GameStatus::InProgress) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            snake.setMoveDirection({-1, 0});
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            snake.setMoveDirection({1, 0});
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            snake.setMoveDirection({0, -1});
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            snake.setMoveDirection({0, 1});

        totalTime += deltaTime;
        if (totalTime >= tickTime) {
            totalTime -= tickTime;

            snake.move();
            if (
                snake.isCollision()
                || snake.getPosition().x < 0 || snake.getPosition().x >= blockCount.x
                || snake.getPosition().y < 0 || snake.getPosition().y >= blockCount.y
            ) {
                gameStatus = GameStatus::Lost;
                /* some more stuff when game is lost */
            } else if ( snake.getPosition() == fruit.getPosition()) {
                fruit.respawn();
                snake.extend();
            }
    }


    }
}


void Game::draw(sf::RenderWindow& window) {
    snake.draw(window);
    fruit.draw(window);
};
