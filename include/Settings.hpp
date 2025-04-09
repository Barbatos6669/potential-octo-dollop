/********************************************************************************************/
/*  settings.hpp                                                                            */
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

#include <iostream>
#include <string>

#include "UIState.hpp"
#include "UIConfig.hpp"

class Settings : public UIState
{
    public:
        // Constructor and Destructor
        /// @brief Constructor for the Settings class.
        /// @param width Width of the settings panel (default: 200)
        /// @param height Height of the settings panel (default: 800)
        /// @param x X position of the settings panel (default: 0)
        /// @param y Y position of the settings panel (default: 0)
        /// @details Initializes the settings panel and title text with the specified dimensions and position.
        Settings(int width = 200, int height = 800, int x = 0, int y = 0); // Constructor with default values

        /// @brief Destructor for the Settings class.
        /// @details Cleans up resources used by the settings panel.
        /// @details The destructor is virtual to ensure proper cleanup of derived classes.
        /// @note The destructor is responsible for releasing any dynamically allocated resources.
        ~Settings(); // Destructor

        /// @brief Render the settings state.
        /// @param window Reference to the SFML render window where the settings panel will be drawn.
        /// @details This method is responsible for rendering the settings panel on the provided render window.
        /// @details It uses the SFML graphics library to draw the panel and its contents.
        /// @note The render method should be called within the main rendering loop of the application.        
        void render(sf::RenderWindow& window); // Render the My Day state

        /// @brief Update the settings state.
        /// @details This method is responsible for updating the state of the settings panel.
        /// @details It may include updating the position, size, or appearance of the panel based on user interactions or other events.
        /// @note The update method should be called within the main update loop of the application.
        void update(); // Update the My Day state

        /// @brief Process events related to the settings state.
        /// @param event 
        void processEvents(sf::Event& event); // Process events related to the My Day state

    private:

        sf::RectangleShape settingsPanel; // My Day panel shape
        sf::Color settingsColor; // Color of the My Day panel
        sf::Font settingsFont; // Font for the My Day text
        sf::Text settingsText; // Text for the My Day title     
};