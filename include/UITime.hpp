/********************************************************************************************/
/*  UItime.hpp                                                                              */
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
#include <ctime>

#include "iostream"

class UITime
{
    public:
        sf::Clock clock; // SFML clock to track time
        sf::Time elapsedTime; // Elapsed time since the clock started
        sf::Time deltaTime; // Time between frames

        sf::Text dayText; // Text to display the current day
        sf::Text timeText; // Text to display the current time
        sf::Text dateText; // Text to display the current date
        sf::Font font; // Font for the text

        int posX; // X position of the time display
        int posY; // Y position of the time display
        int width; // Width of the time display
        int height; // Height of the time display

        std::string dayString; // String to hold the current day
        std::string timeString; // String to hold the current time
        std::string dateString; // String to hold the current date        

        sf::Color textColor; // Color of the text

        UITime(int x = 0, int y = 0, int w = 200, int h = 50, sf::Color color = sf::Color(255, 255, 255)); // Constructor with default values
        ~UITime(); // Destructor

        void update(); // Update the time display
        void render(sf::RenderWindow& window); // Render the time display
        void processEvents(sf::Event& event); // Process events related to the time display

        void GetCurrentTime(); // Get the current time and date
        void GetCurrentDay(); // Get the current day of the week
        void GetCurrentDate(); // Get the current date
};