#pragma once

#include <SFML/Graphics.hpp>

class Phylactery : public sf::Drawable {
public:
    Phylactery(const std::string& texturePath);
    void incrementSoul();
    bool contains(const sf::Vector2f& point) const;
    void setPosition(float x, float y);

private:
    int soulCount;
    sf::Texture texture;
    sf::Sprite sprite;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
