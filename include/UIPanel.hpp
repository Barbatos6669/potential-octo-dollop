#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "iostream"
#include "UIConfig.hpp"

class UIPanel
{
    public:
        sf::RectangleShape windowPanel; // Left panel shape
        sf::RectangleShape panelOffset; // Offset panel shape

        sf::Color panelColor; // Color of the panel

        int panelWidth; // Width of the panel
        int panelHeight; // Height of the panel
        int posX; // X position of the panel
        int posY; // Y position of the panel     

        // Option to add a background image
        sf::Texture backgroundTexture; // Background texture
        sf::Sprite backgroundSprite; // Background sprite
        bool hasBackground; // Flag to indicate if the panel has a background image

        // Constructor and Destructor
        UIPanel(int width = UIConfig::panelWidth, int height = UIConfig::panelHeight, int x = 0, int y = 0, sf::Color color = sf::Color(50, 50, 50), const std::string& backgroundImagePath = ""); // Constructor with default values
        
        ~UIPanel();

        void draw(sf::RenderWindow& window); // Draw the panel
        void update(); // Update the panel properties
        void processEvents(sf::Event& event); // Process events related to the panel
};