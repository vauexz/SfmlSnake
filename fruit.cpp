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

void Fruit::respawn() {
    sf::Vector2f position((rand() % blockCount.x) * fruit.getSize().x,
        (rand() % blockCount.y) * fruit.getSize().y);
   
    sf::IntRect rect((rand() % imageCount.x) * imageSize.x, (rand() % imageCount.y) * imageSize.y,
        imageSize.x, imageSize.y);
    fruit.setTextureRect(rect);
    setPosition(position);
}