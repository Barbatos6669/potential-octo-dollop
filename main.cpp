#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

/// @file main.cpp
/// @brief A simple to-do list program that allows users to add, remove, and view tasks.
/// @details This program provides a basic command-line interface for managing tasks.  
/// @note The program uses a vector to store tasks and allows users to add, remove, and view them.
/// @warning This program does not include error handling for invalid user input.
/// @exception None

/// @todo [High Priority] Add a feature to mark tasks as completed.
/// @todo [High Priority] Implement file I/O to save and load tasks from a file.
/// @todo [Medium Priority] Add a feature to edit existing tasks.
/// @todo [Medium Priority] Implement a feature to set task priorities (high, medium, low).
/// @todo [Medium Priority] Add a feature to sort tasks based on priority or due date.
/// @todo [Medium Priority] Implement a feature to set due dates for tasks.
/// @todo [Medium Priority] Add a feature to categorize tasks (e.g., work, personal, etc.).
/// @todo [Low Priority] Implement a feature to search for tasks by name or description.
/// @todo [Low Priority] Add a feature to set reminders for tasks.
/// @todo [Low Priority] Implement a feature to archive completed tasks.
/// @todo [Low Priority] Add a feature to customize the user interface (themes, colors, etc.).

/// @todo [Future Features] 
///   - Implement a feature to view tasks in a calendar format.
///   - Add a feature to share tasks with other users.
///   - Implement a feature to sync tasks with a cloud service.
///   - Add a feature to set recurring tasks (daily, weekly, etc.).
///   - Implement a feature to import/export tasks from/to other task management apps.
///   - Add a feature to integrate with a calendar app.
///   - Implement a feature to set task dependencies (e.g., Task B cannot start until Task A is completed).
///   - Add a feature to set task reminders based on location (e.g., remind me when I get to work).
///   - Implement a feature to set task reminders based on time zones.
///   - Add a feature to prioritize tasks based on user input.
///   - Add a feature to mark tasks as important or urgent.
///   - Implement a feature to filter tasks based on their status (completed/incomplete).

/// @brief Class to represent a task in the to-do list.
/// @details This class contains the task ID, name, and description.
/// @note This class is used to create task objects that will be stored in the task list.
/// @warning None
/// @exception None
class Task 
{
public:
    int id; ///< The unique ID of the task.
    string name; ///< The name of the task.
    string description; ///< A brief description of the task.

    /// @brief Constructor for the Task class.
    /// @details Initializes a task with an ID, name, and description.
    /// @param i The unique ID of the task.
    /// @param n The name of the task.
    /// @param d The description of the task.
    Task(int i, string n, string d) 
    {
        id = i;
        name = n;
        description = d;
    }

    /// @brief Displays the task details.
    /// @details Prints the task ID, name, and description to the console.
    /// @param None
    /// @return None
    void display() const 
    {
        cout << id << ".) " << name << " - " << description << endl;
    }
};

/// @brief Class to manage the program flow and user interactions.
/// @details This class contains methods to display the menu, add tasks, remove tasks, and view tasks.
/// @note This class is responsible for handling user input and managing the task list.
/// @warning None
/// @exception None
class ProgramFlow 
{
public:
    /// @brief Displays the menu options to the user.
    /// @details This function prints the available options for the user to choose from.
    /// @todo Add an option to view completed tasks.
    void displayMenu();

    /// @brief Adds a new task to the task list.
    /// @details This function prompts the user for task details and adds it to the tasks vector.
    /// @param tasks A reference to the vector of tasks where the new task will be added.
    /// @param nextId A reference to the next available task ID.
    /// @todo Add input validation for task name and description.
    void addTask(vector<Task>& tasks, int& nextId);

    /// @brief Removes a task from the task list.
    /// @details This function prompts the user for the task ID to remove and removes it from the tasks vector.
    /// @param tasks A reference to the vector of tasks from which the task will be removed.
    /// @todo Add confirmation before removing a task.
    void removeTask(vector<Task>& tasks);

