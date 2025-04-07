#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>

#include "iostream"

class UITime
{
    public:
        sf::Clock clock; // SFML clock to track time
        sf::Time elapsedTime; // Elapsed time since the clock started
        sf::Time deltaTime; // Time between frames

        sf::Text dayText; // Text to display the current day
        sf::Text timeText; // Text to display the current time
        sf::Text dateText; // Text to display the current date
        sf::Font font; // Font for the text

        int posX; // X position of the time display
        int posY; // Y position of the time display
        int width; // Width of the time display
        int height; // Height of the time display

        std::string dayString; // String to hold the current day
        std::string timeString; // String to hold the current time
        std::string dateString; // String to hold the current date        

        sf::Color textColor; // Color of the text

        UITime(int x = 0, int y = 0, int w = 200, int h = 50, sf::Color color = sf::Color(255, 255, 255)); // Constructor with default values
        ~UITime(); // Destructor

        void update(); // Update the time display
        void render(sf::RenderWindow& window); // Render the time display
        void processEvents(sf::Event& event); // Process events related to the time display

        void GetCurrentTime(); // Get the current time and date
        void GetCurrentDay(); // Get the current day of the week
        void GetCurrentDate(); // Get the current date
};