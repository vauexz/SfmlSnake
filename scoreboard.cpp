#include "scoreboard.h"

Scoreboard::Scoreboard(sf::Vector2f size, sf::Vector2f position, sf::Font font) 
: model(size) {

    model.setPosition(position);
    model.setFillColor(sf::Color::Magenta);
    score = 0;
    this->font = font;
}

void Scoreboard::draw(sf::RenderWindow& window) {
    window.draw(model);
    sf::Text text("Score: " + std::to_string(score), font);
    text.setCharacterSize(20);
    text.setPosition(model.getPosition() + sf::Vector2f(10,10));

    window.draw(text);
}
