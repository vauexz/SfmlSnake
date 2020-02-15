#ifndef VARIABLES_H_
    #define VARIABLES_H_
    #include <SFML/Graphics.hpp>

    sf::Vector2f WINDOW_SIZE(512.0, 512);

    sf::Vector2f (*BORAD_SIZE)() = []() {
        return sf::Vector2f(WINDOW_SIZE.x * 0.8, WINDOW_SIZE.y);
    };

    sf::Vector2u BOARD_SEGMENTS(30, 30);

#endif