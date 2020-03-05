#ifndef GAME_H_
    #define GAME_H_
    #include <SFML/Graphics.hpp>
    #include "fruit.h"
    #include "snake.h"
    #include "scoreboard.h"
    #include "player.h"

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
            float bonusTime;        // each bonusTime secs player gets snake.size bonus
            float totalBonusTime;
            sf::Vector2u blockCount;
            GameStatus gameStatus;
            sf::Font font;
            sf::Vector2f offset;
            sf::Vector2f blockSize;
            Scoreboard* scoreboard;
            sf::Text* loseInfo = nullptr;
            Player* player = nullptr;
        public:
            Game(Scoreboard* scoreboard, sf::Texture* texture, sf::Vector2u imageCount, sf::Vector2u blockCount, sf::Vector2f blockSize, sf::Vector2f offset, float tickTime, sf::Font font);
            void tick(float deltaTime);
            void draw(sf::RenderWindow& window);
            void pause();
        private:
            void restart();
    };

#endif