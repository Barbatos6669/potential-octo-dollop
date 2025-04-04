#include "../include/Task.hpp"
#include "../include/ProgramFlow.hpp"
#include "../include/UserInput.hpp"
#include "../include/Time.hpp"

using namespace std;

int main() 
{
    ProgramFlow programFlow; // Create an instance of the ProgramFlow class
    vector<Task> tasks; // Vector to store tasks
    int nextId = 1; // Next available task ID
    Task::loadTasks(tasks, nextId); // Load tasks from file
    
    while (true) 
    {
        programFlow.displayMenu(); // Display the menu options
        int choice;
        cin >> choice; // Get user input for menu choice
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character from the input buffer

        switch (choice) 
        {
            case 1:
                programFlow.addTask(tasks, nextId); // Add a new task
                break;
            case 2:
                programFlow.removeTask(tasks); // Remove a task
                break;
            case 3:
                programFlow.completeTask(tasks); // Mark a task as completed
                break;
            case 4:
                programFlow.undoTask(tasks); // Undo the last task action
                break;
            case 5:
                programFlow.editTask(tasks); // Edit a task
                break;
            case 6:
                programFlow.searchTasks(tasks); // Search for tasks
                break;
            case 7:
                Task::saveTasks(tasks); // Save tasks to file before exiting
                cout << "Exiting the application." << endl;
                return 0; // Exit the application
            default:
                cout << "Invalid choice. Please try again." << endl; // Handle invalid menu choice
        }
    }
    Task::saveTasks(tasks); // Save tasks to file before exiting

    return 0;
}

