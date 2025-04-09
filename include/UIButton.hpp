/********************************************************************************************/
/*  UIButton.hpp                                                                            */
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
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "UIConfig.hpp"

/// @brief Class representing a button in the UI.
/// This class handles the button's appearance, text, icon, and events.
/// It uses SFML for rendering and event handling.
/// @details The UIButton class allows you to create a button with customizable properties such as size, position, color, text, and icon.
/// It also provides methods to render the button, update its state, and process events such as mouse clicks and hover effects.
/// @note The button can change its appearance when hovered or clicked, providing visual feedback to the user.
/// @note The button's text and icon can be set during construction or modified later.
class UIButton
{
    public:
        sf::RectangleShape buttonShape; // Button shape
        sf::Text buttonText; // Button text
        sf::Font buttonFont; // Button font
        sf::Color buttonColor; // Button color
        sf::Color hoverColor; // Hover color
        sf::Color clickColor; // Click color
        sf::Color textColor; // Text color
        sf::Color textHoverColor; // Text hover color
        sf::Color textClickColor; // Text click color
        sf::Mouse::Button mouseButton; // Mouse button for events

        // Icons
        sf::Texture buttonIcon; // Button icon texture
        sf::Sprite buttonIconSprite; // Button icon sprite

        int buttonWidth; // Width of the button
        int buttonHeight; // Height of the button
        int posX; // X position of the button
        int posY; // Y position of the button

        std::string buttonTextString; // Text string of the button
        std::string buttonIconPath; // Path to the button icon 
        
        /// @brief Constructor for UIButton class.
        /// @details Initializes the button with the specified properties.
        /// @param width 
        /// @param height 
        /// @param x 
        /// @param y 
        /// @param color 
        /// @param text 
        /// @param tex 
        UIButton(int width = 100, int height = 50, int x = 0, int y = 0, sf::Color color = sf::Color(50, 50, 50), std::string text = "Button", std::string tex = ""); // Constructor with default values

        /// @brief Destructor for UIButton class.
        /// @details Cleans up resources used by the button.
        /// @note The destructor is responsible for releasing any resources allocated during the lifetime of the button.
        ~UIButton(); 

        /// @brief  Render the button to the window.
        /// @details This function renders the button to the provided window.
        /// @param window The window to render the button on.
        void render(sf::RenderWindow& window);

        /// @brief  Set the button's text.
        /// @details This function sets the text of the button and updates its position accordingly.
        /// @param text The text to be set on the button.
        /// @note The text is displayed on the button and can be changed at any time.
        void update(); // Update the button properties

        /// @brief  Set the button's text.
        /// @details This function sets the text of the button and updates its position accordingly.
        /// @param text The text to be set on the button.
        /// @note The text is displayed on the button and can be changed at any time.
        void processEvents(sf::Event& event); 

};