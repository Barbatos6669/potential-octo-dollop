/********************************************************************************************/
/*  UIButton.cpp                                                                            */
/********************************************************************************************/
/*                               This file is part of:                                      */
/*                                     To Do List                                           */       
/*                                                                                          */
/********************************************************************************************/
/*                                                                                          */
/*  This program is free software: you can redistribute it and/or modify                    */
/*  it under the terms of the GNU General Public License as published by                    */
/*  the Free Software Foundation, either version 3 of the License, or                       */
/*  (at your option) any later version.                                                     */
/*                                                                                          */
/*                                                                                          */
/*  This program is distributed in the hope that it will be useful,                         */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of                          */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                           */
/*  GNU General Public License for more details.                                            */
/*                                                                                          */
/*  You should have received a copy of the GNU General Public License                       */
/*  along with this program.  If not, see <http://www.gnu.org/licenses/>.                   */
/*                                                                                          */
/********************************************************************************************/
#include "../include/UIButton.hpp"

#include "UIConfig.hpp"

// Constructor
UIButton::UIButton(int width, int height, int x, int y, sf::Color color, std::string text, std::string tex) 
    : buttonWidth(width), buttonHeight(height), posX(x), posY(y), buttonColor(color), buttonTextString(text), buttonIconPath(tex)
{
    // Initialize the button shape
    buttonShape.setSize(sf::Vector2f(buttonWidth, buttonHeight)); // Set the size of the button
    buttonShape.setPosition(posX + UIConfig::linePadding, posY + UIConfig::linePadding); // Set the position of the button
    buttonShape.setFillColor(UIConfig::accentColor); // Set the color of the button

    // Load the font and set the text properties
    if (!buttonFont.loadFromFile("../assets/fonts/arial.ttf")) {
        std::cerr << "Error loading font." << std::endl;
    }
    buttonText.setFont(buttonFont); // Set the font of the text
    buttonText.setString(buttonTextString); // Set the text string
    buttonText.setCharacterSize(24); // Set the character size
    buttonText.setFillColor(sf::Color::White); // Set the text color
    buttonText.setPosition(50, 15); // Set the position of the text

    // Load the icon texture if provided
    if (!buttonIcon.loadFromFile(buttonIconPath)) {
        std::cerr << "Error loading icon texture." << std::endl;
    }
    buttonIconSprite.setTexture(buttonIcon); // Set the texture of the icon sprite
    buttonIconSprite.setPosition(posX + 20, posY + 20); // Set the position of the icon sprite

    std::cout << "Button initialized." << std::endl;
}

// Destructor
UIButton::~UIButton() 
{
    // Clean up resources here if needed
    std::cout << "Button destroyed." << std::endl;
}

// Render the button
void UIButton::render(sf::RenderWindow& window) 
{
    // Draw the button shape and text
    window.draw(buttonShape); // Draw the button shape
    window.draw(buttonText); // Draw the button text
    window.draw(buttonIconSprite); // Draw the button icon sprite if needed    
}

// Update the button properties
void UIButton::update() 
{
    // Example: Change the button color over time or based on some condition
}

// Process events related to the button
void UIButton::processEvents(sf::Event& event) 
{
    if (event.type == sf::Event::MouseMoved) 
    {
        // Check if the mouse is hovering over the button
        if (buttonShape.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) 
        {
            buttonShape.setFillColor(sf::Color(UIConfig::accentColor)); // Change color on hover.
            buttonText.setFillColor(sf::Color::Black); // Change text color on hover.
        } 
        else
        {
            buttonShape.setFillColor(UIConfig::primaryColor); // Reset color when not hovering
            buttonText.setFillColor(sf::Color::White); // Reset text color when not hovering
        }
    }
}