    /// @brief Displays the list of tasks.
    /// @details This function prints all the tasks in the tasks vector.
    /// @param tasks A reference to the vector of tasks to be displayed.
    /// @todo Add an option to filter tasks by priority or category.
    void viewTasks(const vector<Task>& tasks);
};

/// @brief Main function to run the program.
/// @details This function initializes the program and handles user input for the menu options.
/// @return 0 on success.
/// @note This function is the entry point of the program.
/// @warning None
/// @exception None
int main() 
{
    vector<Task> tasks; // To-Do list for incomplete tasks
    vector<Task> completedTasks; // To-Do list for completed tasks
    int menuChoice = 0;
    int nextId = 1;

    while (menuChoice != 4) 
    {
        ProgramFlow programFlow;
        programFlow.displayMenu();
        if (!(cin >> menuChoice)) 
        {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number." << endl;
            continue; // Skip to the next iteration of the loop
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character from the input buffer

        switch (menuChoice) 
        {
            case 1: 
            {
                programFlow.addTask(tasks, nextId);
                break;
            }
            case 2: 
            {
                programFlow.removeTask(tasks);
                break;
            }
            case 3: 
            {
                programFlow.viewTasks(tasks);
                break;
            }
            case 4:
            {
                cout << "Exit selected....Goodbye" << endl;
                break;
            }
            default:
            {
                cout << "Invalid option. Try again." << endl;
                break;
            }
        }
    }

    return 0;
}

void ProgramFlow::displayMenu() 
{
    cout << "\nTo-do list" << endl;
    cout << "1. Add task" << endl;
    cout << "2. Remove task" << endl;
    cout << "3. View tasks" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option: ";
}

void ProgramFlow::addTask(vector<Task>& tasks, int& nextId) 
{
    string taskName, taskDescription;

    cout << "Task Name: ";
    getline(cin, taskName);

    if (taskName.empty()) 
    {
        cout << "Task name cannot be empty." << endl;
        return;
    }

    if (taskName.length() > 50) 
    {
        cout << "Task name is too long. Maximum length is 50 characters." << endl;
        return;
    }

    if (taskName.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ") != string::npos) 
    {
        cout << "Task name can only contain letters, numbers, and spaces." << endl;
        return;
    }

    cout << "Task Description: ";
    getline(cin, taskDescription);

    if (taskDescription.empty()) 
    {
        cout << "Task description cannot be empty." << endl;
        return;
    }

    if (taskDescription.length() > 100) 
    {
        cout << "Task description is too long. Maximum length is 100 characters." << endl;
        return;
    }

    if (taskDescription.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ") != string::npos) 
    {
        cout << "Task description can only contain letters, numbers, and spaces." << endl;
        return;
    }

    tasks.push_back(Task(nextId, taskName, taskDescription));
    cout << "Task added successfully!" << endl;
    nextId++;
}

void ProgramFlow::removeTask(vector<Task>& tasks) 
{
    if (tasks.empty()) 
    {
        cout << "No tasks to remove." << endl;
        return;
    }

    int idToRemove;
    cout << "Enter task ID to remove: ";
    if (!(cin >> idToRemove)) 
    {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Please enter a number." << endl;
        return; // Exit the function if input is invalid
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character from the input buffer

    bool found = false;
    for (auto it = tasks.begin(); it != tasks.end(); ++it) 
    {
        if (it->id == idToRemove) 
        {
            tasks.erase(it);
            cout << "Task removed successfully!" << endl;
            found = true;
            break;
        }
    }

    if (!found) 
    {
        cout << "Task ID not found." << endl;
    }
}

void ProgramFlow::viewTasks(const vector<Task>& tasks) 
{
    if (tasks.empty()) 
    {
        cout << "No tasks in the list." << endl;
    } 
    else 
    {
        cout << "\nIncomplete tasks:\n";
        for (const auto& task : tasks) 
        {
            task.display();
        }
    }
}

