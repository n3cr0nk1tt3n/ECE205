#include "Phylactery.hpp"
#include <iostream>

Phylactery::Phylactery(const std::string& texturePath) : soulCount(0) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Failed to load phylactery texture: " << texturePath << std::endl;
    } else {
        sprite.setTexture(texture);

        // Scale to about 200x200 px
        float scaleX = 200.0f / texture.getSize().x;
        float scaleY = 200.0f / texture.getSize().y;
        sprite.setScale(scaleX, scaleY);

        // Center on screen (800x600)
        float posX = 400.0f - (sprite.getGlobalBounds().width / 2);
        float posY = 300.0f - (sprite.getGlobalBounds().height / 2);
        sprite.setPosition(posX, posY);
    }
}

void Phylactery::incrementSoul() {
    soulCount++;
}

bool Phylactery::contains(const sf::Vector2f& point) const {
    return sprite.getGlobalBounds().contains(point);
}

void Phylactery::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void Phylactery::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}
