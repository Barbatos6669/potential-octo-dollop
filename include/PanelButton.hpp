#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <string>

using namespace std;

class PanelButton 
{
    public:
        float buttonWidth = 200.f; // Width of the button
        float buttonHeight = 50.f; // Height of the button
        int buttonPosX = 0; // X position of the button
        int buttonPosY = 0; // Y position of the button

        string buttonTextString = "Button"; // Text to display on the button

        string iconPath = ""; // Path to the button icon (if needed)
        
        sf::Color buttonColor = sf::Color(20, 20, 20, 10); // Color of the button

        // Constructor to initialize the button
        PanelButton(float width, float height, int posX, int posY, const string& text, const string& iconPath = "", const sf::Color& color = sf::Color(20, 20, 20, 10));

        // Destructor
        ~PanelButton();

        // Method to draw the button on the window
        void draw(sf::RenderWindow& window);
        void processEvent(sf::Event event, int posX, int posY); // Method to handle input events for the button
        void setButtonColor(const sf::Color& color); // Method to set the button color

    private:
        sf::RectangleShape button; // Rectangle shape for the button
        sf::Text buttonText; // Text object for displaying the button text
        sf::Font font; // Font for the button text
        sf::Texture buttonTexture; // Texture for the button (if needed)
        sf::Sprite buttonIcon; // Sprite for the button icon (if needed)       
};