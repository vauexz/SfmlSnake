#ifndef SCOREBOARD_H_
    #define SCOREBOARD_H_
    #include <SFML/Graphics.hpp>
    #include <vector>
    #include "player.h"
    #include "leaderboard.h"

    class Scoreboard {
        private:
            int score;
            sf::RectangleShape model;
            sf::Font font;
            Leaderboard leaderboard;
            sf::Text leaderboardText;
        public:
            Scoreboard(sf::Vector2f size, sf::Vector2f position, sf::Font font, std::string filename);
            void draw(sf::RenderWindow& window);
            void setScore(int score) { this->score = score; }
            bool checkResult(Player& player);

        private:
            void setLeaderboardText();
    };

#endif