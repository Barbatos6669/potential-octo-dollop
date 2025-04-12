#include "../include/UIButton.hpp"
#include <iostream>

// Constructor
UIButton::UIButton()
{
    if (!buttonFont.loadFromFile(UIConfig::globalFontPath)) // Load the font
    {
        std::cerr << "Error loading font" << std::endl;
    }
    else
    {
        std::cout << "Font loaded successfully" << std::endl;
    }
}

// Destructor
UIButton::~UIButton()
{
    // Destructor logic (if needed)
}

// Render the button
void UIButton::render(sf::RenderWindow& window)
{
    window.draw(buttonShape); // Draw the button shape
    window.draw(buttonText);  // Draw the text inside the button
}

// Update the button (if needed)
void UIButton::update()
{
    // Update logic for the button (if needed)
}

// Handle events for the button
void UIButton::handleEvents(const sf::Event& event)
{
    // Handle mouse button pressed event
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (buttonShape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
        {
            std::cout << "Button clicked!" << std::endl; // Handle button click event
        }
    }
}

// Load texture from file
bool UIButton::loadFromFile(const std::string& filename)
{
    // Load the texture from the specified file
    sf::Texture texture;
    if (!texture.loadFromFile(filename))
    {
        std::cerr << "Error loading texture from file: " << filename << std::endl;
        return false;
    }
    buttonShape.setTexture(&texture); // Set the texture for the button shape
    return true;
}

// Getters
sf::Vector2f UIButton::getSize() const
{
    return buttonShape.getSize(); // Return the size of the button shape
}

void UIButton::getPosition(sf::Vector2f& position) const
{
    position = buttonShape.getPosition(); // Get the position of the button shape
}

sf::Color UIButton::getColor() const
{
    return buttonShape.getFillColor(); // Return the fill color of the button shape
}

sf::Color UIButton::getOutlineColor() const
{
    return buttonShape.getOutlineColor(); // Return the outline color of the button shape
}

float UIButton::getOutlineThickness() const
{
    return buttonShape.getOutlineThickness(); // Return the outline thickness of the button shape
} 

const sf::Vector2f& UIButton::getOrigin() const
{
    return buttonShape.getOrigin(); // Return the origin of the button shape
}

const sf::Texture& UIButton::getTexture() const
{
    return *buttonShape.getTexture(); // Return the texture of the button shape
}

const sf::Text& UIButton::getText() const
{
    return buttonText; // Return the text in the button
}

// Setters
void UIButton::setSize(const sf::Vector2f& size)
{
    buttonShape.setSize(size);
}

void UIButton::setPosition(const sf::Vector2f& position)
{
    buttonShape.setPosition(position);
    buttonText.setPosition(position.x + 10, position.y + 10); // Adjust text position
}

void UIButton::setColor(const sf::Color& color)
{
    buttonShape.setFillColor(color);
}

void UIButton::setOutlineColor(const sf::Color& color)
{
    buttonShape.setOutlineColor(color);
}

void UIButton::setOutlineThickness(float thickness)
{
    buttonShape.setOutlineThickness(thickness);
}

void UIButton::setOrigin(const sf::Vector2f& origin)
{
    buttonShape.setOrigin(origin);
}

void UIButton::setTexture(const sf::Texture& texture, bool resetRect)
{
    buttonShape.setTexture(&texture, resetRect);
}

void UIButton::setText(const std::string& text)
{
    buttonFont.loadFromFile(UIConfig::globalFontPath); // Load the font
    buttonText.setFont(buttonFont); // Set the font for the button text
    buttonText.setString(text); // Set the text for the button
    buttonText.setCharacterSize(UIConfig::globalFontSize); // Set the character size for the button text
    buttonText.setFillColor(UIConfig::globalTextColor); // Set the text color
}