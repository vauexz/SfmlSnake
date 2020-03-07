#ifndef LEADERBOARD_H_
    #define LEADERBOARD_H_

    #include <vector>
    #include <fstream>
    #include "player.h"
    class Leaderboard {
        private:
            const int limit = 5;
            std::string filename;
            std::vector<Player> bestScore;
            std::vector<Player> longestSnake;
        public:
            Leaderboard(std::string filename) : filename(filename) { load(); };
            bool checkResult(Player& player);
            std::string getLeaderboard();    
        private:
            void save();
            void load();
    };

#endif