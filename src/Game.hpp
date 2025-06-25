#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Phylactery.hpp"
#include "SpiritPanel.hpp" // Include the new SpiritPanel system

enum class GameState {
    MAIN_MENU,
    IN_GAME,
    PAUSED,
    QUIT_CONFIRM
};

class Game {
public:
    Game();
    ~Game();
    void run();

private:
    sf::RenderWindow window;
    sf::Font font;

    sf::Texture menuBackgroundTexture;
    sf::Sprite menuBackground;

    Phylactery* phylactery;
    SpiritPanel* spiritPanel;

    GameState state;
    bool paused;
    int soulCount;

    std::vector<sf::Text> menuTexts;
    std::vector<sf::Text> pauseTexts;
    std::vector<sf::Text> quitTexts;

    int selectedMenuOption;
    int selectedPauseOption;
    int selectedQuitOption;

    sf::Clock soulClock;

    void processEvents();
    void update();
    void render();
};
