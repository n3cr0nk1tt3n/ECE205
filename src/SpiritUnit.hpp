#pragma once
#include <SFML/Graphics.hpp>
#include <string>

struct SpiritUnit {
public:
    SpiritUnit(const std::string& name,
               const std::string& description,
               int baseCost,
               float sps,
               const std::string& iconPath);

    void update(float deltaTime);
    void draw(sf::RenderTarget& target, const sf::Vector2f& position, float width, float height, int currentSouls) const;
    void purchase();

    void setVisible(bool visibility);
    void setEnabled(bool enabled);
    bool isVisible() const;
    bool isEnabled() const;

    float getSoulsPerSecond() const;
    int getCost() const;
    const std::string& getName() const;
    int getCount() const;

private:
    std::string name;
    std::string description;
    int baseCost;
    float soulsPerSecond;
    std::string iconPath;

    int count = 0;
    bool visible = false;
    bool enabled = false;

    sf::Texture iconTexture;
    sf::Sprite iconSprite;
};
