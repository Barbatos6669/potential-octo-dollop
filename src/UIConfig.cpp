#include "../include/UIConfig.hpp"

// declaration
bool UIConfig::init() 
{
    // Load the font from the specified path
    if (!font.loadFromFile(globalFontPath)) {
        std::cerr << "Error loading font from file: " << globalFontPath << std::endl;
        return false;
    }
    return true;
}

