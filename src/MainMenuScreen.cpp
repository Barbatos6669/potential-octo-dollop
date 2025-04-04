#include "../include/MainMenuScreen.hpp"

MainMenuScreen::MainMenuScreen() 
{
    cout << "Initializing Main Menu Screen..." << endl; // Initialize the main menu screen
}  

MainMenuScreen::~MainMenuScreen() 
{
    cout << "Destroying Main Menu Screen..." << endl; // Clean up resources when the main menu screen is destroyed
}

void MainMenuScreen::handleEvent(const sf::Event& event) 
{
    cout << "Handling events in Main Menu Screen..." << endl; // Handle user input and window events
    if (event.type == sf::Event::Closed) 
    {
        // Handle window close event
    }
    // Handle other events based on the main menu screen state
}

void MainMenuScreen::update() 
{
    cout << "Updating Main Menu Screen..." << endl; // Update the main menu screen state
    // Logic updates (e.g., animations, transitions) can be handled here
}

void MainMenuScreen::render(sf::RenderWindow& window) 
{
    cout << "Rendering Main Menu Screen..." << endl; // Render the main menu screen
    window.clear(); // Clear the window before rendering
    // Render main menu UI elements here
    window.display(); // Display the rendered content on the window
}