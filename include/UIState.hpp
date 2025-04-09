/********************************************************************************************/
/*  UIState.hpp                                                                             */
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

class UIState
{
    public:
        sf::RectangleShape windowPanel; // Left panel shape
        sf::Text titleText; // Title text
        sf::Font titleFont; // Title font

        std::string titleString; // Title string

        int panelWidth; // Width of the panel
        int panelHeight; // Height of the panel
        int posX; // X position of the panel
        int posY; // Y position of the panel

        // Constructor and Destructor
        /// @brief Default constructor for the UIState class.
        /// @param width Width of the UI state window
        /// @param height Height of the UI state window
        /// @param x X position of the UI state window
        /// @param y Y position of the UI state window
        /// @param title Title of the UI state window
        /// @details Initializes the UI state with the specified dimensions and position.
        UIState(int width = 200, int height = 800, int x = 0, int y = 0, std::string title = "UI State"); // Constructor with default values

        
        ~UIState(); // Destructor

        /// @brief Render the UI state.
        /// @param window Reference to the SFML render window where the UI state will be drawn.
        void render(sf::RenderWindow& window); // Render the UI state

        /// @brief Update the UI state.
        void update(); // Update the UI state

        /// @brief Process events related to the UI state.
        /// @param event Reference to the SFML event to be processed.
        /// @details This function handles events such as mouse clicks and keyboard input.
        void processEvents(sf::Event& event); // Process events related to the UI state
};