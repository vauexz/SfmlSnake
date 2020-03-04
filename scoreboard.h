#ifndef SCOREBOARD_H_
    #define SCOREBOARD_H_
    #include <SFML/Graphics.hpp>
    #include <vector>
    #include "player.h"

    class Scoreboard {
        private:
            int score;
            sf::RectangleShape model;
            sf::Font font;
            std::vector<std::string> info;
            std::vector<Player> bestScores;
            std::vector<std::string> longestSnakes;
        public:
            Scoreboard(sf::Vector2f size, sf::Vector2f position, sf::Font font);
            void draw(sf::RenderWindow& window);
            void setScore(int score) { this->score = score; }
    };

#endif