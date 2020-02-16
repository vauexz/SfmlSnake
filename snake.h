#ifndef SNAKE_H_
    #define SNAKE_H_
    #include <SFML/Graphics.hpp>
    #include <vector>

    using SnakeSegments = std::vector<sf::RectangleShape>;

    enum Direction {
        Up,
        Down,
        Left,
        Right
    };

    class Snake {
        private:
            SnakeSegments snakeSegments;
            Direction direction;
        public:
            Snake(sf::Vector2f startPosition, Direction startDirection = Direction::Up);
    };


#endif