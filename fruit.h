#ifndef FRUIT_H_
    #define FRUIT_H_
    #include <SFML/Graphics.hpp>

    class Fruit {
        private:
            sf::RectangleShape fruit;
            sf::Vector2u blockCount;  // XY gameboard size
            sf::Vector2u imageCount; 
            sf::Vector2f imageSize;

        public:
            Fruit(sf::Texture* texture, sf::Vector2u imageCount, sf::Vector2f blockSize, sf::Vector2u blockCount);
            sf::Vector2f getPosition() { return fruit.getPosition(); };
            void setPosition(sf::Vector2f position) { fruit.setPosition(position); };
            sf::RectangleShape getFruit() { return fruit; }
            void respawn();
    };

#endif