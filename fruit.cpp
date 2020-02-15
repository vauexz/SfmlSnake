#include "fruit.h"
#include <cstdlib>

Fruit::Fruit(sf::Texture* texture, sf::Vector2u imageCount, sf::Vector2f blockSize, sf::Vector2u blockCount) 
:imageSize(texture->getSize().x / imageCount.x, texture->getSize().y / imageCount.y) {

    this->blockCount = blockCount;
    this->imageCount = imageCount;

    fruit.setSize(blockSize);
    fruit.setTexture(texture);
    respawn();
}

sf::Vector2u Fruit::getPosition() {
    return sf::Vector2u(
        static_cast<unsigned int> (fruit.getPosition().x / fruit.getSize().x),
        static_cast<unsigned int> (fruit.getPosition().y / fruit.getSize().y)
    );
}

void Fruit::respawn() {
    sf::Vector2f position((rand() % blockCount.x) * fruit.getSize().x,
        (rand() % blockCount.y) * fruit.getSize().y);
   
    sf::IntRect rect((rand() % imageCount.x) * imageSize.x, (rand() % imageCount.y) * imageSize.y,
        imageSize.x, imageSize.y);
    fruit.setTextureRect(rect);
    setPosition(position);
}

void Fruit::draw(sf::RenderWindow& window) {
    window.draw(fruit);
};
