#ifndef LEADERBOARD_H
    #define LEADERBOARD_H

    #include <SFML/Graphics.hpp>
    #include <vector>
    #include "player.h"
    class Leaderboard {
        private:
            std::vector<Player> bestScore;
            std::vector<Player> longestSnake;
            sf::Font font;
            sf::Vector2f position;
        public:
            void checkResult(Player& player);
            void draw(sf::RenderWindow& window);
    };

#endif