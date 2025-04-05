#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

class DateTimeDisplay 
{
    public:
        float displayWidth = 200.f; // Width of the display
        float displayHeight = 50.f; // Height of the display
        int displayPosX = 0; // X position of the display
        int displayPosY = 0; // Y position of the display

        string displayTextStringDate = "date"; // Text to display on the display
        string displayTextStringTime = "time"; // Text to display on the display

        // Constructor to initialize the display
        DateTimeDisplay(float width, float height, int posX, int posY, const string& textDate, const string& textTime, const sf::Color& color = sf::Color(20, 20, 20, 10));

        // Destructor
        ~DateTimeDisplay();

        // Method to draw the display on the window
        void draw(sf::RenderWindow& window);

        // Method to update the date and time display
        string updateDate(string displayTextStringDate);

        string setColor(const sf::Color& color); // Method to set the display color

    private:
        sf::Font font; // Font for the display text
        sf::Text displayTextDate; // Text object for displaying the date
        sf::Text displayTextTime; // Text object for displaying the time
        sf::RectangleShape backPanel; // Rectangle shape for the background panel
        sf::Color displayColor; // Color of the display
        sf::RectangleShape display; // Rectangle shape for the display        
};