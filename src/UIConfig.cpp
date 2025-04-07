#include "../include/UIConfig.hpp"
#include <iostream>

bool UIConfig::init() 
{
    // Load the default font
    if (!defaultFont.loadFromFile("../assets/fonts/arial.ttf")) {
        std::cerr << "Error loading font." << std::endl;
        return false; // Return false if font loading fails
    }
    
    defaultText.setFont(defaultFont); // Set the default font for the text
    defaultText.setCharacterSize(fontSize); // Set the character size for the text
    defaultText.setFillColor(textColor); // Set the text color

    return true; // Return true if initialization is successful
}