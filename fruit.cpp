#include "fruit.h"
#include <cstdlib>

Fruit::Fruit(sf::Texture* texture, sf::Vector2u imageCount, sf::Vector2f blockSize, sf::Vector2u blockCount, sf::Vector2f offset) 
:imageSize(texture->getSize().x / imageCount.x, texture->getSize().y / imageCount.y) {

    this->blockCount = blockCount;
    this->imageCount = imageCount;
    this->offset = offset;

    fruit.setSize(blockSize);
    fruit.setTexture(texture);
    respawn();
}

void Fruit::respawn() {
    position = {
        rand() % blockCount.x,
        rand() % blockCount.y
    };
   
    sf::IntRect rect((rand() % imageCount.x) * imageSize.x, (rand() % imageCount.y) * imageSize.y,
        imageSize.x, imageSize.y);
    fruit.setTextureRect(rect);
}

void Fruit::draw(sf::RenderWindow& window) {
    fruit.setPosition(
        offset.x + position.x * fruit.getSize().x,
        offset.y + position.y * fruit.getSize().y
    );
    window.draw(fruit);
};
