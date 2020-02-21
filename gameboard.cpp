#include "gameboard.h"

Gameboard::Gameboard(sf::Vector2f offset, sf::Vector2f blockSize, sf::Vector2u blockCount, sf::Texture* cellTexture) 
: model(blockSize) {
    this->offset = offset;
    this->blockCount = blockCount;
    model.setTexture(cellTexture);
}

void Gameboard::draw(sf::RenderWindow& window) {
    auto size = model.getSize();
    for (int i = 0; i < blockCount.y; i++)
        for (int j = 0; j < blockCount.x; j++) {
            model.setPosition({offset.x + j * size.x, offset.y + i * size.y});
            window.draw(model);
        }
}