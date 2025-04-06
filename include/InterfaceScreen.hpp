#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>

using namespace std;

class InterfaceScreen
{
    public:        

        float displayWidth = 200.f; // Width of the display
        float displayHeight = 50.f; // Height of the display
        int displayPosX = 0; // X position of the display
        int displayPosY = 0; // Y position of the display

        string title = "Interface"; // Title of the interface
        string iconPath = ""; // Path to the button icon (if needed)
        
        // Constructor to initialize the interface screen
        InterfaceScreen(float width, float height, int posX, int posY, const string& titleText, const sf::Color& color = sf::Color(20, 20, 20, 10), const string& iconPath = "");

        // Destructor
        ~InterfaceScreen() = default; // Default destructor

        // Method to draw the interface screen on the window
        virtual void handleEvent(const sf::Event& event, int posX, int posY) = 0; // Pure virtual function for handling events
        virtual void update(sf::RenderWindow& window) = 0; // Pure virtual function for updating the screen
        virtual void render(sf::RenderWindow& window) = 0; // Pure virtual function for rendering the screen

    private:
        sf::RectangleShape displayPanel; // Rectangle shape for the display panel
        sf::Text titleText; // Text object for displaying the title
        sf::Font font; // Font for the title text
        sf::Color displayColor; // Color of the display panel
        sf::RectangleShape display; // Rectangle shape for the display panel
        sf::Texture backgroundTexture; // Texture for the background
        sf::Sprite backgroundSprite; // Sprite for the background
};
