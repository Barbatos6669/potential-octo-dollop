/********************************************************************************************/
/*  ProgramManager.cpp                                                                      */
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
#include "../include/ProgramManager.hpp"

// Constructor
ProgramManager::ProgramManager() 
    : window(sf::VideoMode(UIConfig::WINDOW_WIDTH, UIConfig::WINDOW_HEIGHT), "SFML Application"), 
    persistentUI(),
    currentState(AppState::MyDay),
    myDay(UIConfig::panelWidth, UIConfig::panelHeight, 0, 0),
    tasks(UIConfig::panelWidth, UIConfig::panelHeight, 0, 0),
    addTask(UIConfig::panelWidth, UIConfig::panelHeight, 0, 0), 
    settings(UIConfig::panelWidth, UIConfig::panelHeight, 0, 0),
    calender(UIConfig::panelWidth, UIConfig::panelHeight, 0, 0) 
{
    // Initialize the window and other resources here
    window.setFramerateLimit(60); // Set the frame rate limit
}

// Destructor
ProgramManager::~ProgramManager() 
{
    // Clean up resources here
}

// Main loop of the program
void ProgramManager::run() 
{
    while (window.isOpen()) 
    {
        processEvents(); // Process events
        update(); // Update the program state
        render(); // Render the program
    }
}

// Process events
void ProgramManager::processEvents() 
{
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close(); // Close the window if the close event is received
        }
    }

    // Handle other events here (e.g., keyboard input, mouse input, etc.)
    if (event.type == sf::Event::MouseButtonPressed) 
    {
        if (persistentUI.searchButton.buttonShape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) 
        {
            std::cout << "Search button clicked!" << std::endl; // Handle search button click
            currentState = AppState::Search; // Change the state to Search
            std::cout << "Current state: " << static_cast<int>(currentState) << std::endl; // Print the current state
        }
        else if (persistentUI.myDayButton.buttonShape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) 
        {
            std::cout << "My Day button clicked!" << std::endl; // Handle My Day button click
            currentState = AppState::MyDay; // Change the state to My Day
            std::cout << "Current state: " << static_cast<int>(currentState) << std::endl; // Print the current state
        }
        else if (persistentUI.tasksButton.buttonShape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) 
        {
            std::cout << "Tasks button clicked!" << std::endl; // Handle Tasks button click
            currentState = AppState::Tasks; // Change the state to Tasks
            std::cout << "Current state: " << static_cast<int>(currentState) << std::endl; // Print the current state
        }
        else if (persistentUI.newListButton.buttonShape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) 
        {
            std::cout << "New List button clicked!" << std::endl; // Handle New List button click
            currentState = AppState::NewList; // Change the state to New List
            std::cout << "Current state: " << static_cast<int>(currentState) << std::endl; // Print the current state
        }
        else if (persistentUI.addATaskButton.buttonShape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) 
        {
            std::cout << "Add a Task button clicked!" << std::endl; // Handle Add a Task button click
            currentState = AppState::AddTask; // Change the state to Add Task
            std::cout << "Current state: " << static_cast<int>(currentState) << std::endl; // Print the current state
        }
        else if (persistentUI.settingsButton.buttonShape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) 
        {
            std::cout << "Settings button clicked!" << std::endl; // Handle Settings button click
            currentState = AppState::Settings; // Change the state to Settings
            std::cout << "Current state: " << static_cast<int>(currentState) << std::endl; // Print the current state
        }
        else if (persistentUI.calendarButton.buttonShape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) 
        {
            std::cout << "Calendar button clicked!" << std::endl; // Handle Calendar button click
            currentState = AppState::Calendar; // Change the state to Calendar  
            std::cout << "Current state: " << static_cast<int>(currentState) << std::endl; // Print the current state      
        }
    }

    persistentUI.processEvents(event); // Process events for the persistent UI
}

// Update the program state
void ProgramManager::update() 
{
    // Update the program state here (e.g., game logic, animations, etc.)
    switch (currentState) 
    {
        case AppState::MyDay:
            // Update logic for My Day state      
            break;
        case AppState::Calendar:
            // Update logic for Calendar state
            break;
        case AppState::Tasks:
            // Update logic for Tasks state
            break;
        case AppState::Settings:
            // Update logic for Settings state
            break;
        case AppState::NewList:
            // Update logic for New List state
            break;
        case AppState::AddTask:
            // Update logic for Add Task state
            break;
        case AppState::Search:
            // Update logic for Search state
            break;
        default:
            std::cerr << "Unknown state!" << std::endl; // Handle unknown state
            break;
    }
    persistentUI.update(); // Update the persistent UI
}

// Render the program
void ProgramManager::render() 
{
    window.clear(sf::Color::Black); // Clear the window with a black color

    // Draw your UI elements here (e.g., buttons, panels, etc.)
    switch(currentState)
    {
        case AppState::MyDay:
            persistentUI.render(window); // Render the persistent UI for My Day
            myDay.render(window); // Render the My Day state
            break;
        case AppState::Calendar:
            persistentUI.render(window); // Render the persistent UI for Calendar
            calender.render(window); // Render the Calendar state
            break;
        case AppState::Tasks:
            persistentUI.render(window); // Render the persistent UI for Tasks
            tasks.render(window); // Render the Tasks state
            break;
        case AppState::Settings:
            persistentUI.render(window); // Render the persistent UI for Settings
            settings.render(window); // Render the Settings state
            break;
        case AppState::NewList:
            persistentUI.render(window); // Render the persistent UI for New List
            break;
        case AppState::AddTask:
            persistentUI.render(window); // Render the persistent UI for Add Task
            addTask.render(window); // Render the Add Task state
            break;
        case AppState::Search:
            persistentUI.render(window); // Render the persistent UI for Search
            break;
        default:
            std::cerr << "Unknown state!" << std::endl; // Handle unknown state
            break;
    }
    
    window.display(); // Display the contents of the window
}

