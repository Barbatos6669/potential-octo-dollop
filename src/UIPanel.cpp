#include "../include/UIPanel.hpp"

#include "UIConfig.hpp"

// Constructor
UIPanel::UIPanel(int width, int height, int x, int y, sf::Color color, const std::string& backgroundImagePath) 
    : panelWidth(width), panelHeight(height), posX(x), posY(y), panelColor(color)
{
    int panelWidth = UIConfig::WINDOW_WIDTH / 3; // Set the width of the panel to one-third of the window width

    // Initialize the panel shape
    windowPanel.setSize(sf::Vector2f(panelWidth, UIConfig::WINDOW_HEIGHT)); // Set the size of the panel
    windowPanel.setPosition(posX, posY); // Set the position of the panel
    windowPanel.setFillColor(sf::Color(UIConfig::primaryColor)); // Set the color of the panel

    panelOffset.setSize(sf::Vector2f(panelWidth - UIConfig::linePadding, UIConfig::WINDOW_HEIGHT - UIConfig::linePadding)); // Set the size of the offset panel
    panelOffset.setPosition(posX + UIConfig::linePadding, posY + UIConfig::linePadding); // Set the position of the offset panel
    panelOffset.setFillColor(sf::Color(UIConfig::secondaryColor)); // Set the color of the offset panel

    // Optional background
    if (!backgroundImagePath.empty()) {
        if (backgroundTexture.loadFromFile(backgroundImagePath)) {
            backgroundSprite.setTexture(backgroundTexture);
            backgroundSprite.setPosition(posX, posY);
            backgroundSprite.setScale(
                float(panelWidth) / backgroundTexture.getSize().x,
                float(panelHeight) / backgroundTexture.getSize().y
            );
            hasBackground = true;
        } else {
            std::cerr << "Failed to load background image: " << backgroundImagePath << std::endl;
        }
    }

    std::cout << "WindowPanel initialized." << std::endl;
}

// Destructor
UIPanel::~UIPanel() 
{
    // Clean up resources here if needed
    std::cout << "WindowPanel destroyed." << std::endl;

}

// Draw the panel
void UIPanel::draw(sf::RenderWindow& window) 
{   
    // Draw other UI elements here if needed
    window.draw(windowPanel); // Draw the panel shape
    window.draw(panelOffset); // Draw the offset panel shape
    window.draw(backgroundSprite); // Draw the background sprite if it exists
    
}

// Update the panel properties
void UIPanel::update() 
{
    // Example: Change the background color over time or based on some condition
}

// Process events related to the panel
void UIPanel::processEvents(sf::Event& event) 
{
    // Process events related to the panel here if needed
    std::cout << "WindowPanel processing events." << std::endl;

    // Example: Handle mouse clicks or keyboard input    
}

