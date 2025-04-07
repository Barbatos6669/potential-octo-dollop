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

class AddTask : public UIState
{
    public:
        // Constructor and Destructor
        AddTask(int width = 200, int height = 800, int x = 0, int y = 0); // Constructor with default values
        ~AddTask(); // Destructor

        void render(sf::RenderWindow& window); // Render the My Day state
        void update(); // Update the My Day state
        void processEvents(sf::Event& event); // Process events related to the My Day state

    private:

        sf::RectangleShape myDayPanel; // My Day panel shape
        sf::Color myDayColor; // Color of the My Day panel
        sf::Font myDayFont; // Font for the My Day text
        sf::Text myDayText; // Text for the My Day title    
};