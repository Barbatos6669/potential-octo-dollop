#include "../include/DateTimeDisplay.hpp"

// Constructor to initialize the display
DateTimeDisplay::DateTimeDisplay(float width, float height, int posX, int posY, const string& textDate, const string& textTime, const sf::Color& color) 
    : displayColor(color), display(sf::Vector2f(width, height)) // Initialize the rectangle shape with the specified width and height
{
    displayWidth = width;
    displayHeight = height;
    displayPosX = posX;
    displayPosY = posY;
    displayTextStringDate = textDate;
    displayTextStringTime = textTime;

    // Load font
    if (!font.loadFromFile("../assets/fonts/arial.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }
    // Set up the background panel
    backPanel.setSize(sf::Vector2f(displayWidth, displayHeight)); // Set the size of the background panel
    backPanel.setFillColor(sf::Color(20, 20, 20, 180)); // Set the background color of the panel
    backPanel.setPosition(displayPosX, displayPosY); // Set the position of the panel

    // Set up the date text
    displayTextDate.setFont(font);
    displayTextDate.setString(displayTextStringDate);
    displayTextDate.setCharacterSize(24); // Set the character size
    displayTextDate.setFillColor(sf::Color::White); // Set the text color
    displayTextDate.setPosition(displayPosX + 5, displayPosY + 5); // Set the position of the text
    displayTextDate.setStyle(sf::Text::Bold); // Set the text style to bold

    // Set up the time text
    displayTextTime.setFont(font);
    displayTextTime.setString(displayTextStringTime);
    displayTextTime.setCharacterSize(24); // Set the character size
    displayTextTime.setFillColor(sf::Color::White); // Set the text color
    displayTextTime.setPosition(displayPosX + 20, displayPosY + 35); // Set the position of the text

    // Set up the rectangle shape for the display
    display.setSize(sf::Vector2f(displayWidth, displayHeight));
    display.setFillColor(sf::Color(20, 20, 20, 10)); // Set the background color of the rectangle
}

// Destructor
DateTimeDisplay::~DateTimeDisplay() 
{
    // Destructor implementation (if needed)
}

// Method to draw the display on the window
void DateTimeDisplay::draw(sf::RenderWindow& window) 
{
    // Draw the rectangle and text on the window
    window.draw(display);
    window.draw(backPanel); // Draw the background panel
    window.draw(displayTextDate);
    window.draw(displayTextTime);
}

string DateTimeDisplay::updateDate(string displayTextStringDate) 
{
    // Get the current date and time
    time_t now = time(0);
    tm* localtm = localtime(&now);

    // Format the date and time strings
    char dateBuffer[80];
    strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d", localtm);
    displayTextStringDate = string(dateBuffer);

    char timeBuffer[80];
    strftime(timeBuffer, sizeof(timeBuffer), "%H:%M:%S", localtm);
    displayTextStringTime = string(timeBuffer);

    // Update the text objects with the new date and time
    displayTextDate.setString(displayTextStringDate);
    displayTextTime.setString(displayTextStringTime);

    return displayTextStringDate;
}

string DateTimeDisplay::setColor(const sf::Color& color) 
{
    display.setFillColor(color); // Set the background color of the rectangle
    return "Color set successfully";
}