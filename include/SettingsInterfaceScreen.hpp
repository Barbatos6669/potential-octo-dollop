#pragma once
#include "InterfaceScreen.hpp"

class SettingsInterfaceScreen : public InterfaceScreen 
{
    public:
        SettingsInterfaceScreen(float width, float height, int posX, int posY, const string& titleText, const sf::Color& color = sf::Color(20, 20, 20, 10), const string& iconPath = "");
        ~SettingsInterfaceScreen(); // Default destructor

        void handleEvent(const sf::Event& event, int posX, int posY) override; // Handle events for the settings interface
        void update(sf::RenderWindow& window) override; // Update the settings interface
        void render(sf::RenderWindow& window) override; // Render the settings interface
};