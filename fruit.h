#ifndef FRUIT_H_
    #define FRUIT_H_
    #include <SFML/Graphics.hpp>

    class Fruit {
        private:
            sf::RectangleShape fruit;
            sf::Vector2f imageSize;

            sf::Vector2u blockCount;  // XY gameboard size
            sf::Vector2u imageCount;
            sf::Vector2f offset;
            sf::Vector2i position;

        public:
            Fruit(sf::Texture* texture, sf::Vector2u imageCount, sf::Vector2f blockSize, sf::Vector2u blockCount, sf::Vector2f offset);
            sf::Vector2i getPosition() { return position; }
            void respawn();
            void draw(sf::RenderWindow& window);
    };

#endif