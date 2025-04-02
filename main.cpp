#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
#include <array>

using namespace std;

/// @file main.cpp
/// @brief A simple to-do list program that allows users to add, remove, and view tasks.
/// @details This program provides a basic command-line interface for managing tasks.  
/// @note The program uses a vector to store tasks and allows users to add, remove, and view them.
/// @exception None


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

    bool completed = false; ///< Indicates whether the task is completed.

    
    /// @brief Constructor for the Task class.
    /// @details Initializes a task with an ID, name, and description.
    /// @param i The unique ID of the task.
    /// @param n The name of the task.
    /// @param d The description of the task.
    /// @return None
    /// @note The completed status is set to false by default.
    Task(int i, string n, string d) 
    {
        id = i;
        name = n;
        description = d;
        completed = false; // Default to not completed
    }

    /// @brief Displays the task details.
    /// @details Prints the task ID, name, and description to the console.
    /// @param None
    /// @return None
    void display() const;

    /// @brief Reorganizes the task IDs after a task is removed.
    /// @details This function updates the IDs of the tasks to be sequential after a task is removed.
    /// @param tasks A reference to the vector of tasks to be reorganized.
    /// @return None
    /// @note This function is called after a task is removed to ensure that the IDs are sequential.
    static void reorganizeIds(vector<Task>& tasks);

    /// @brief Saves the tasks to a file.
    /// @details This function writes the task details to a file for persistence.
    /// @param tasks 
    /// @return None
    /// @note This function is called when the program exits to save the tasks.
    static void saveTasks(const vector<Task>& tasks);

    /// @brief Loads the tasks from a file.
    /// @details This function reads the task details from a file to restore the tasks.
    /// @param tasks A reference to the vector of tasks to be loaded.
    /// @param nextId A reference to the next available task ID.
    /// @return None
    /// @note This function is called when the program starts to load the tasks.
    static void loadTasks(vector<Task>& tasks, int& nextId);
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

    /// @brief Marks a task as completed.
    /// @details This function prompts the user for the task ID to mark as completed and updates the task status.
    /// @param tasks A reference to the vector of tasks where the task will be marked as completed.
    /// @todo Add input validation for task ID.
    /// @todo Add confirmation before marking a task as completed.
    void completeTask(vector<Task>& tasks);

    /// @brief Future feature to edit a task.
    /// @details This function will allow the user to edit the details of an existing task.
    /// @param tasks 
    /// @todo Implement the edit task feature.
    /// @todo Add input validation for task name and description.
    void editTask(vector<Task>& tasks); // Future feature to edit tasks

    /// @brief Future feature to set task priorities.
    /// @details This function will allow the user to set priorities for tasks (high, medium, low).
    /// @param tasks
    /// @todo Implement the set task priority feature.
    void setTaskPriority(vector<Task>& tasks); // Future feature to set task priorities

    /// @brief Future feature to sort tasks.
    /// @details This function will allow the user to sort tasks based on priority or due date.
    /// @param tasks
    /// @todo Implement the sort tasks feature.
    void sortTasks(vector<Task>& tasks); // Future feature to sort tasks

    /// @brief Future feature to set due dates.
    /// @details This function will allow the user to set due dates for tasks.
    /// @param tasks
    /// @todo Implement the set due date feature.
    void setDueDate(vector<Task>& tasks); // Future feature to set due dates

    /// @brief Future feature to categorize tasks.
    /// @details This function will allow the user to categorize tasks (e.g., work, personal, etc.).
    /// @param tasks
    /// @todo Implement the categorize tasks feature.
    void categorizeTasks(vector<Task>& tasks); // Future feature to categorize tasks

    /// @brief Future feature to search tasks.
    /// @details This function will allow the user to search for tasks by name or description.
    /// @param tasks
    /// @todo Implement the search tasks feature.
    void searchTasks(vector<Task>& tasks); // Future feature to search tasks

    /// @brief Future feature to set reminders.
    /// @details This function will allow the user to set reminders for tasks.
    /// @param tasks
    /// @todo Implement the set reminders feature.
    void setReminders(vector<Task>& tasks); // Future feature to set reminders

    /// @brief Future feature to archive tasks.
    /// @details This function will allow the user to archive completed tasks. 
    /// @param tasks
    /// @todo Implement the archive tasks feature.
    void archiveTasks(vector<Task>& tasks); // Future feature to archive tasks

    /// @brief Future feature to customize UI.
    /// @details This function will allow the user to customize the user interface (themes, colors, etc.).
    /// @param tasks
    /// @todo Implement the customize UI feature.
    void customizeUI(vector<Task>& tasks); // Future feature to customize UI    
};

