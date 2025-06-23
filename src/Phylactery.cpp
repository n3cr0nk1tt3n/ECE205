#include "Phylactery.hpp"
#include <iostream>

Phylactery::Phylactery(const std::string& texturePath) : soulCount(0) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Failed to load phylactery texture: " << texturePath << std::endl;
    } else {
        sprite.setTexture(texture);
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
