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
    sf::Text text("Score:", font);
    text.setCharacterSize(20);
    text.setPosition(model.getPosition() + sf::Vector2f(10,10));

    sf::Text sc(std::to_string(score), font);
    sc.setCharacterSize(20);
    sc.setPosition(sf::Vector2f(200, 100) + sf::Vector2f(20, 0));
    
    window.draw(text);
}
