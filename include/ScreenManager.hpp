#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "IScreen.hpp" // Include the IScreen interface for screen management

using namespace std;

/// Enum to represent different screen states
enum class ScreenState 
{
    MAIN_MENU,
    TASK_LIST,
    ADD_TASK,
    REMOVE_TASK,
    EDIT_TASK,
    VIEW_TASK,
    EXIT
};

/// Manages the current screen and transitions
class ScreenManager 
{
public:
    ScreenState currentScreen; ///< The current screen state

    ScreenManager();           ///< Initializes with default screen state
    ~ScreenManager();          ///< Destructor

    void render(sf::RenderWindow& window);     ///< Renders UI based on current state
    void processEvents(sf::Event event);       ///< Processes user input
    void update();                             ///< Logic updates (e.g., animations)

private:
    IScreen* currentScreenPtr; ///< Pointer to the current screen object
    vector<IScreen*> screens;  ///< Vector to hold different screen objects
};
