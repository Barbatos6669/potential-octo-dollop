#pragma omce
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <string>

#include "UIState.hpp"
#include "UIConfig.hpp"

class Tasks : public UIState
{
    public:
        // Constructor and Destructor
        Tasks(int width = 200, int height = 800, int x = 0, int y = 0); // Constructor with default values
        ~Tasks(); // Destructor

        void render(sf::RenderWindow& window); // Render the My Day state
        void update(); // Update the My Day state
        void processEvents(sf::Event& event); // Process events related to the My Day state

    private:

        sf::RectangleShape tasksPanel; // My Day panel shape
        sf::Color tasksColor; // Color of the My Day panel
        sf::Font tasksFont; // Font for the My Day text
        sf::Text tasksText; // Text for the My Day title     

};