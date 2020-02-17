#ifndef SNAKE_H_
    #define SNAKE_H_
    #include <SFML/Graphics.hpp>
    #include <vector>

    using SegmentPosition = std::vector<sf::Vector2u>;

    class Snake {
        private:
            SegmentPosition segmentsPositions;
            sf::RectangleShape model;
            sf::Vector2f offset;
            sf::Vector2f moveDirection;
            float totalTime;
            float moveTime;
        public:
            Snake(sf::Vector2u startPosition, sf::Vector2f blockSize, sf::Vector2f offset, float moveTime = 0.2);
            void move(float deltaTime);
            void draw(sf::RenderWindow& window);
    };


#endif