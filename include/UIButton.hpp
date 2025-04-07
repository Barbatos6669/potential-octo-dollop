#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "UIConfig.hpp"


class UIButton
{
    public:
        sf::RectangleShape buttonShape; // Button shape
        sf::Text buttonText; // Button text
        sf::Font buttonFont; // Button font
        sf::Color buttonColor; // Button color
        sf::Color hoverColor; // Hover color
        sf::Color clickColor; // Click color
        sf::Color textColor; // Text color
        sf::Color textHoverColor; // Text hover color
        sf::Color textClickColor; // Text click color
        sf::Mouse::Button mouseButton; // Mouse button for events

        // Icons
        sf::Texture buttonIcon; // Button icon texture
        sf::Sprite buttonIconSprite; // Button icon sprite

        int buttonWidth; // Width of the button
        int buttonHeight; // Height of the button
        int posX; // X position of the button
        int posY; // Y position of the button

        std::string buttonTextString; // Text string of the button
        std::string buttonIconPath; // Path to the button icon 
        
        UIButton(int width = 100, int height = 50, int x = 0, int y = 0, sf::Color color = sf::Color(50, 50, 50), std::string text = "Button", std::string tex = ""); // Constructor with default values

        ~UIButton(); // Destructor

        void render(sf::RenderWindow& window); // Render the button
        void update(); // Update the button properties
        void processEvents(sf::Event& event); // Process events related to the button

};