/********************************************************************************************/
/*  Calender.hpp                                                                            */
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

/// @brief Class representing the Calendar state in the application.
/// @details This class inherits from UIState and is responsible for rendering and updating the Calendar state.
/// It includes a panel for displaying the calendar and a title text.
/// @note The calendar panel is initialized with default values for width, height, and position.
/// @note The class also includes methods for rendering, updating, and processing events related to the Calendar state.
/// @note The constructor initializes the calendar panel and title text, while the destructor cleans up resources.
class Calender : public UIState
{
    public:
        // Constructor and Destructor

        /// @brief Constructor for the Calendar class.
        /// @param width Width of the calendar panel (default is 200).
        /// @param height Height of the calendar panel (default is 800).
        /// @param x X position of the calendar panel (default is 0).
        /// @param y Y position of the calendar panel (default is 0).
        /// @details Initializes the calendar panel and title text with the specified dimensions and position.
        /// @note The calendar panel is created as a rectangle shape with the specified width and height.
        /// @note The title text is set to "My Day" with a specific font and color.
        /// @note The calendar panel is filled with a color and has a border outline.
        /// @note The font for the title text is loaded from a file, and the text is centered within the panel.
        Calender(int width = 200, int height = 800, int x = 0, int y = 0); 

        /// @brief Destructor for the Calendar class.
        /// @details Cleans up resources used by the Calendar class.
        /// @note The destructor is responsible for releasing any dynamically allocated resources.
        /// @note In this case, it does not perform any specific cleanup as no dynamic memory is allocated.
        ~Calender();

        /// @brief Render the Calendar state.
        /// @param window 
        /// The SFML render window to draw the Calendar state on.
        /// @details This method draws the calendar panel and title text on the specified render window.
        /// @note The calendar panel is drawn as a rectangle shape with a specific color and outline.
        void render(sf::RenderWindow& window); 

        /// @brief Update the Calendar state.
        /// @details This method updates the state of the calendar panel and title text.
        void update();

        /// @brief Process events related to the Calendar state.
        /// @param event The SFML event to process.
        /// @details This method handles user input events such as mouse clicks and keyboard input.
        /// @note It checks if the mouse is clicked within the bounds of the calendar panel and updates the state accordingly.
        void processEvents(sf::Event& event); 

    private:

        sf::RectangleShape myDayPanel; // My Day panel shape
        sf::Color myDayColor; // Color of the My Day panel
        sf::Font myDayFont; // Font for the My Day text
        sf::Text myDayText; // Text for the My Day title     
};