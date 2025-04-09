/********************************************************************************************/
/*  MyDay.cpp                                                                               */
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


/// @brief This class represents the "My Day" state of the application.
/// @details The MyDay class inherits from the UIState class and is responsible for rendering and updating the "My Day" panel.
/// @note The class includes a constructor and destructor, as well as methods for rendering, updating, and processing events related to the "My Day" state.
class MyDay : public UIState
{
    public:
        // Constructor and Destructor
        /// @brief Constructor for the MyDay class.
        /// @details Initializes the My Day panel with default values for width, height, position, and color.
        /// @param width Width of the My Day panel (default is 200).
        /// @param height Height of the My Day panel (default is 800).
        /// @param x X position of the My Day panel (default is 0).
        /// @param y Y position of the My Day panel (default is 0).
        /// @note The constructor sets the size and position of the panel, as well as the font and text for the title.
        MyDay(int width = 200, int height = 800, int x = 0, int y = 0); // Constructor with default values

        /// @brief Destructor for the MyDay class.
        /// @details Cleans up resources used by the My Day panel.
        /// @note The destructor is responsible for releasing any resources allocated during the lifetime of the My Day panel.
        ~MyDay();

        /// @brief  Render the My Day state.
        /// @details This method is responsible for rendering the My Day panel on the provided render window.
        /// @param window 
        void render(sf::RenderWindow& window);

        /// @brief  Update the My Day state.
        /// @details This method is responsible for updating the My Day panel's state.
        /// @note The update method may include logic for refreshing the panel's content or handling animations.
        void update();
        /// @brief Process events related to the My Day state.
        /// @details This method handles user input events such as mouse clicks or keyboard presses.
        /// @param event 
        /// @note The processEvents method is responsible for responding to user interactions with the My Day panel.
        void processEvents(sf::Event& event);

    private:

        sf::RectangleShape myDayPanel; // My Day panel shape
        sf::Color myDayColor; // Color of the My Day panel
        sf::Font myDayFont; // Font for the My Day text
        sf::Text myDayText; // Text for the My Day title     

};