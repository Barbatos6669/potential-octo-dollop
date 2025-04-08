/********************************************************************************************/
/*  Settings.cpp                                                                            */
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
#include "../include/Settings.hpp"

// Constructor
Settings::Settings(int width, int height, int x, int y) 
    : UIState(width, height, x, y, "Settings") // Initialize the base class with the constructor
{
    // Initialize the settings panel shape
    settingsPanel.setSize(sf::Vector2f(UIConfig::WINDOW_WIDTH, UIConfig::WINDOW_HEIGHT - 165)); // Set the size of the panel
    settingsPanel.setPosition(UIConfig::panelWidth + UIConfig::spacing * 2, 60); // Set the position of the panel
    settingsPanel.setFillColor(UIConfig::primaryColor); // Set the color of the panel

    settingsFont.loadFromFile("../assets/fonts/arial.ttf"); // Load the font for the Settings text
    settingsText.setFont(settingsFont); // Set the font of the Settings text
    settingsText.setString("Settings"); // Set the text string
    settingsText.setCharacterSize(24); // Set the character size for the Settings text
    settingsText.setFillColor(UIConfig::textColor); // Set the text color
    settingsText.setPosition(UIConfig::panelWidth + UIConfig::spacing * 2 + 20, 70); // Set the position of the Settings text
    settingsText.setStyle(sf::Text::Bold); // Set the text style to bold
    settingsText.setOutlineThickness(1); // Set the outline thickness for the Settings text  

    std::cout << "Settings initialized." << std::endl;
}

// Destructor
Settings::~Settings() 
{
    // Clean up resources here if needed
    std::cout << "Settings destroyed." << std::endl;
}

// Render the Settings state
void Settings::render(sf::RenderWindow& window) 
{
    // Draw the settings panel
    window.draw(settingsPanel); // Draw the settings panel shape
    window.draw(settingsText); // Draw the settings text    
}

// Update the Settings state
void Settings::update() 
{
    // Update the Settings state here if needed
}

// Process events related to the Settings state
void Settings::processEvents(sf::Event& event) 
{
    // Process events related to the Settings state here if needed
}