#include "scoreboard.h"

Scoreboard::Scoreboard(sf::Vector2f size, sf::Vector2f position, sf::Font font) 
: model(size), leaderboard("some.dat") {

    model.setPosition(position);
    model.setFillColor(sf::Color::Magenta);
    score = 0;
    this->font = font;
    setLeaderboardText();
}

void Scoreboard::draw(sf::RenderWindow& window) {
    window.draw(model);
    sf::Text text("Score: " + std::to_string(score) + "\n\nPress P to pause", font);
    text.setCharacterSize(20);
    text.setPosition(model.getPosition() + sf::Vector2f(10,10));
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2);
    window.draw(text);
    window.draw(leaderboardText);
}

bool Scoreboard::checkResult(Player& player) { 
    bool result = leaderboard.checkResult(player); 
    if (result)
        setLeaderboardText();
    return result;
}

void Scoreboard::setLeaderboardText() {
    leaderboardText = sf::Text(leaderboard.getLeaderboard(), font);
    leaderboardText.setCharacterSize(20);
    leaderboardText.setPosition(model.getPosition() + sf::Vector2f(10,200));
    leaderboardText.setOutlineColor(sf::Color::Black);
    leaderboardText.setOutlineThickness(2);
}