/********************************************************************************************/
/*  Tasks.cpp                                                                               */
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
#include "../include/Tasks.hpp"

// Constructor
Tasks::Tasks(int width, int height, int x, int y) 
    : UIState(width, height, x, y, "Tasks") // Initialize the base class with the constructor
{
    // Initialize the My Day panel shape
    tasksPanel.setSize(sf::Vector2f(UIConfig::WINDOW_WIDTH, UIConfig::WINDOW_HEIGHT - 165)); // Set the size of the panel
    tasksPanel.setPosition(UIConfig::panelWidth + UIConfig::spacing * 2, 60); // Set the position of the panel
    tasksPanel.setFillColor(UIConfig::primaryColor); // Set the color of the panel

    tasksFont.loadFromFile("../assets/fonts/arial.ttf"); // Load the font for the My Day text
    tasksText.setFont(tasksFont); // Set the font of the My Day text
    tasksText.setString("Tasks"); // Set the text string
    tasksText.setCharacterSize(24); // Set the character size for the My Day text
    tasksText.setFillColor(UIConfig::textColor); // Set the text color
    tasksText.setPosition(UIConfig::panelWidth + UIConfig::spacing * 2 + 20, 70); // Set the position of the My Day text
    tasksText.setStyle(sf::Text::Bold); // Set the text style to bold
    tasksText.setOutlineThickness(1); // Set the outline thickness for the My Day text  

    std::cout << "Tasks initialized." << std::endl;
}

// Destructor
Tasks::~Tasks() 
{
    // Clean up resources here if needed
    std::cout << "Tasks destroyed." << std::endl;
}

// Render the Tasks state
void Tasks::render(sf::RenderWindow& window) 
{
    // Draw the tasks panel
    window.draw(tasksPanel); // Draw the tasks panel shape
    window.draw(tasksText); // Draw the tasks text    
}

// Update the Tasks state
void Tasks::update() 
{
    // Update the Tasks state here if needed
}

