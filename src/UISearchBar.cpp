#include "../include/UISearchBar.hpp"
#include <iostream>

// Constructor
UISearchBar::UISearchBar()
    : isActive(false), isFocused(false), isHovered(false), isClicked(false),
      isTextEntered(false), isTextDeleted(false), isTextCleared(false)
{
    searchbarShape.setSize(sf::Vector2f(300, 50)); // Default size
    searchbarShape.setFillColor(sf::Color::White); // Default color
    searchbarShape.setOutlineColor(sf::Color::Black); // Default outline color
    searchbarShape.setOutlineThickness(2.0f); // Default outline thickness

    if (!searchbarFont.loadFromFile("assets/fonts/arial.ttf")) // Load default font
    {
        std::cerr << "Error loading font for UISearchBar" << std::endl;
    }

    searchbarText.setFont(searchbarFont);
    searchbarText.setCharacterSize(20); // Default text size
    searchbarText.setFillColor(sf::Color::Black); // Default text color
    searchbarText.setString(""); // Default text
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
    return searchbarShape.getSize();
}

void UISearchBar::getPosition(sf::Vector2f& position) const
{
    position = searchbarShape.getPosition();
}

sf::Color UISearchBar::getColor() const
{
    return searchbarShape.getFillColor();
}

sf::Color UISearchBar::getOutlineColor() const
{
    return searchbarShape.getOutlineColor();
}

float UISearchBar::getOutlineThickness() const
{
    return searchbarShape.getOutlineThickness();
}

const sf::Vector2f& UISearchBar::getOrigin() const
{
    return searchbarShape.getOrigin();
}

// Setters
void UISearchBar::setSize(const sf::Vector2f& size)
{
    searchbarShape.setSize(size);
}

void UISearchBar::setPosition(const sf::Vector2f& position)
{
    searchbarShape.setPosition(position);
    searchbarText.setPosition(position.x + 10, position.y + 10); // Adjust text position
}

void UISearchBar::setColor(const sf::Color& color)
{
    searchbarShape.setFillColor(color);
}

void UISearchBar::setOutlineColor(const sf::Color& color)
{
    searchbarShape.setOutlineColor(color);
}

void UISearchBar::setOutlineThickness(float thickness)
{
    searchbarShape.setOutlineThickness(thickness);
}

void UISearchBar::setOrigin(const sf::Vector2f& origin)
{
    searchbarShape.setOrigin(origin);
}

// Additional methods
void UISearchBar::setText(const std::string& text)
{
    searchbarTextString = text;
    searchbarText.setString(searchbarTextString);
}

std::string UISearchBar::getText() const
{
    return searchbarTextString;
}

void UISearchBar::clearText()
{
    searchbarTextString.clear();
    searchbarText.setString("");
    isTextCleared = true;
}







