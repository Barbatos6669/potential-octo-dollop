#pragma once
#include "../include/IScreen.hpp"

#include <iostream>

using namespace std;

class MainMenuScreen : public IScreen 
{
public:
    MainMenuScreen(); ///< Constructor for the main menu screen.
    ~MainMenuScreen(); ///< Destructor for the main menu screen.

    void handleEvent(const sf::Event& event) override; ///< Handle events like clicks, keypresses, etc.
    void update() override; ///< Update logic (animations, transitions, etc).
    void render(sf::RenderWindow& window) override; ///< Render screen elements.
};