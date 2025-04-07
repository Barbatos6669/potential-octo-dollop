#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "iostream"
#include "UIConfig.hpp"

class UIState
{
    public:
        sf::RectangleShape windowPanel; // Left panel shape
        sf::Text titleText; // Title text
        sf::Font titleFont; // Title font

        std::string titleString; // Title string

        int panelWidth; // Width of the panel
        int panelHeight; // Height of the panel
        int posX; // X position of the panel
        int posY; // Y position of the panel

        // Constructor and Destructor
        UIState(int width = 200, int height = 800, int x = 0, int y = 0, std::string title = "UI State"); // Constructor with default values
        ~UIState(); // Destructor

        void render(sf::RenderWindow& window); // Render the UI state
        void update(); // Update the UI state
        void processEvents(sf::Event& event); // Process events related to the UI state
};