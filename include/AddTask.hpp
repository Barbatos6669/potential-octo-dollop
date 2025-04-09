/********************************************************************************************/
/*  AddTask.hpp                                                                             */
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

/// @brief Class representing the Add Task state in the application.
/// This class is responsible for rendering and updating the Add Task UI.
/// It inherits from the UIState class, which provides common functionality for UI states.
/// @details The AddTask class contains a panel for adding tasks, a title text, and handles user input events.
/// It uses SFML for rendering graphics and handling events.
/// @note The class is designed to be used in a graphical application where tasks can be added to a list.
/// @note The class is part of a larger application that manages tasks and events.
class AddTask : public UIState
{
    public:
        // Constructor and Destructor

        /// @brief Constructor for the AddTask class.
        /// @details This constructor initializes the Add Task panel and title text.
        /// @param width The width of the panel.
        /// @param height The height of the panel.
        /// @param x The x position of the panel.
        /// @param y The y position of the panel.
        /// @note The constructor sets the size and position of the panel, as well as the font and text for the title.

        AddTask(int width = 200, int height = 800, int x = 0, int y = 0); // Constructor with default values

        /// @brief Destructor for the AddTask class.
        /// @details This destructor cleans up any resources used by the Add Task state.
        /// @note The destructor is responsible for releasing any dynamically allocated resources.
        ~AddTask(); 

        /// @brief Render the Add Task state.
        /// @details This function draws the Add Task panel and title text on the provided window.
        /// @param window 
        void render(sf::RenderWindow& window); // Render the My Day state

        /// @brief Update the Add Task state.
        /// @details This function updates the state of the Add Task panel and handles any necessary logic.
        /// @param event The event to process.        
        void update(); 

        /// @brief Process events related to the Add Task state.
        /// @details This function handles user input events such as mouse clicks and keyboard input.
        /// @param event The event to process.        
        void processEvents(sf::Event& event); 
    private:

        sf::RectangleShape myDayPanel; // My Day panel shape
        sf::Color myDayColor; // Color of the My Day panel
        sf::Font myDayFont; // Font for the My Day text
        sf::Text myDayText; // Text for the My Day title    
};