#include "../include/PanelButton.hpp"

// Constructor to initialize the button
PanelButton::PanelButton(float width, float height, int posX, int posY, const string& text, const string& iconPath, const sf::Color& color) 
    : buttonWidth(width), buttonHeight(height), buttonPosX(posX), buttonPosY(posY), buttonTextString(text), iconPath(iconPath), buttonColor(sf::Color(20, 20, 20, 10))
{
    // Set up the button background
    button.setSize(sf::Vector2f(width, height)); // Set size to 1/10th of the window height
    button.setFillColor(sf::Color(20, 20, 20)); // Dark gray color
    button.setPosition(posX, posY); // Position at the top of the window

    // Set up the button text
    font.loadFromFile("../assets/fonts/arial.ttf"); // Load font from file
    buttonText.setFont(font); // Set the font for the text
    buttonText.setCharacterSize(20); // Set character size
    buttonText.setFillColor(sf::Color::White); // Set text color to white
    buttonText.setPosition(posX + 40, posY + 6); // Position the text inside the button
    buttonText.setString(text); // Set default text

    // set up the button icon if needed
    buttonTexture.loadFromFile(iconPath); // Load button icon texture
    buttonIcon.setTexture(buttonTexture); // Set the texture for the button icon
    buttonIcon.setScale(1, 1); // Scale the icon to fit the button
    buttonIcon.setPosition(posX + 10, posY + 10); // Position the button icon inside the button    
}

// Destructor
PanelButton::~PanelButton() 
{
    // Cleanup if necessary
}

// Method to draw the button on the window
void PanelButton::draw(sf::RenderWindow& window) 
{
    // Draw the button background and text
    window.draw(button);
    window.draw(buttonText); // Draw the button text
    window.draw(buttonIcon); // Draw the button icon
}

// Method to handle input events for the button
void PanelButton::processEvent(sf::Event event, int posX, int posY) 
{
    // Check if the mouse is over the button
    if (event.type == sf::Event::MouseMoved) 
    {
        if (button.getGlobalBounds().contains(posX, posY)) 
        {
            // Change button color on hover
            button.setFillColor(sf::Color(100, 100, 100)); // Change to a lighter gray color
        } 
        else 
        {
            // Reset button color when not hovered
            button.setFillColor(sf::Color(20, 20, 20, 220)); // Dark gray color
        }
    }


    // Check if the button is clicked
    if (event.type == sf::Event::MouseButtonPressed) 
    {
        if (event.mouseButton.button == sf::Mouse::Left && button.getGlobalBounds().contains(posX, posY)) 
        {
            // Button clicked, perform action here
            cout << "Button clicked: " << buttonTextString << endl; // Print button click for debugging
            // Perform the desired action here
        }
    }
}

// Method to set the button color
void PanelButton::setButtonColor(const sf::Color& color) 
{
    button.setFillColor(color); // Set the button color
}