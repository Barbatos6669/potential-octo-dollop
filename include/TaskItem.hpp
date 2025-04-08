#pragma once
#include <SFML/Graphics.hpp>

#include "UIConfig.hpp"

class TaskItem {
public:
    TaskItem(float width, float height, float x, float y, const std::string& taskString);

    ~TaskItem(); // Destructor

    void render(sf::RenderWindow& window);
    void setPosition(float x, float y);// Set the position of the task item

    bool isClicked(float mouseX, float mouseY) const; // Check if the item is clicked

private:
    sf::RectangleShape background;
    sf::Text taskText; // Text for the task item
    sf::Font taskFont; // Font for the task item text
    std::string taskString; // String for the task item text

};
