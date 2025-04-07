/********************************************************************************************/
/*  UIConfig.cpp                                                                            */
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
#include "../include/UIConfig.hpp"
#include <iostream>

bool UIConfig::init() 
{
    // Load the default font
    if (!defaultFont.loadFromFile("../assets/fonts/arial.ttf")) {
        std::cerr << "Error loading font." << std::endl;
        return false; // Return false if font loading fails
    }
    
    defaultText.setFont(defaultFont); // Set the default font for the text
    defaultText.setCharacterSize(fontSize); // Set the character size for the text
    defaultText.setFillColor(textColor); // Set the text color

    return true; // Return true if initialization is successful
}