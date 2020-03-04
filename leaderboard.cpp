#include "leaderboard.h"

void Leaderboard::checkResult(Player& player) {
    bool flag = false;
    if (player.getScore() > bestScore[bestScore.size() - 1].getScore()) {
        flag = true;
        bestScore.resize(bestScore.size() - 1);
        bestScore.push_back(player);
        std::sort(bestScore.begin(), bestScore.end(), [](const Player& p1, const Player& p2) {
                                                            return p1.getScore() < p2.getScore();
        });
    }
    if (player.getSnakeSize() > bestScore[bestScore.size() - 1].getSnakeSize()) {
        flag = true;
        longestSnake.resize(longestSnake.size() - 1);
        longestSnake.push_back(player);
        std::sort(longestSnake.begin(), longestSnake.end(), [](const Player& p1, const Player& p2) {
                                                            return p1.getSnakeSize() < p2.getSnakeSize();
        });
    }
    if (flag) {
        //save to file
    }
}

std::string Leaderboard::getLeaderboard() {

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

    return text;
}
