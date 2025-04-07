#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <string>

#include "UIState.hpp"
#include "UIConfig.hpp"

class MyDay : public UIState
{
    public:
        // Constructor and Destructor
        MyDay(int width = 200, int height = 800, int x = 0, int y = 0); // Constructor with default values
        ~MyDay(); // Destructor

        void render(sf::RenderWindow& window); // Render the My Day state
        void update(); // Update the My Day state
        void processEvents(sf::Event& event); // Process events related to the My Day state

    private:

        sf::RectangleShape myDayPanel; // My Day panel shape
        sf::Color myDayColor; // Color of the My Day panel
        sf::Font myDayFont; // Font for the My Day text
        sf::Text myDayText; // Text for the My Day title     

};