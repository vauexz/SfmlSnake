#include "snake.h"

Snake::Snake(sf::Vector2f startPosition, Direction startDirection = Direction::Up) {
    snakeSegments.push_back(sf::RectangleShape());
}