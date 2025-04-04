#include "../include/ScreenManager.hpp"

ScreenManager::ScreenManager() : currentScreen(ScreenState::MAIN_MENU) 
{
    cout << "Initializing Screen Manager..." << endl; // Initialize the screen manager

}

ScreenManager::~ScreenManager() 
{
    cout << "Destroying Screen Manager..." << endl; // Clean up resources when the screen manager is destroyed
}

void ScreenManager::render(sf::RenderWindow& window) 
{
    cout << "Rendering current screen..." << endl; // Render the current screen
    window.clear(); // Clear the window before rendering
    switch (currentScreen) 
    {
        case ScreenState::MAIN_MENU:
            // Render main menu UI here
            break;
        case ScreenState::TASK_LIST:
            // Render task list UI here
            break;
        case ScreenState::ADD_TASK:
            // Render add task UI here
            break;
        case ScreenState::REMOVE_TASK:
            // Render remove task UI here
            break;
        case ScreenState::EDIT_TASK:
            // Render edit task UI here
            break;
        case ScreenState::VIEW_TASK:
            // Render view task UI here
            break;
        case ScreenState::EXIT:
            window.close(); // Close the window if exit is selected
            break;
    }
    window.display(); // Display the rendered content on the window
}
void ScreenManager::processEvents(sf::Event event) 
{
    cout << "Processing events..." << endl; // Process user input and window events
    if (event.type == sf::Event::Closed) 
    {
        currentScreen = ScreenState::EXIT; // Set exit screen state if close event is triggered
    }
    // Handle other events based on the current screen state
}

void ScreenManager::update() 
{
    cout << "Updating application state..." << endl; // Update the application state
    // Logic updates (e.g., animations, transitions) can be handled here
}

