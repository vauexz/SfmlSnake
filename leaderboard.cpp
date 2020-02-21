#include "leaderboard.h"

bool compareSnakeSize(const Player& p1, const Player& p2) {
    return p1.getSnakeSize() < p2.getSnakeSize();
}

bool compareScore(const Player& p1, const Player& p2) {
    return p1.getScore() < p2.getScore();
}

void Leaderboard::checkResult(Player& player) {
    bool flag = false;
    if (player.moreScoreThan(bestScore[bestScore.size() - 1])) {
        flag = true;
        bestScore.resize(bestScore.size() - 1);
        bestScore.push_back(player);
        std::sort(bestScore.begin(), bestScore.end(), compareScore);
    }
    if (player.longerSnakeThan(longestSnake[longestSnake.size() - 1])) {
        flag = true;
        longestSnake.resize(longestSnake.size() - 1);
        longestSnake.push_back(player);
        std::sort(longestSnake.begin(), longestSnake.end(), compareSnakeSize);
    }
    if (flag) {
        //save to file
    }
}

void Leaderboard::draw(sf::RenderWindow& window) {
    std::string text = "Best scores (snake size):\n";

    int i = 1;
    for (Player& player : bestScore) {
        text += std::to_string(i++) + ". ";
        text += player.getName() + " - ";
        text += std::to_string(player.getScore());
        text += "(" + std::to_string(player.getSnakeSize()) + ")\n";
    }

    i = 1;
    text += "\nLongest snake (score):\n";
    for (Player& player : longestSnake) {
        text += std::to_string(i++) + ". ";
        text += player.getName() + " - ";
        text += std::to_string(player.getSnakeSize());
        text += "(" + std::to_string(player.getScore()) + ")\n";
    }

    sf::Text txt(text, font);
    txt.setPosition(position);
    window.draw(txt);
}