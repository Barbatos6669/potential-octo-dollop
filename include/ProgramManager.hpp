#pragma Once 
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "iostream"
#include "AppState.hpp"
#include "UIConfig.hpp"
#include "PersistentUI.hpp"
#include "MyDay.hpp"
#include "Tasks.hpp"
#include "AddTask.hpp"
#include "Settings.hpp"
#include "Calender.hpp"

class ProgramManager
{
    public:
        // Constructor and Destructor
        ProgramManager();
        ~ProgramManager();

        void run(); // Main loop of the program

    private:
        sf::RenderWindow window; // SFML window
        sf::Event event; // SFML event
        sf::Clock clock; // SFML clock

        PersistentUI persistentUI; // Persistent UI object
        AppState currentState; // Current application state

        MyDay myDay; // My Day object
        Tasks tasks; // Tasks object
        AddTask addTask; // Add Task object   
        Settings settings; // Settings object 
        Calender calender; // Calendar object
        
        void processEvents(); // Process events
        void update(); // Update the program state
        void render(); // Render the program
};