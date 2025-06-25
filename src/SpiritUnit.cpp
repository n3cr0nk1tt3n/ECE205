#include "SpiritUnit.hpp"
#include <iostream>
#include <sstream>

SpiritUnit::SpiritUnit(const std::string& name,
                       const std::string& description,
                       int baseCost,
                       float sps,
                       const std::string& iconPath)
    : name(name), description(description), baseCost(baseCost), soulsPerSecond(sps),
      iconPath(iconPath), count(0), visible(false), enabled(false) {
    
    if (!iconTexture.loadFromFile(iconPath)) {
        std::cerr << "Failed to load texture: " << iconPath << std::endl;
    } else {
        iconSprite.setTexture(iconTexture);
        iconSprite.setScale(0.75f, 0.75f); // Scale sprite as needed
    }
}

void SpiritUnit::update(float deltaTime) {
    // Placeholder if you want timed animations later
}

void SpiritUnit::draw(sf::RenderTarget& target, const sf::Vector2f& position, float width, float height, int currentSouls) const {
    sf::RectangleShape background(sf::Vector2f(width, height));
    background.setPosition(position);
    background.setFillColor(enabled ? sf::Color(50, 50, 50) : sf::Color(30, 30, 30));
    target.draw(background);

    // "Summon" Button with cost
    sf::Text buttonText;
    static sf::Font font;
    static bool fontLoaded = false;
    if (!fontLoaded) {
        if (!font.loadFromFile("assets/pixel_font.ttf")) {
            std::cerr << "Failed to load font in SpiritUnit draw()" << std::endl;
        } else {
            fontLoaded = true;
        }
    }
    buttonText.setFont(font);
    std::stringstream ss;
    ss << "Summon\n" << getCost();
    buttonText.setString(ss.str());
    buttonText.setCharacterSize(14);
    buttonText.setFillColor(currentSouls >= getCost() ? sf::Color::White : sf::Color::Red);
    buttonText.setPosition(position.x + 5, position.y + 5);
    target.draw(buttonText);

    // Unit name & description (middle 1/3)
    sf::Text infoText(name + "\n" + description, font, 14);
    infoText.setFillColor(sf::Color::White);
    infoText.setPosition(position.x + width / 3.0f, position.y + 5);
    target.draw(infoText);

    // Unit icon (right 1/3)
    sf::Sprite icon = iconSprite;
    icon.setPosition(position.x + width * 0.66f, position.y + 5);
    target.draw(icon);
}

void SpiritUnit::purchase() {
    count++;
}

int SpiritUnit::getCost() const {
    return baseCost * (count + 1); // Cost scales linearly
}

float SpiritUnit::getSoulsPerSecond() const {
    return count * soulsPerSecond;
}

void SpiritUnit::setVisible(bool visibility) {
    visible = visibility;
}

void SpiritUnit::setEnabled(bool en) {
    enabled = en;
}

bool SpiritUnit::isVisible() const {
    return visible;
}

bool SpiritUnit::isEnabled() const {
    return enabled;
}

const std::string& SpiritUnit::getName() const {
    return name;
}

int SpiritUnit::getCount() const {
    return count;
}
