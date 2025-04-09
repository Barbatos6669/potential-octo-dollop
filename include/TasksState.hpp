/********************************************************************************************/
/*  Tasks.hpp                                                                               */
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

/// @brief Class representing the Tasks state in the application.
/// @details This class inherits from UIState and is responsible for rendering and updating the Tasks panel.
/// It includes a panel for displaying tasks and a title text.
/// @details The Tasks panel is a rectangular shape with a specified width, height, and position.
/// @details The title text is displayed at the top of the panel and can be customized with a font and color.
class TasksState : public UIState
{
    public:
        // Constructor and Destructor
        /// @brief Constructor for the TasksState class.
        /// @param width Width of the Tasks panel (default: 200)
        /// @param height Height of the Tasks panel (default: 800)
        /// @param x X position of the Tasks panel (default: 0)
        /// @param y Y position of the Tasks panel (default: 0)
        /// @details Initializes the Tasks panel with the specified dimensions and position.
        TasksState(int width = 200, int height = 800, int x = 0, int y = 0); // Constructor with default values

        /// @brief Destructor for the TasksState class.
        /// @details Cleans up resources used by the Tasks panel.
        /// @details The destructor is virtual to ensure proper cleanup of derived classes.
        ~TasksState();
        
        /// @brief  Render the Tasks panel.
        /// @details This function is responsible for rendering the Tasks panel on the provided window.
        /// @param window 
        void render(sf::RenderWindow& window); 

        /// @brief  Update the Tasks panel state.
        /// @details This function is responsible for updating the state of the Tasks panel.
        /// @details It may include updating the position, size, or other properties of the panel.
        void update(); 

        /// @brief  Process events related to the Tasks panel.
        /// @details This function is responsible for processing events related to the Tasks panel.
        /// @param event The event to process.
        void processEvents(sf::Event& event);

    private:

        sf::RectangleShape tasksPanel; // My Day panel shape
        sf::Color tasksColor; // Color of the My Day panel
        sf::Font tasksFont; // Font for the My Day text
        sf::Text tasksText; // Text for the My Day title     

};