#include "../include/UISearchBar.hpp"
#include <iostream>

// Constructor
UISearchBar::UISearchBar()
    : isActive(false), isFocused(false), isHovered(false), isClicked(false),
      isTextEntered(false), isTextDeleted(false), isTextCleared(false)
{
    if (!searchbarFont.loadFromFile(UIConfig::globalFontPath)) // Load font from file
    {
        std::cerr << "Error loading font for search bar" << std::endl;
    }
    else 
    {
        std::cout << "Font loaded successfully for search bar" << std::endl;
    }
}

// Destructor
UISearchBar::~UISearchBar() {}

// Render the search bar
void UISearchBar::render(sf::RenderWindow& window)
{
    window.draw(searchbarShape); // Draw the search bar shape
    window.draw(searchbarText); // Draw the text inside the search bar
}

// Update the search bar (if needed)
void UISearchBar::update()
{
    // Update logic for the search bar (if needed)
}

// Handle events for the search bar
void UISearchBar::handleEvents(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (searchbarShape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
        {
            isFocused = true; // Focus the search bar if clicked
            std::cout << "Search bar clicked" << std::endl;
        }
        else
        {
            isFocused = false; // Unfocus if clicked outside
        }
    }
}

// Getters
sf::Vector2f UISearchBar::getSize() const
{
    return searchbarShape.getSize(); // Return the size of the search bar shape
}

void UISearchBar::getPosition(sf::Vector2f& position) const
{
    position = searchbarShape.getPosition(); // Get the position of the search bar shape
}

sf::Color UISearchBar::getColor() const
{
    return searchbarShape.getFillColor(); // Return the fill color of the search bar shape
}

sf::Color UISearchBar::getOutlineColor() const
{
    return searchbarShape.getOutlineColor(); // Return the outline color of the search bar shape
}

float UISearchBar::getOutlineThickness() const
{
    return searchbarShape.getOutlineThickness(); // Return the outline thickness of the search bar shape
}

const sf::Vector2f& UISearchBar::getOrigin() const
{
    return searchbarShape.getOrigin(); // Return the origin of the search bar shape
}

// Setters
void UISearchBar::setSize(const sf::Vector2f& size)
{
    searchbarShape.setSize(size); // Set the size of the search bar shape
}

void UISearchBar::setPosition(const sf::Vector2f& position)
{
    searchbarShape.setPosition(position); // Set the position of the search bar shape
    searchbarText.setPosition(position.x + 10, position.y + 10); // Adjust text position
}

void UISearchBar::setColor(const sf::Color& color)
{
    searchbarShape.setFillColor(color); // Set the fill color for the search bar shape
}

void UISearchBar::setOutlineColor(const sf::Color& color)
{
    searchbarShape.setOutlineColor(color); // Set the outline color for the search bar shape
}

void UISearchBar::setOutlineThickness(float thickness)
{
    searchbarShape.setOutlineThickness(thickness); // Set the outline thickness for the search bar shape
}

void UISearchBar::setOrigin(const sf::Vector2f& origin)
{
    searchbarShape.setOrigin(origin); // Set the origin for the search bar shape
}

// Additional methods
void UISearchBar::setText(const std::string& text)
{
    searchbarFont.loadFromFile(UIConfig::globalFontPath); // Load font from file
    searchbarText.setFont(searchbarFont); // Set the font for the text
    searchbarText.setString(text); // Set the text string
}

std::string UISearchBar::getText() const
{
    return searchbarTextString; // Return the text string
}

void UISearchBar::clearText()
{
    searchbarTextString.clear(); // Clear the text string
    searchbarText.setString(""); // Clear the text displayed in the search bar
    isTextCleared = true; // Set the flag to indicate text cleared
}







