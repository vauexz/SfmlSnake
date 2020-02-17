#ifndef GAME_H_
    #define GAME_H_
    #include <SFML/Graphics.hpp>
    #include "fruit.h"
    #include "snake.h"

    enum GameStatus {
        Paused,
        Lost,
        InProgress
    };

    class Game {
        private:
            Fruit fruit;
            Snake snake;
            unsigned int score;
            float totalTime;
            float tickTime;
            sf::Vector2u blockCount;
            GameStatus gameStatus;
        public:
            Game(sf::Texture* texture, sf::Vector2u imageCount, sf::Vector2u blockCount, sf::Vector2f blockSize, sf::Vector2f offset, float tickTime);
            unsigned int getScore() { return score; }
            void tick(float deltaTime);
            void draw(sf::RenderWindow& window);
    };

#endif