#include "snake.h"

Snake::Snake(sf::Vector2u startPosition, sf::Vector2f blockSize, sf::Vector2f offset, float moveTime)
: model(blockSize) {
    this->moveTime = moveTime;
    this->offset = offset;
    totalTime = 0;
    segmentsPositions.push_back(startPosition);
    moveDirection = {0,0};
}

void Snake::move(float deltaTime) {
    totalTime += deltaTime;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        moveDirection = {-1, 0};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        moveDirection = {1, 0};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        moveDirection = {0, -1};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        moveDirection = {0, 1};


    if (totalTime >= moveTime) {
        totalTime -= moveTime;

        for (int i = segmentsPositions.size() - 1; i > 0; i--)
            segmentsPositions[i] = segmentsPositions[i-1];        
        segmentsPositions[0] = sf::Vector2u(segmentsPositions[0].x + moveDirection.x, segmentsPositions[0].y + moveDirection.y);
    }
}

void Snake::draw(sf::RenderWindow& window) {

    model.setFillColor(sf::Color::Yellow);
    model.setPosition(sf::Vector2f(
            offset.x + model.getSize().x * segmentsPositions[0].x,
            offset.y + model.getSize().y * segmentsPositions[0].y
        ));
    window.draw(model);

    model.setFillColor(sf::Color::Green);
    for (auto it = segmentsPositions.begin() + 1; it < segmentsPositions.end(); it++) {
        model.setPosition(sf::Vector2f(
            offset.x + model.getSize().x * it->x,
            offset.y + model.getSize().y * it->y
        ));
        window.draw(model);
    }
}
