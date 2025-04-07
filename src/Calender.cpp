#include "../include/Calender.hpp"

// Constructor
Calender::Calender(int width, int height, int x, int y) 
    : UIState(width, height, x, y, "Calender") // Initialize the base class with the constructor
{
    // Initialize the calendar panel shape
    myDayPanel.setSize(sf::Vector2f(UIConfig::WINDOW_WIDTH, UIConfig::WINDOW_HEIGHT - 165)); // Set the size of the panel
    myDayPanel.setPosition(UIConfig::panelWidth + UIConfig::spacing * 2, 60); // Set the position of the panel
    myDayPanel.setFillColor(UIConfig::primaryColor); // Set the color of the panel

    myDayFont.loadFromFile("../assets/fonts/arial.ttf"); // Load the font for the My Day text
    myDayText.setFont(myDayFont); // Set the font of the My Day text
    myDayText.setString("Calendar"); // Set the text string
    myDayText.setCharacterSize(24); // Set the character size for the My Day text
    myDayText.setFillColor(UIConfig::textColor); // Set the text color
    myDayText.setPosition(UIConfig::panelWidth + UIConfig::spacing * 2 + 20, 70); // Set the position of the My Day text
    myDayText.setStyle(sf::Text::Bold); // Set the text style to bold
    myDayText.setOutlineThickness(1); // Set the outline thickness for the My Day text  

    std::cout << "My Day initialized." << std::endl;
}

// Destructor
Calender::~Calender() 
{
    // Clean up resources here if needed
    std::cout << "My Day destroyed." << std::endl;
}

// Render the My Day state
void Calender::render(sf::RenderWindow& window) 
{
    // Draw the calendar panel
    window.draw(myDayPanel); // Draw the calendar panel shape
    window.draw(myDayText); // Draw the calendar text    
}

// Update the My Day state
void Calender::update() 
{
    // Update the My Day state here if needed
}

// Process events related to the My Day state
void Calender::processEvents(sf::Event& event) 
{
    // Process events related to the My Day state here if needed
}
