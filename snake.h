#ifndef SNAKE_H_
    #define SNAKE_H_
    #include <SFML/Graphics.hpp>
    #include <vector>

    using SegmentPosition = std::vector<sf::Vector2i>;

    class Snake {
        private:
            SegmentPosition segmentsPositions;
            sf::RectangleShape model;
            sf::Vector2f offset;
            sf::Vector2i moveDirection;
            sf::Vector2f blockSize;
        public:
            Snake(sf::Vector2i startPosition, sf::Vector2f blockSize, sf::Vector2f offset);
            void move();
            void draw(sf::RenderWindow& window);
            void extend();
            sf::Vector2i getPosition() { return segmentsPositions[0]; }
            void setMoveDirection(sf::Vector2i moveDirection) { this->moveDirection = moveDirection; }
            bool isCollision();
    };


#endif