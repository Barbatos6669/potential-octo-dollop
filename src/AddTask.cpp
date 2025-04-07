#include "../include/AddTask.hpp"

// Constructor
AddTask::AddTask(int width, int height, int x, int y) 
    : UIState(width, height, x, y, "Add Task") // Initialize the base class with the constructor
{
    // Initialize the My Day panel shape
    myDayPanel.setSize(sf::Vector2f(UIConfig::WINDOW_WIDTH, UIConfig::WINDOW_HEIGHT - 165)); // Set the size of the panel
    myDayPanel.setPosition(UIConfig::panelWidth + UIConfig::spacing * 2, 60); // Set the position of the panel
    myDayPanel.setFillColor(UIConfig::primaryColor); // Set the color of the panel

    myDayFont.loadFromFile("../assets/fonts/arial.ttf"); // Load the font for the My Day text
    myDayText.setFont(myDayFont); // Set the font of the My Day text
    myDayText.setString("Add Task"); // Set the text string
    myDayText.setCharacterSize(24); // Set the character size for the My Day text
    myDayText.setFillColor(UIConfig::textColor); // Set the text color
    myDayText.setPosition(UIConfig::panelWidth + UIConfig::spacing * 2 + 20, 70); // Set the position of the My Day text
    myDayText.setStyle(sf::Text::Bold); // Set the text style to bold

    std::cout << "AddTask initialized." << std::endl;
}

// Destructor
AddTask::~AddTask() 
{
    // Clean up resources here if needed
    std::cout << "AddTask destroyed." << std::endl;
}

// Render the Add Task state
void AddTask::render(sf::RenderWindow& window) 
{
    // Draw the Add Task panel
    window.draw(myDayPanel); // Draw the Add Task panel shape
    window.draw(myDayText); // Draw the Add Task text    
}

// Update the Add Task state
void AddTask::update() 
{
    // Update the Add Task state here if needed
}

// Process events related to the Add Task state
void AddTask::processEvents(sf::Event& event) 
{
    // Process events related to the Add Task state here if needed
}