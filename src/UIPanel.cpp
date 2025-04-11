#include "../include/UIPanel.hpp"
#include <iostream>

// Constructor
UIPanel::UIPanel(const sf::Vector2f& size, const sf::Color& color)
    : panelShape(size) // Initialize the panel shape with the given size
{
    panelShape.setFillColor(color); // Set the initial color of the panel
}

// Destructor
UIPanel::~UIPanel() {}

// Render the panel
void UIPanel::render(sf::RenderWindow& window)
{
    window.draw(panelShape); // Draw the panel shape on the window
}

// Update the panel (if needed)
void UIPanel::update()
{
    // Update logic for the panel (if needed)
}

// Handle events (if needed)
void UIPanel::handleEvents(const sf::Event& event)
{
    // Event handling logic for the panel (if needed)
}

// Load texture from file
bool UIPanel::loadFromFile(const std::string& filename)
{
    if (!panelTexture.loadFromFile(filename)) // Load the texture from the file
    {
        std::cerr << "Error loading texture from file: " << filename << std::endl;
        return false; // Return false if loading fails
    }
    panelShape.setTexture(&panelTexture); // Set the loaded texture to the panel shape
    return true; // Return true if loading is successful
}

// Getters
sf::Vector2f UIPanel::getSize() const
{
    return panelShape.getSize(); // Return the size of the panel shape
}

void UIPanel::getPosition(sf::Vector2f& position) const
{
    position = panelShape.getPosition(); // Get the position of the panel shape
}

sf::Color UIPanel::getColor() const
{
    return panelShape.getFillColor(); // Return the fill color of the panel shape
}

sf::Color UIPanel::getOutlineColor() const
{
    return panelShape.getOutlineColor(); // Return the outline color of the panel shape
}

float UIPanel::getOutlineThickness() const
{
    return panelShape.getOutlineThickness(); // Return the outline thickness of the panel shape
}

const sf::Vector2f& UIPanel::getOrigin() const
{
    return panelShape.getOrigin(); // Return the origin of the panel shape
}

const sf::Texture& UIPanel::getTexture() const
{
    return *panelShape.getTexture(); // Return the texture of the panel shape
}

// Setters
void UIPanel::setSize(const sf::Vector2f& size)
{
    panelShape.setSize(size); // Set the size of the panel shape
}

void UIPanel::setPosition(const sf::Vector2f& position)
{
    panelShape.setPosition(position); // Set the position of the panel shape
}

void UIPanel::setColor(const sf::Color& color)
{
    panelShape.setFillColor(color); // Set the fill color of the panel shape
}

void UIPanel::setOutlineColor(const sf::Color& color)
{
    panelShape.setOutlineColor(color); // Set the outline color of the panel shape
}

void UIPanel::setOutlineThickness(float thickness)
{
    panelShape.setOutlineThickness(thickness); // Set the outline thickness of the panel shape
}

void UIPanel::setOrigin(const sf::Vector2f& origin)
{
    panelShape.setOrigin(origin); // Set the origin of the panel shape
}

void UIPanel::setTexture(const sf::Texture& texture, bool resetRect)
{
    panelShape.setTexture(&texture, resetRect); // Set the texture of the panel shape
}