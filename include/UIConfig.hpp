#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
#include <string>

class UIConfig 
{
public:
    static bool init(); // Declaration only 
    inline static sf::Font font; // Static member

    // Base dimensions (design resolution)
    inline static int baseWidth = 1280; // Base width for scaling
    inline static int baseHeight = 800; // Base height for scaling

    // Global scaling factor for the UI
    inline static float globalScale = 1.0f; // Default scaling factor

    // Global padding (used for margins and button calculations)
    inline static int globalLinePadding = 2; // Default line padding

    // Panel dimensions and spacing
    inline static int panelWidth = baseWidth / 3 - globalLinePadding * 2; // Set the width of the panel to one-third of the base width
    inline static int panelHeight = baseHeight - globalLinePadding * 2; // Set the height of the panel to the base height
    inline static int panelButtonWidth = panelWidth - 10; // Width of the panel button
    inline static int panelButtonHeight = 50; // Height of the panel button
    inline static int spacing = 5; // Spacing between elements in the panel

    // Global font and icon configuration
    inline static int globalFontSize = 24; // Default font size
    inline static std::string globalFontPath = "assets/fonts/arial.ttf"; // Default font path
    inline static int globalIconSize = 50; // Default icon size

    // Global button dimensions
    inline static int globalButtonWidth = panelWidth - globalLinePadding * 2; // Default global button width
    inline static int globalButtonHeight = 50; // Default global button height

    // Global color scheme for the UI (using SFML's sf::Color)
    inline static sf::Color globalPrimaryColor = sf::Color(20, 20, 20, 255); // Default primary color
    inline static sf::Color globalSecondaryColor = sf::Color(50, 50, 50, 100); // Default secondary color
    inline static sf::Color globalAccentColor = sf::Color(150, 150, 150, 255); // Default accent color
    inline static sf::Color globalBackgroundColor = sf::Color(0, 0, 0); // Default background color
    inline static sf::Color globalTextColor = sf::Color(255, 255, 255); // Default text color

    // Anchor points for UI elements
    inline static sf::Vector2f anchorTopLeft = sf::Vector2f(0.0f + globalLinePadding, 0.0f + globalLinePadding); // Top-left anchor point
    inline static sf::Vector2f anchorMiddleLeft = sf::Vector2f(0.0f, baseHeight / 2.0f); // Middle-left anchor point
    inline static sf::Vector2f anchorBottomLeft = sf::Vector2f(0.0f, static_cast<float>(baseHeight)); // Bottom-left anchor point
    inline static sf::Vector2f anchorTopMiddle = sf::Vector2f(baseWidth / 2.0f, 0.0f); // Top-middle anchor point
    inline static sf::Vector2f anchorMiddleMiddle = sf::Vector2f(baseWidth / 2.0f, baseHeight / 2.0f); // Middle-middle anchor point
    inline static sf::Vector2f anchorBottomMiddle = sf::Vector2f(baseWidth / 2.0f, static_cast<float>(baseHeight)); // Bottom-middle anchor point
    inline static sf::Vector2f anchorTopRight = sf::Vector2f(static_cast<float>(baseWidth), 0.0f); // Top-right anchor point
    inline static sf::Vector2f anchorMiddleRight = sf::Vector2f(static_cast<float>(baseWidth), baseHeight / 3.0f); // Middle-right anchor point
    inline static sf::Vector2f anchorBottomRight = sf::Vector2f(static_cast<float>(baseWidth), static_cast<float>(baseHeight)); // Bottom-right anchor point
};
