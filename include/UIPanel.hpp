/********************************************************************************************/
/*  UIPanel.hpp                                                                             */
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

#include "iostream"
#include "UIConfig.hpp"

class UIPanel
{
    public:
        sf::RectangleShape windowPanel; // Left panel shape
        sf::RectangleShape panelOffset; // Offset panel shape

        sf::Color panelColor; // Color of the panel

        int panelWidth; // Width of the panel
        int panelHeight; // Height of the panel
        int posX; // X position of the panel
        int posY; // Y position of the panel     

        // Option to add a background image
        sf::Texture backgroundTexture; // Background texture
        sf::Sprite backgroundSprite; // Background sprite
        bool hasBackground; // Flag to indicate if the panel has a background image

        // Constructor and Destructor
        /// \brief Default constructor
        /// \details Initializes the UIPanel with default values for width, height, position, and color.
        /// \param width Width of the panel (default is UIConfig::panelWidth)
        /// \param height Height of the panel (default is UIConfig::panelHeight)
        /// \param x X position of the panel (default is 0)
        /// \param y Y position of the panel (default is 0)
        /// \param color Color of the panel (default is sf::Color(50, 50, 50))
        /// \param backgroundImagePath Path to the background image (default is an empty string)
        /// \note The constructor sets the size and position of the panel, as well as the color and background image if provided.
        /// \note The background image is loaded from the specified path if provided, otherwise it is not used.
        UIPanel(int width = UIConfig::panelWidth, int height = UIConfig::panelHeight, int x = 0, int y = 0, sf::Color color = sf::Color(50, 50, 50), const std::string& backgroundImagePath = ""); // Constructor with default values

        /// \brief Destructor
        /// \details Cleans up the UIPanel object and releases any resources used.
        /// \note The destructor is responsible for releasing any resources allocated by the UIPanel object.
        /// \note In this case, it does not have any specific cleanup code, but it is good practice to define a destructor for classes that manage resources.
        ~UIPanel();

        /// @brief  Set the position of the panel
        /// @param window 
        void draw(sf::RenderWindow& window); 

        /// \brief Set the position of the panel
        void update(); 

        /// \brief Set the position of the panel
        void processEvents(sf::Event& event);
};