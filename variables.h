#ifndef VARIABLES_H_
    #define VARIABLES_H_
    #include <SFML/Graphics.hpp>

    sf::Vector2f WINDOW_SIZE(900, 600);
    sf::Vector2f GAMEBOARD_SIZE(600, 600);
    sf::Vector2f SCOREBOARD_SIZE(WINDOW_SIZE.x - GAMEBOARD_SIZE.x, 600);
    sf::Vector2f OFFSET = WINDOW_SIZE - GAMEBOARD_SIZE;
    sf::Vector2u BLOCK_COUNT(30, 30);
    sf::Vector2f BLOCK_SIZE = {GAMEBOARD_SIZE.x / BLOCK_COUNT.x, GAMEBOARD_SIZE.y / BLOCK_COUNT.y};
    float MPS = 6.0f; // MOVES PER SEC
#endif