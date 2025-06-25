#include "Game.hpp"
#include <iostream>

Game::Game()
    : window(sf::VideoMode(800, 600), "The Curse of Kursore"),
      font(), menuBackground(), phylactery(nullptr),
      state(GameState::MAIN_MENU), paused(false), soulCount(0),
      selectedMenuOption(0), selectedPauseOption(0), selectedQuitOption(0) {

    if (!font.loadFromFile("assets/OpenSans-VariableFont_wdth,wght.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
    }

    if (!menuBackgroundTexture.loadFromFile("assets/mainmenu.png")) {
        std::cerr << "Failed to load main menu image" << std::endl;
    }
    menuBackground.setTexture(menuBackgroundTexture);
    menuBackground.setScale(
        static_cast<float>(window.getSize().x) / menuBackgroundTexture.getSize().x,
        static_cast<float>(window.getSize().y) / menuBackgroundTexture.getSize().y
    );

    std::vector<std::string> mainMenuStrings = {"Play", "Options", "Credits", "Quit"};
    for (size_t i = 0; i < mainMenuStrings.size(); ++i) {
        sf::Text text(mainMenuStrings[i], font, 24);
        text.setPosition(50, 100 + i * 40);
        menuTexts.push_back(text);
    }

    std::vector<std::string> pauseMenuStrings = {"Resume", "Quit to Main Menu"};
    for (size_t i = 0; i < pauseMenuStrings.size(); ++i) {
        sf::Text text(pauseMenuStrings[i], font, 24);
        text.setPosition(50, 100 + i * 40);
        pauseTexts.push_back(text);
    }

    std::vector<std::string> quitConfirmStrings = {
        "Are you sure you want to quit?",
        "Yes",
        "No"
    };
    for (size_t i = 0; i < quitConfirmStrings.size(); ++i) {
        sf::Text text(quitConfirmStrings[i], font, 24);
        text.setPosition(50, 100 + i * 40);
        quitTexts.push_back(text);
    }

    phylactery = new Phylactery("assets/phylactery.png");
}

Game::~Game() {
    delete phylactery;
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (state == GameState::MAIN_MENU) {
                    if (event.key.code == sf::Keyboard::Down)
                        selectedMenuOption = (selectedMenuOption + 1) % menuTexts.size();
                    else if (event.key.code == sf::Keyboard::Up)
                        selectedMenuOption = (selectedMenuOption - 1 + menuTexts.size()) % menuTexts.size();
                    else if (event.key.code == sf::Keyboard::Enter) {
                        switch (selectedMenuOption) {
                            case 0:
                                state = GameState::IN_GAME;
                                break;
                            case 1:
                                break;
                            case 2:
                                break;
                            case 3:
                                state = GameState::QUIT_CONFIRM;
                                break;
                        }
                    }
                } else if (state == GameState::IN_GAME) {
                    if (event.key.code == sf::Keyboard::Escape)
                        paused = !paused;
                    state = paused ? GameState::PAUSED : GameState::IN_GAME;
                } else if (state == GameState::PAUSED) {
                    if (event.key.code == sf::Keyboard::Down)
                        selectedPauseOption = (selectedPauseOption + 1) % pauseTexts.size();
                    else if (event.key.code == sf::Keyboard::Up)
                        selectedPauseOption = (selectedPauseOption - 1 + pauseTexts.size()) % pauseTexts.size();
                    else if (event.key.code == sf::Keyboard::Enter) {
                        switch (selectedPauseOption) {
                            case 0:
                                state = GameState::IN_GAME;
                                paused = false;
                                break;
                            case 1:
                                state = GameState::MAIN_MENU;
                                break;
                        }
                    }
                } else if (state == GameState::QUIT_CONFIRM) {
                    if (event.key.code == sf::Keyboard::Down)
                        selectedQuitOption = (selectedQuitOption + 1) % 2;
                    else if (event.key.code == sf::Keyboard::Up)
                        selectedQuitOption = (selectedQuitOption - 1 + 2) % 2;
                    else if (event.key.code == sf::Keyboard::Enter) {
                        if (selectedQuitOption == 0) window.close();
                        else state = GameState::MAIN_MENU;
                    }
                }
                break;

            case sf::Event::MouseButtonPressed:
                if (state == GameState::IN_GAME && event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f clickPosition(event.mouseButton.x, event.mouseButton.y);
                    if (phylactery->contains(clickPosition)) {
                        phylactery->incrementSoul();
                        soulCount++;
                        std::cout << "Soul Count: " << soulCount << std::endl;
                    }
                }
                break;

            default:
                break;
        }
    }
}

void Game::update() {
    // Reserved for logic updates
}

void Game::render() {
    window.clear();

    if (state == GameState::MAIN_MENU) {
        window.draw(menuBackground);
        for (size_t i = 0; i < menuTexts.size(); ++i) {
            menuTexts[i].setFillColor(i == selectedMenuOption ? sf::Color::Yellow : sf::Color::White);
            window.draw(menuTexts[i]);
        }
    } else {
        window.draw(*phylactery);

        if (state == GameState::IN_GAME) {
            sf::Text soulText;
            soulText.setFont(font);
            soulText.setCharacterSize(24);
            soulText.setFillColor(sf::Color::White);
            soulText.setString("Souls: " + std::to_string(soulCount));
            soulText.setPosition(10.f, 10.f);
            window.draw(soulText);
        }

        if (state == GameState::PAUSED) {
            for (size_t i = 0; i < pauseTexts.size(); ++i) {
                pauseTexts[i].setFillColor(i == selectedPauseOption ? sf::Color::Yellow : sf::Color::White);
                window.draw(pauseTexts[i]);
            }
        } else if (state == GameState::QUIT_CONFIRM) {
            for (size_t i = 0; i < quitTexts.size(); ++i) {
                quitTexts[i].setFillColor((i - 1) == selectedQuitOption ? sf::Color::Red : sf::Color::White);
                window.draw(quitTexts[i]);
            }
        }
    }

    window.display();
}
