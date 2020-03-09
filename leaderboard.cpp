#include "leaderboard.h"
#include <iostream>
bool Leaderboard::checkResult(Player& player) {
    bool flag = false;
    if (player.getScore() > bestScore[bestScore.size() - 1].getScore()) {
        flag = true;
        bestScore.push_back(player);
        std::sort(bestScore.rbegin(), bestScore.rend(), [](const Player& p1, const Player& p2) {
                                                            return (p1.getScore() < p2.getScore());
        });
        bestScore.resize(bestScore.size() - 1);
    }   
    if (player.getSnakeSize() > longestSnake[longestSnake.size() - 1].getSnakeSize()) {
        flag = true;
        longestSnake.push_back(player);
        std::sort(longestSnake.rbegin(), longestSnake.rend(), [](const Player& p1, const Player& p2) {
                                                            return (p1.getSnakeSize() < p2.getSnakeSize());
        });
        longestSnake.resize(longestSnake.size() - 1);
    }
    if (flag)
        save();
        
    return flag;
}

std::string Leaderboard::getLeaderboard() {

    std::string text = "Best scores:\n";

    int i = 1;
    for (Player& player : bestScore) {
        text += "\t" + std::to_string(i++) + ". ";
        text += player.getName() + " - ";
        text += std::to_string(player.getScore()) + "\n";
    }

    i = 1;
    text += "\nLongest snake:\n";
    for (Player& player : longestSnake) {
        text += "\t" + std::to_string(i++) + ". ";
        text += player.getName() + " - ";
        text += std::to_string(player.getSnakeSize()) + "\n";
    }

    return text;
}

void Leaderboard::save() {
    std::ofstream file(filename, std::ios_base::binary | std::ios_base::trunc);
    if (!file.is_open()) {
        exit(EXIT_FAILURE);
    } else {
        int size = bestScore.size();
        file.write((const char *)&size, sizeof(size));

        for (Player& p : bestScore) {
            size = p.getName().size();
            file.write((const char *)&size, sizeof(size));
            file.write(&p.getName()[0], size * sizeof(char));
            int res = p.getScore();
            file.write((const char *)&res, sizeof(size));
            res = p.getSnakeSize();
            file.write((const char *)&res, sizeof(size));
        }
        for (Player& p : longestSnake) {
            size = p.getName().size();
            file.write((const char *)&size, sizeof(size));
            file.write(&p.getName()[0], size * sizeof(char));
            int res = p.getScore();
            file.write((const char *)&res, sizeof(size));
            res = p.getSnakeSize();
            file.write((const char *)&res, sizeof(size));
        }
        file.close();
    }
}

void Leaderboard::load() {
    bestScore.resize(0);
    longestSnake.resize(0);
    std::ifstream file(filename, std::ios_base::binary);
    int records;

    if (!file.is_open()) {
        ; // it's ok too, empty leaderboard
    } else {
        file.read((char*)&records, sizeof(int));
        for (int i = 0; i < records; i++) {
            int size, score;
            std::string name;
            file.read((char*)&size, sizeof(int));
            name.resize(size);
            file.read((char *)&name[0], size * sizeof(char));
            file.read((char*)&score, sizeof(int));
            file.read((char*)&size, sizeof(int));

            bestScore.push_back(Player(name, score, size));
        }
        for (int i = 0; i < records; i++) {
            int size, score;
            std::string name;
            file.read((char*)&size, sizeof(int));
            name.resize(size);
            file.read((char *)&name[0], size * sizeof(char));
            file.read((char*)&score, sizeof(int));
            file.read((char*)&size, sizeof(int));
            longestSnake.push_back(Player(name, score, size));
        }
        file.close();
    }
    bestScore.resize(limit, Player());
    longestSnake.resize(limit, Player());
}