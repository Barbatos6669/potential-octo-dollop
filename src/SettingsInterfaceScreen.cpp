#include "../include/InterfaceScreen.hpp"

// Constructor to initialize the interface screen
InterfaceScreen::InterfaceScreen(float width, float height, int posX, int posY, const string& titleText, const sf::Color& color, const string& iconPath) 
    : displayWidth(width), displayHeight(height), displayPosX(posX), displayPosY(posY), title(titleText), iconPath(iconPath) 
{
    

}

// Destructor for the interface screen (defaulted in the header file)


// Method to handle events for the interface screen
void InterfaceScreen::handleEvent(const sf::Event& event, int posX, int posY) 
{
    // Handle events for the interface screen (to be implemented in derived classes)
}

// Method to update the interface screen
void InterfaceScreen::update(sf::RenderWindow& window) 
{
    // Update the interface screen (to be implemented in derived classes)
}

// Method to render the interface screen
void InterfaceScreen::render(sf::RenderWindow& window) 
{
    // Draw the display panel and title text on the window
    window.draw(displayPanel);
    window.draw(titleText);
    // Draw other elements of the interface screen (to be implemented in derived classes)
}