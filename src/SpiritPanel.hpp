#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "SpiritUnit.hpp"

class SpiritPanel {
public:
    SpiritPanel(sf::Font& font, float x, float y, float width, float height);

    void update(float deltaTime, int currentSouls);
    void updateUnitStates(int currentSouls);
    void handleClick(const sf::Vector2f& mousePos, int& soulCount);
    void scroll(float amount);
    void draw(sf::RenderTarget& target, int currentSouls);
    float getTotalSPS() const;

private:
    sf::Font& font;
    sf::RectangleShape panelBounds;
    std::vector<SpiritUnit> spiritUnits;
    float scrollOffset;
    float unitHeight;
};
