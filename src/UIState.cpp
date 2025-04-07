#include "../include/UIState.hpp"

// Constructor
UIState::UIState(int width, int height, int x, int y, std::string title)
    : panelWidth(width), panelHeight(height), posX(x), posY(y), titleString("UI State") // Initialize member variables
{
    // Initialize the window panel shape
    windowPanel.setSize(sf::Vector2f(panelWidth, panelHeight)); // Set the size of the panel
    windowPanel.setPosition(UIConfig::panelButtonWidth, posY); // Set the position of the panel
    windowPanel.setFillColor(UIConfig::primaryColor); // Set the color of the panel

    titleText.setFont(UIConfig::defaultFont); // Set the font of the title text
    titleText.setString(title); // Set the title string
    titleText.setCharacterSize(UIConfig::fontSize); // Set the character size for the title text
    titleText.setFillColor(UIConfig::textColor); // Set the text color
    titleText.setPosition(posX + UIConfig::spacing, posY + UIConfig::spacing); // Set the position of the title text
    titleText.setStyle(sf::Text::Bold); // Set the text style to bold

    std::cout << "UIState initialized." << std::endl;
}

// Destructor
UIState::~UIState() 
{
    // Clean up resources here if needed
    std::cout << "UIState destroyed." << std::endl;
}

// Render the UI state
void UIState::render(sf::RenderWindow& window) 
{
    // Draw the UI state elements here
    window.draw(windowPanel); // Draw the panel shape
    window.draw(titleText); // Draw the title text
}

// Update the UI state properties
void UIState::update() 
{
    // Example: Change the panel color over time or based on some condition
}

// Process events related to the UI state
void UIState::processEvents(sf::Event& event) 
{
    // Process events related to the UI state here if needed
}