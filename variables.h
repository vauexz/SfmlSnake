#ifndef VARIABLES_H_
    #define VARIABLES_H_
    #include <SFML/Graphics.hpp>

    sf::Vector2f WINDOW_SIZE(900, 600);
    sf::Vector2f GAME_BOARD_SIZE(600, 600);
    sf::Vector2f SCORE_BOARD_SIZE(WINDOW_SIZE.x - GAME_BOARD_SIZE.x, 600);
    sf::Vector2f OFFSET = WINDOW_SIZE - GAME_BOARD_SIZE;
    sf::Vector2u BLOCK_COUNT(15, 15);
    sf::Vector2f BLOCK_SIZE = {GAME_BOARD_SIZE.x / BLOCK_COUNT.x, GAME_BOARD_SIZE.y / BLOCK_COUNT.y};
    float MPS = 6.0f; // MOVES PER SEC
#endif