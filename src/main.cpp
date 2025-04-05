#include <SFML/Graphics.hpp>
#include "GUI.hpp"
#include "TaskManager.hpp"


int main()
{
    // Create a TaskManager instance
    TaskManager taskManager;
    // Create a GUI instance
    GUI gui(taskManager);
    // LoadG tasks from a file
    taskManager.loadTasksFromFile("../tasks.txt");
    // Main loop
    while (true) 
    {
        // Handle user input
        gui.handleInput();
        // Update the display
        gui.updateDisplay();
        // Render the GUI with tasks
        gui.render(taskManager.getAllTasks());
    }
    // Save tasks to a file before exiting
    taskManager.saveTasksToFile("../tasks.txt");

    return 0;
}