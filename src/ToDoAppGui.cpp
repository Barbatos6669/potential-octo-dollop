#include "../include/ToDoAppGui.hpp"

/// Constructor for the GUI application
ToDoAppGui::ToDoAppGui() 
{
    cout << "Initializing To-Do List App..." << endl; // Initialize the GUI application

    window.create(sf::VideoMode(800, 600), "To-Do List App"); // Create the main window
    window.setFramerateLimit(60); // Set the frame rate limit to 60 FPS  
    
}

/// Destructor for the GUI application
ToDoAppGui::~ToDoAppGui() 
{
    cout << "Destroying To-Do List App..." << endl; // Clean up resources when the application is destroyed
}

void ToDoAppGui::run() 
{
    cout << "Running To-Do List App..." << endl; // Start the application

    window.create(sf::VideoMode(800, 600), "To-Do List App"); // Create the main window
    window.setFramerateLimit(60); // Set the frame rate limit to 60 FPS

    sf::Event event; // Event object to handle user input
    while (window.isOpen()) 
    {
        while (window.pollEvent(event)) 
        {
           screenManager.processEvents(event); // Process events using the ScreenManager
           screenManager.update(); // Update the application state
           screenManager.render(window); // Render the current screen
        }
    }
}
