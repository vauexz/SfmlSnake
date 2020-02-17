#include "snake.h"

Snake::Snake(sf::Vector2i startPosition, sf::Vector2f blockSize, sf::Vector2f offset)
: model(blockSize * 0.9f) {
    this->offset = offset;
    this->blockSize = blockSize;
    segmentsPositions.push_back(startPosition);
    moveDirection = {0,0};
}

void Snake::move() {

    for (int i = segmentsPositions.size() - 1; i > 0; i--)
        segmentsPositions[i] = segmentsPositions[i-1];        
    segmentsPositions[0] = sf::Vector2i(segmentsPositions[0].x + moveDirection.x, segmentsPositions[0].y + moveDirection.y);
}

void Snake::draw(sf::RenderWindow& window) {

    model.setFillColor(sf::Color::Yellow);
    model.setPosition(sf::Vector2f(
            offset.x + blockSize.x * segmentsPositions[0].x,
            offset.y + blockSize.y * segmentsPositions[0].y
        ));
    window.draw(model);

    model.setFillColor(sf::Color::Green);
    model.setOutlineColor(sf::Color::Magenta);

    for (auto it = segmentsPositions.begin() + 1; it < segmentsPositions.end(); it++) {
        model.setPosition(sf::Vector2f(
            offset.x + blockSize.x * it->x,
            offset.y + blockSize.y * it->y
        ));
        window.draw(model);
    }
}

void Snake::extend() {
    segmentsPositions.push_back(segmentsPositions[segmentsPositions.size() - 1]);
}

bool Snake::isCollision() {
    for (auto it = segmentsPositions.begin() + 1; it < segmentsPositions.end(); it++)
        if (*it == segmentsPositions[0])
            return true;
    return false;
};
