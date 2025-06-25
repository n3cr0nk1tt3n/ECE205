#include "SpiritPanel.hpp"
#include <iostream>

SpiritPanel::SpiritPanel(sf::Font& font, float x, float y, float width, float height)
    : font(font), panelBounds(sf::Vector2f(width, height)), scrollOffset(0.0f)
{
    panelBounds.setPosition(x, y);
    panelBounds.setFillColor(sf::Color(10, 10, 10, 200));
    panelBounds.setOutlineColor(sf::Color::White);
    panelBounds.setOutlineThickness(2.0f);

    unitHeight = 100.0f;

    spiritUnits.push_back(SpiritUnit("Spectral Hand", "Passive: +0.01 souls/s", 100, 0.01f, "assets/spectral_hand.png"));
    spiritUnits.push_back(SpiritUnit("Wailing Skull", "Passive: +0.05 souls/s", 500, 0.05f, "assets/wailing_skull.png"));
    spiritUnits.push_back(SpiritUnit("Ghostly Scribe", "Passive: +0.20 souls/s", 1000, 0.2f, "assets/ghostly_scribe.png"));
    spiritUnits.push_back(SpiritUnit("Poltergeist Monk", "Passive: +0.50 souls/s", 2500, 0.5f, "assets/poltergeist_monk.png"));
    spiritUnits.push_back(SpiritUnit("Grave Whisperer", "Passive: +2.00 souls/s", 5000, 2.0f, "assets/grave_whisperer.png"));
}

void SpiritPanel::update(float deltaTime, int currentSouls) {
    for (auto& unit : spiritUnits) {
        unit.update(deltaTime);
    }
    updateUnitStates(currentSouls);
}

void SpiritPanel::updateUnitStates(int currentSouls) {
    bool unlockNext = true;

    for (auto& unit : spiritUnits) {
        if (unlockNext) {
            unit.setVisible(true);
            unit.setEnabled(currentSouls >= unit.getCost());
            unlockNext = currentSouls >= unit.getCost();
        } else {
            unit.setVisible(false);
        }
    }
}

void SpiritPanel::handleClick(const sf::Vector2f& mousePos, int& soulCount) {
    float yOffset = panelBounds.getPosition().y + scrollOffset;

    for (auto& unit : spiritUnits) {
        if (!unit.isVisible())
            continue;

        sf::FloatRect bounds(panelBounds.getPosition().x + 10, yOffset + 10,
                             panelBounds.getSize().x - 20, unitHeight - 10);
        if (bounds.contains(mousePos)) {
            if (soulCount >= unit.getCost()) {
                soulCount -= unit.getCost();
                unit.purchase();
                std::cout << "Purchased: " << unit.getName() << std::endl;
            }
            break;
        }

        yOffset += unitHeight;
    }
}

float SpiritPanel::getTotalSPS() const {
    float total = 0.0f;
    for (const auto& unit : spiritUnits) {
        total += unit.getSoulsPerSecond();
    }
    return total;
}

void SpiritPanel::scroll(float amount) {
    scrollOffset += amount;
}

void SpiritPanel::draw(sf::RenderTarget& target, int currentSouls) {
    target.draw(panelBounds);

    float yOffset = panelBounds.getPosition().y + scrollOffset;
    for (const auto& unit : spiritUnits) {
        if (!unit.isVisible())
            continue;

        unit.draw(target,
                  sf::Vector2f(panelBounds.getPosition().x + 10, yOffset + 10),
                  panelBounds.getSize().x - 20,
                  unitHeight - 10,
                  currentSouls);
        yOffset += unitHeight;
    }
}
