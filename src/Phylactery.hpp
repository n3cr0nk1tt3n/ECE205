#pragma once

#include <SFML/Graphics.hpp>

class Phylactery : public sf::Drawable {
public:
    // Updated constructor to accept texture path
    Phylactery(const std::string& texturePath);

    // Increases the soul count
    void incrementSoul();

    // Check if a point (e.g., mouse click) is inside the sprite bounds
    bool contains(const sf::Vector2f& point) const;

    // Set the position of the sprite
    void setPosition(float x, float y);

private:
    int soulCount;
    sf::Texture texture;
    sf::Sprite sprite;

    // Draw override for rendering
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
