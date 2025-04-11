#include "../include/UIButton.hpp"
#include <iostream>

// Constructor
UIButton::UIButton()
{}

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
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (buttonShape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
        {
            std::cout << "Button clicked!" << std::endl;
        }
    }
}

// Load texture from file
bool UIButton::loadFromFile(const std::string& filename)
{
    sf::Texture texture;
    if (!texture.loadFromFile(filename))
    {
        std::cerr << "Error loading texture from file: " << filename << std::endl;
        return false;
    }
    buttonShape.setTexture(&texture);
    return true;
}

// Getters
sf::Vector2f UIButton::getSize() const
{
    return buttonShape.getSize();
}

void UIButton::getPosition(sf::Vector2f& position) const
{
    position = buttonShape.getPosition();
}

sf::Color UIButton::getColor() const
{
    return buttonShape.getFillColor();
}

sf::Color UIButton::getOutlineColor() const
{
    return buttonShape.getOutlineColor();
}

float UIButton::getOutlineThickness() const
{
    return buttonShape.getOutlineThickness();
}

const sf::Vector2f& UIButton::getOrigin() const
{
    return buttonShape.getOrigin();
}

const sf::Texture& UIButton::getTexture() const
{
    return *buttonShape.getTexture();
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
    buttonText.setString(text);
    buttonText.setFont(UIConfig::font); // Set the font for the button text
    buttonText.setCharacterSize(UIConfig::globalFontSize); // Set the character size for the button text
    buttonText.setFillColor(UIConfig::globalTextColor); // Set the text color
}