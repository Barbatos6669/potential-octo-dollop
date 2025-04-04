#pragma once
#include <SFML/Graphics.hpp> ///< Include the SFML graphics library for GUI components.
#include <SFML/Window.hpp> ///< Include the SFML window library for window management.

#include <iostream> ///< Include the iostream library for input/output operations.

#include "ScreenManager.hpp" ///< Include the Task class header file for task management.

using namespace std; ///< Use the standard namespace for convenience.

class ToDoAppGui 
{
    public:
        float padding = 2.5f; ///< Padding for the GUI elements.

        ToDoAppGui(); ///< Constructor for the GUI application.
        ~ToDoAppGui(); ///< Destructor for the GUI application.
        void run(); ///< Starts the GUI application.

    private:
        sf::RenderWindow window; ///< The main window of the application.
        sf::Font font; ///< Font used for text rendering.

        sf::RectangleShape leftPanel; ///< Left panel for displaying tasks.
        sf::RectangleShape myDayPanel; ///< Panel for displaying "My Day" tasks.

        ScreenManager screenManager; ///< Manages the current screen and transitions.
}; 
