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
        PersistentUI();
        ~PersistentUI();

        void render(sf::RenderWindow& window); // Draw the UI elements
        void update(); // Update the UI elements
        void processEvents(sf::Event& event); // Process events related to the UI elements

};