#include "../include/TaskItem.hpp"

TaskItem::TaskItem(float width, float height, float x, float y, const std::string& taskString) 
    : taskString(taskString) 
{
    UIConfig::defaultFont.loadFromFile("../assets/fonts/arial.ttf");
    background.setSize(sf::Vector2f(width, height)); // Set the size of the background rectangle
    background.setPosition(x, y); // Set the position of the background rectangle
    background.setFillColor(UIConfig::primaryColor); // Set the fill color of the background rectangle

    taskText.setFont(UIConfig::defaultFont);
    taskText.setString(taskString); // Set the string for the text
    taskText.setCharacterSize(UIConfig::fontSize); // Set the character size for the text
    taskText.setFillColor(UIConfig::textColor); // Set the fill color for the text
    taskText.setPosition(x + 10, y + 10); // Set the position of the text within the rectangle
}

TaskItem::~TaskItem() 
{
    // Destructor implementation (if needed)
}


void TaskItem::render(sf::RenderWindow& window) 
{
    window.draw(background);
    window.draw(taskText); // Draw the task item text
}

void TaskItem::setPosition(float x, float y) {
    background.setPosition(x, y);
    taskText.setPosition(x + 10, y + 10);
}

bool TaskItem::isClicked(float mouseX, float mouseY) const 
{
    return background.getGlobalBounds().contains(mouseX, mouseY); // Check if the mouse coordinates are within the bounds of the task item
}
