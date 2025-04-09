/********************************************************************************************/
/*  PersistentUI.hpp                                                                        */
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
#include "UIButton.hpp"
#include "UIPanel.hpp"

#include "UITime.hpp"

/// @brief This class represents the persistent UI elements of the application.
/// @details The PersistentUI class contains the UI elements that are always present in the application, such as panels, buttons, and time display.
/// @note The class includes methods for rendering, updating, and processing events for the UI elements.
class PersistentUI
{
    public:

        UIPanel leftPanel; // Left panel object
        UIPanel contentPanel; // Content panel object
        UIButton searchButton; // Search button object
        UIButton myDayButton; // My Day button object
        UIButton tasksButton; // Tasks button object
        UIButton newListButton; // New List button object
        UIButton addATaskButton; // Add a Task button object
        UIButton settingsButton; // Settings button object
        UIButton calendarButton; // Calendar button object        

        UITime timeDisplay; // Time display object
        sf::Texture backgroundTexture; // Background texture
        sf::Sprite backgroundSprite; // Background sprite
        // Constructor and Destructor
        /// @brief Default constructor for the PersistentUI class.
        /// @details Initializes the UI elements with default values and loads the background texture.
        /// @note The constructor also sets the position and size of the UI elements.
        PersistentUI();

        /// @brief Destructor for the PersistentUI class.
        /// @details Cleans up the resources used by the UI elements.
        /// @note The destructor is responsible for releasing any allocated resources.
        ~PersistentUI();

        // Methods
        /// @brief Renders the UI elements on the given window.
        /// @details This method draws all the UI elements, including panels, buttons, and time display, on the specified window.
        /// @param window The SFML render window where the UI elements will be drawn.
        /// @note The render method is responsible for updating the display of the UI elements.
        void render(sf::RenderWindow& window); 

        /// @brief Updates the UI elements based on the current state and events.
        /// @details This method updates the positions, states, and properties of the UI elements.
        /// @note The update method is responsible for refreshing the UI elements based on user interactions and other events.
        /// @param event The SFML event to process.
        void update();

        /// @brief Processes events related to the UI elements.
        /// @details This method handles user interactions with the UI elements, such as button clicks and panel interactions.
        /// @param event The SFML event to process.
        /// @note The processEvents method is responsible for managing user input and updating the UI elements accordingly.
        void processEvents(sf::Event& event); 

};