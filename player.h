#ifndef PLAYER_H_
    #define PLAYER_H_

    #include <SFML/Graphics.hpp>
    class Player {
        private:
            std::string name;
            int score;
            int snakeSize;
        public:
            Player(std::string name = "???", int score = 0, int snakeSize = 1) 
                : name(name), score(score), snakeSize(snakeSize) { }
            void setName(std::string name) { this->name = name; }
            std::string getName() const { return name; }
            void setScore(int score) { this->score = score; }
            int getScore() const { return score; }
            void setSnakeSize(int snakeSize) { this->snakeSize = snakeSize; }
            int getSnakeSize() const { return snakeSize; }
    };

#endif