class UserInput 
{
public:
    
    string convertUserInputLowercase(const string& str);
    string trimUserInput(const string& str);

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

    // Load tasks from file
    Task::loadTasks(tasks, nextId);

    while (menuChoice != 7) 
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
                programFlow.completeTask(tasks);
                break;
            }
            case 5:
            {
                programFlow.editTask(tasks); // Future feature to edit tasks
                break;
            }
            case 6:
            {
                programFlow.searchTasks(tasks); // Future feature to search tasks
                break;
            }
            case 7:
            {
                Task::saveTasks(tasks); // Save tasks to file before exiting
                cout << "Exiting program. Tasks saved to file." << endl;
                return 0; // Exit the program
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

/// Function Definitions

void Task::display() const 
{
    string status = completed ? "[✓]" : "[ ]"; // Display completed status
    cout << id << ".) " << status << " " << name << " - " << description << endl;
}

void Task::reorganizeIds(vector<Task>& tasks) 
{
    for (size_t i = 0; i < tasks.size(); ++i) 
    {
        tasks[i].id = i + 1; // Reorganize IDs to be sequential
    }
}

void Task::saveTasks(const vector<Task>& tasks) 
{
    ofstream outFile("tasks.txt");
    if (outFile.is_open()) 
    {
        for (const auto& task : tasks) 
        {
            outFile << task.id << "," << task.name << "," << task.description << "," << task.completed << endl;
        }
        outFile.close();
    } 
    else 
    {
        cout << "Unable to open file for saving tasks." << endl;
    }
}

void Task::loadTasks(vector<Task>& tasks, int& nextId) 
{
    ifstream inFile("tasks.txt");
    if (inFile.is_open()) 
    {
        string line;
        while (getline(inFile, line)) 
        {
            size_t pos = 0;
            vector<string> taskData;
            while ((pos = line.find(",")) != string::npos) 
            {
                taskData.push_back(line.substr(0, pos));
                line.erase(0, pos + 1);
            }
            taskData.push_back(line); // Add the last part

            if (taskData.size() == 4) 
            {
                Task task(stoi(taskData[0]), taskData[1], taskData[2]);
                task.completed = (taskData[3] == "1");
                tasks.push_back(task);
                nextId = max(nextId, task.id + 1); // Update nextId
            }
        }
        inFile.close();
    } 
    else 
    {
        cout << "Unable to open file for loading tasks." << endl;
    }
}

void ProgramFlow::displayMenu() 
{
    cout << "\nTo-do list" << endl;
    cout << "1. Add task" << endl;
    cout << "2. Remove task" << endl;
    cout << "3. View tasks" << endl;
    cout << "4. Mark task as completed" << endl;
    cout << "5. Edit task" << endl; // Future feature to edit tasks
    cout << "6. Search tasks" << endl; // Future feature to search tasks
    // cout << "6. Set task priority" << endl; // Future feature to set task priorities
    // cout << "7. Sort tasks" << endl; // Future feature to sort tasks
    // cout << "8. Set due date" << endl; // Future feature to set due dates    
    cout << "7. Exit" << endl;
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

    // Reorganize IDs after removal
    if (!tasks.empty()) 
    {
        
        Task::reorganizeIds(tasks);
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

void ProgramFlow::completeTask(vector<Task>& tasks) 
{
    if (tasks.empty()) 
    {
        cout << "No tasks to mark as completed." << endl;
        return;
    }

    int idToComplete;
    cout << "Enter task ID to mark as completed: ";
    if (!(cin >> idToComplete)) 
    {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Please enter a number." << endl;
        return; // Exit the function if input is invalid
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character from the input buffer

    bool found = false;
    for (auto& task : tasks) 
    {
        if (task.id == idToComplete) 
        {
            task.completed = true; // Mark the task as complete
            cout << "Task marked as completed!" << endl;
            found = true;
            break;
        }
    }

    if (!found) 
    {
        cout << "Task ID not found." << endl;
    }
}

void ProgramFlow::editTask(vector<Task>& tasks) 
{
    if (tasks.empty()) 
    {
        cout << "No tasks to edit." << endl;
        return; // Exit the function if there are no tasks
    }

    int idToEdit;
    
    cout << "Enter task ID to edit: ";

    if (!(cin >> idToEdit)) // Check if input is valid
    {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Please enter a number." << endl;
        return; // Exit the function if input is invalid
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character from the input buffer

    bool found = false;

    for (auto& task : tasks) 
    {
        if (task.id == idToEdit) 
        {
            string newName, newDescription;
            cout << "New Task Name: ";
            getline(cin, newName);
            cout << "New Task Description: ";
            getline(cin, newDescription);

            // Update task details
            task.name = newName;
            task.description = newDescription;
            cout << "Task updated successfully!" << endl;
            found = true;
        }
    }

    if (!found) 
    {
        cout << "Task ID not found." << endl;
    }
    // Reorganize IDs after editing
    if (!tasks.empty()) 
    {
        Task::reorganizeIds(tasks);
    }
    // Save tasks to file after editing
    Task::saveTasks(tasks);
    cout << "Tasks saved to file." << endl;
}

void ProgramFlow::setTaskPriority(vector<Task>& tasks) 
{
    // Future feature to set task priorities
    cout << "Set task priority feature is not implemented yet." << endl;

    if (tasks.empty()) 
    {
        cout << "No tasks to set priority." << endl;
        return; // Exit the function if there are no tasks
    }
}

void ProgramFlow::sortTasks(vector<Task>& tasks) 
{
    // Future feature to sort tasks
    cout << "Sort tasks feature is not implemented yet." << endl;
}

void ProgramFlow::setDueDate(vector<Task>& tasks) 
{
    // Future feature to set due dates
    cout << "Set due date feature is not implemented yet." << endl;
}

void ProgramFlow::categorizeTasks(vector<Task>& tasks) 
{
    // Future feature to categorize tasks
    cout << "Categorize tasks feature is not implemented yet." << endl;
}

void ProgramFlow::searchTasks(vector<Task>& tasks) 
{
    // Future feature to search tasks
    cout << "Search tasks feature is not implemented yet." << endl;

    if (tasks.empty()) 
    {
        cout << "No tasks to search." << endl;
        return; // Exit the function if there are no tasks
    }
    
    string searchTerm;
    cout << "Enter search term: ";
    
    if (!(cin >> searchTerm)) // Check if input is valid
    {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Please enter a string." << endl;
        return; // Exit the function if input is invalid
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character from the input buffer

    // Search for tasks containing the search term
    cout << "Tasks containing '" << searchTerm << "':" << endl;
    bool found = false;

    searchTerm = UserInput().convertUserInputLowercase(searchTerm); // Convert search term to lowercase

    for (auto& task : tasks) 
    {
        task.name = UserInput().convertUserInputLowercase(task.name); // Convert task name to lowercase
        task.description = UserInput().convertUserInputLowercase(task.description); // Convert task description to lowercase
    }

    // Search for tasks containing the search term in name or description
    for (const auto& task : tasks) 
    {
        if (task.name.find(searchTerm) != string::npos) 
        {
            task.display(); // Display tasks containing the search term
            found = true;
        }
        else if (task.description.find(searchTerm) != string::npos) // Check if description contains the search term
        {
            task.display();
            found = true;
        }
        else if (task.id == stoi(searchTerm)) // Check if ID matches the search term
        {
            task.display();
            found = true;
        }
    }
    if (!found)
    {
        cout << "No tasks found with the search term '" << searchTerm << "'." << endl;
    }
}

void ProgramFlow::setReminders(vector<Task>& tasks) 
{
    // Future feature to set reminders
    cout << "Set reminders feature is not implemented yet." << endl;
}

void ProgramFlow::archiveTasks(vector<Task>& tasks) 
{
    // Future feature to archive tasks
    cout << "Archive tasks feature is not implemented yet." << endl;
}

void ProgramFlow::customizeUI(vector<Task>& tasks) 
{
    // Future feature to customize UI
    cout << "Customize UI feature is not implemented yet." << endl;
}

string UserInput::convertUserInputLowercase(const string& str) 
{
    string lowerStr = str;
    for (char& c : lowerStr) 
    {
        c = tolower(c); // Convert each character to lowercase
    }
    return lowerStr;
}

string UserInput::trimUserInput(const string& str) 
{
    size_t first = str.find_first_not_of(' '); // Find the first non-space character
    size_t last = str.find_last_not_of(' '); // Find the last non-space character
    return (first == string::npos) ? "" : str.substr(first, (last - first + 1)); // Return the trimmed string
}



