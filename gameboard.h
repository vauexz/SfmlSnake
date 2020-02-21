#ifndef GAMEBOARD_H_
    #define GAMEBOARD_H_
    #include <SFML/Graphics.hpp>

    class Gameboard {
        private:
            sf::Vector2f offset;
            sf::Vector2u blockCount;
            sf::RectangleShape model;
        public:
            Gameboard(sf::Vector2f offset, sf::Vector2f blockSize, sf::Vector2u blockCount, sf::Texture*);
            void draw(sf::RenderWindow& window);
    };

#endif