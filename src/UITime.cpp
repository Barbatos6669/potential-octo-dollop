#include "../include/UITime.hpp"

// Constructor
UITime::UITime(int x, int y, int w, int h, sf::Color color) 
    : posX(x), posY(y), width(w), height(h), textColor(color) 
{
    // Load the font and set the text properties
    if (!font.loadFromFile("../assets/fonts/arial.ttf")) {
        std::cerr << "Error loading font." << std::endl;
    }
    dayText.setFont(font); // Set the font of the day text
    timeText.setFont(font); // Set the font of the time text
    dateText.setFont(font); // Set the font of the date text

    dayText.setCharacterSize(24); // Set the character size for day text
    timeText.setCharacterSize(24); // Set the character size for time text
    dateText.setCharacterSize(24); // Set the character size for date text

    dayText.setFillColor(textColor); // Set the color of the day text
    timeText.setFillColor(textColor); // Set the color of the time text
    dateText.setFillColor(textColor); // Set the color of the date text

    dayText.setPosition(posX, posY); // Set the position of the day text

    std::cout << "UITime initialized." << std::endl;
}

// Destructor
UITime::~UITime() 
{
    // Clean up resources here if needed
    std::cout << "UITime destroyed." << std::endl;
}

// Update the time display
void UITime::update() 
{
    // Update the elapsed time and delta time
    elapsedTime = clock.getElapsedTime(); // Get the elapsed time since the clock started
    deltaTime = clock.restart(); // Restart the clock and get the delta time

    // Get the current time, day, and date
    GetCurrentTime(); // Get the current time
    GetCurrentDay(); // Get the current day of the week
    GetCurrentDate(); // Get the current date
}

// Render the time display
void UITime::render(sf::RenderWindow& window) 
{
    
    window.draw(dayText); // Draw the day text
    window.draw(timeText); // Draw the time text
    window.draw(dateText); // Draw the date text
}

void UITime::processEvents(sf::Event& event) 
{
    // Process events related to the time display here if needed

}

// Get the current time and date
void UITime::GetCurrentTime() 
{
    // Get the current time
    std::time_t now = std::time(nullptr); // Get the current time as a time_t object
    std::tm* localTime = std::localtime(&now); // Convert to local time

    // Format the time string
    char buffer[10]; // Buffer to hold the formatted time string
    std::strftime(buffer, sizeof(buffer), "%H:%M:%S", localTime); // Format the time as HH:MM:SS
    timeString = buffer; // Store the formatted time string in the member variable

    timeText.setString(timeString); // Set the text of the time display
}


void UITime::GetCurrentDate() {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);

    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", localTime);
    dateString = buffer;
    dateText.setString(dateString);
    
}

void UITime::GetCurrentDay() {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);

    char buffer[10];
    std::strftime(buffer, sizeof(buffer), "%A", localTime);
    dayString = buffer;
    dayText.setString(dayString);

    
}



