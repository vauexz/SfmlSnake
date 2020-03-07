#include "game.h"
#include <iostream>
Game::Game(Scoreboard* scoreboard, sf::Texture* texture, sf::Vector2u imageCount, sf::Vector2u blockCount, sf::Vector2f blockSize, sf::Vector2f offset, float tickTime, sf::Font font) 
: fruit(texture, imageCount, blockSize, blockCount, offset),
  snake(sf::Vector2i(blockCount.x / 2, blockCount.y / 2), blockSize, offset) {
    
    this->scoreboard = scoreboard;
    totalTime = totalBonusTime = 0.0f;
    bonusTime = 5.0f;
    this->tickTime = tickTime;
    this->blockCount = blockCount;
    gameStatus = GameStatus::InProgress;
    this->font = font;
    this->offset = offset;
    this->blockSize = blockSize;
}

void Game::tick(float deltaTime) {
    
    if (gameStatus == GameStatus::InProgress) {
        if (snake.getMoveDirection() != sf::Vector2i(0, 0)) {
            totalBonusTime += deltaTime;
            if (totalBonusTime >= bonusTime) {
                score += snake.getSize();
                totalBonusTime -= bonusTime;
                scoreboard->setScore(score);
            }
        }

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
            } else if ( snake.getPosition() == fruit.getPosition()) {
                fruit.respawn();
                snake.extend();
                score += 10;
                scoreboard->setScore(score);
            }
        }
    } else if (gameStatus == GameStatus::Lost) {
        auto pl = Player("XDdapqoelD", score, snake.getSize());
        scoreboard->checkResult(pl);

        //it can be better some day
        std::string text = 
            "You lost the game :(\n"
            "Press R to restart\n";

        loseInfo = new sf::Text(text, font);
        loseInfo->setCharacterSize(30);
        loseInfo->setPosition(sf::Vector2f(
            offset.x + blockCount.x/3 * blockSize.x,
            offset.y + blockCount.x/3 * blockSize.y
        ));
        loseInfo->setOutlineColor(sf::Color::White);
        loseInfo->setOutlineThickness(2);
        loseInfo->setFillColor(sf::Color::Black);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            delete loseInfo;
            loseInfo = nullptr;
            restart();
        }
    }
}

void Game::draw(sf::RenderWindow& window) {
    snake.draw(window);
    fruit.draw(window);
    if (loseInfo != nullptr)
        window.draw(*loseInfo);
};

void Game::restart() {
    totalTime = totalBonusTime = score = 0;
    gameStatus = InProgress;
    fruit.respawn();
    snake.restart(sf::Vector2i(blockCount.x/2, blockCount.y/2));
    scoreboard->setScore(score);
    
    //player-> setScore(0);
    //player-> setSnakeSize(1);
}

void Game::pause() {
    if (gameStatus == GameStatus::InProgress)
        gameStatus = GameStatus::Paused;
    else if (gameStatus == GameStatus::Paused)
        gameStatus = GameStatus::InProgress;
}