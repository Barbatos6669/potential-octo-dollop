/********************************************************************************************/
/*  UIConfig.hpp                                                                            */
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
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "iostream"
#include "string"

class UIConfig 
{
    public:   
        static const int WINDOW_WIDTH = 1280;
        static const int WINDOW_HEIGHT = 800;
        static const int panelWidth = WINDOW_WIDTH / 3; // Set the width of the panel to one-third of the window width
        static const int panelHeight = WINDOW_HEIGHT;
        static const int panelButtonWidth = panelWidth - 10; // Width of the panel button
        static const int panelButtonHeight = 50; // Height of the panel button
        static const int linePadding = 2;
        static const int spacing = 5;
        static const int fontSize = 24; // Font size for UI elements
        static const int iconSize = 50; // Icon size for UI elements

        static const std::string iconPath; // Path to the icon
        static const std::string backgroundPath; // Path to the background image

        inline static sf::Font defaultFont; // Default font for UI elements
        inline static sf::Text defaultText; // Default text for UI elements

        inline static const sf::Color primaryColor = sf::Color(10, 10, 10, 100); // Primary color for the UI elements
        inline static const sf::Color secondaryColor = sf::Color(30, 30, 30); // Secondary color for the UI elements
        inline static const sf::Color accentColor = sf::Color(150, 150, 150); // Accent color for the UI elements
        inline static const sf::Color backgroundColor = sf::Color(0, 0, 0); // Background color for the UI elements
        inline static const sf::Color textColor = sf::Color(255, 255, 255); // Text color for the UI elements

        static bool init(); // Initialize the UIConfig class by loading the default font
};