#ifndef GAMEBOARD_H_
    #define GAMEBOARD_H_
    #include <SFML/Graphics.hpp>

    class GameBoard {
        private:
            sf::RectangleShape gameBoard;
            Snake snake;
            Apple apple;
        public:
            GameBoard(sf::Vector2f size, sf::Vector2f position);
    };

#endif