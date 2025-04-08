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

#include "../include/MyDay.hpp"

// Constructor
MyDay::MyDay(int width, int height, int x, int y) 
    : UIState(width, height, x, y, "Test"), myDayColor(UIConfig::primaryColor), myDayPanel(), myDayText() // Initialize member variables
{
    // Initialize the My Day panel shape
    myDayPanel.setSize(sf::Vector2f(UIConfig::WINDOW_WIDTH, UIConfig::WINDOW_HEIGHT - 165)); // Set the size of the panel
    myDayPanel.setPosition(UIConfig::panelWidth + UIConfig::spacing * 2, 60); // Set the position of the panel
    myDayPanel.setFillColor(UIConfig::primaryColor); // Set the color of the panel

    myDayFont.loadFromFile("../assets/fonts/arial.ttf"); // Load the font for the My Day text
    myDayText.setFont(myDayFont); // Set the font of the My Day text
    myDayText.setString("My Day"); // Set the text string
    myDayText.setCharacterSize(24); // Set the character size for the My Day text
    myDayText.setFillColor(UIConfig::textColor); // Set the text color
    myDayText.setPosition(UIConfig::panelWidth + UIConfig::spacing * 2 + 20, 70); // Set the position of the My Day text
    myDayText.setStyle(sf::Text::Bold); // Set the text style to bold
    myDayText.setOutlineThickness(1); // Set the outline thickness for the My Day text  

    
    std::cout << "My Day initialized." << std::endl;
}

// Destructor
MyDay::~MyDay() 
{
    // Clean up resources here if needed
    std::cout << "My Day destroyed." << std::endl;
}

// Render the My Day state
void MyDay::render(sf::RenderWindow& window) 
{
    // Draw the My Day panel
    window.draw(myDayPanel); // Draw the My Day panel shape
    window.draw(myDayText); // Draw the My Day text    

}

void MyDay::update() 
{
    // Update the My Day state here if needed
}

void MyDay::processEvents(sf::Event& event) 
{
    // Process events related to the My Day state here if needed
}