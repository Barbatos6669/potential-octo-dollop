#include "../include/Tasks.hpp"

// Constructor
Tasks::Tasks(int width, int height, int x, int y) 
    : UIState(width, height, x, y, "Tasks") // Initialize the base class with the constructor
{
    // Initialize the My Day panel shape
    tasksPanel.setSize(sf::Vector2f(UIConfig::WINDOW_WIDTH, UIConfig::WINDOW_HEIGHT - 165)); // Set the size of the panel
    tasksPanel.setPosition(UIConfig::panelWidth + UIConfig::spacing * 2, 60); // Set the position of the panel
    tasksPanel.setFillColor(UIConfig::primaryColor); // Set the color of the panel

    tasksFont.loadFromFile("../assets/fonts/arial.ttf"); // Load the font for the My Day text
    tasksText.setFont(tasksFont); // Set the font of the My Day text
    tasksText.setString("Tasks"); // Set the text string
    tasksText.setCharacterSize(24); // Set the character size for the My Day text
    tasksText.setFillColor(UIConfig::textColor); // Set the text color
    tasksText.setPosition(UIConfig::panelWidth + UIConfig::spacing * 2 + 20, 70); // Set the position of the My Day text
    tasksText.setStyle(sf::Text::Bold); // Set the text style to bold
    tasksText.setOutlineThickness(1); // Set the outline thickness for the My Day text  

    std::cout << "Tasks initialized." << std::endl;
}

// Destructor
Tasks::~Tasks() 
{
    // Clean up resources here if needed
    std::cout << "Tasks destroyed." << std::endl;
}

// Render the Tasks state
void Tasks::render(sf::RenderWindow& window) 
{
    // Draw the tasks panel
    window.draw(tasksPanel); // Draw the tasks panel shape
    window.draw(tasksText); // Draw the tasks text    
}

// Update the Tasks state
void Tasks::update() 
{
    // Update the Tasks state here if needed
}

