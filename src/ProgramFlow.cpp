#include "../include/ProgramFlow.hpp"


void ProgramFlow::displayMenu() 
{
    cout << "\nTo-do list" << endl;
    cout << "1. Add task" << endl;
    cout << "2. Remove task" << endl;    
    cout << "3. Mark task as completed" << endl;
    cout << "4. Undo task" << endl; // Future feature to undo tasks
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
    string taskName, taskDescription, taskDueDate; // Initialize taskDaysLeft to 0
    cout << "Add a new task" << endl;

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

    cout << "Due Date (YYYY-MM-DD): ";
    getline(cin, taskDueDate);

    if (!taskDueDate.empty()) 
    {
        // Validate due date format (YYYY-MM-DD)
        if (taskDueDate.length() != 10 || taskDueDate[4] != '-' || taskDueDate[7] != '-') 
        {
            cout << "Invalid due date format. Please use YYYY-MM-DD." << endl;
            return;
        }

        // Check if the date is valid (basic validation)
        int year = stoi(taskDueDate.substr(0, 4)); // Extract year
        int month = stoi(taskDueDate.substr(5, 2)); // Extract month
        int day = stoi(taskDueDate.substr(8, 2)); // Extract day

        if (month < 1 || month > 12 || day < 1 || day > 31) 
        {
            cout << "Invalid date. Please enter a valid date." << endl;
            return;
        }
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) 
        {
            cout << "Invalid date. The month you entered has only 30 days." << endl;
            return;
        }
        if (month == 2) 
        {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) // Leap year check
            {
                if (day > 29) 
                {
                    cout << "Invalid date. February has only 29 days in a leap year." << endl;
                    return;
                }
            } 
            else 
            {
                if (day > 28) 
                {
                    cout << "Invalid date. February has only 28 days in a non-leap year." << endl;
                    return;
                }
            }
        }

        // If the date is valid, set it to the task
        taskDueDate = taskDueDate; // Set the due date to the task
        
    }

    int daysLeft;
    // Calculate days left until the due date
    
    if (!taskDueDate.empty()) 
    {
        // Calculate days left until the due date
        Time time;
        string currentDate = time.getCurrentDate(); // Get the current date
        int currentYear = stoi(currentDate.substr(0, 4)); // Extract current year
        int currentMonth = stoi(currentDate.substr(5, 2)); // Extract current month
        int currentDay = stoi(currentDate.substr(8, 2)); // Extract current day

        int dueYear = stoi(taskDueDate.substr(0, 4)); // Extract due year
        int dueMonth = stoi(taskDueDate.substr(5, 2)); // Extract due month
        int dueDay = stoi(taskDueDate.substr(8, 2)); // Extract due day

        // Calculate days left until the due date (basic calculation)
        daysLeft = (dueYear - currentYear) * 365 + (dueMonth - currentMonth) * 30 + (dueDay - currentDay); // Basic calculation of days left
    }
    else 
    {
        taskDueDate = ""; // Set due date to empty if not provided
    }

    // Check if the task name already exists
    for (const auto& task : tasks) 
    {
        if (task.name == taskName) 
        {
            cout << "Task with this name already exists." << endl;
            return;
        }
    }

    tasks.push_back(Task(nextId, taskName, taskDescription, taskDueDate, "", "", daysLeft)); // Add the new task to the list
    cout << "Task added successfully!" << endl;
    nextId++;

    Task::saveTasks(tasks); // Save tasks to file after adding
    cout << "Tasks saved to file." << endl;
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

    // Save tasks to file after removal
    Task::saveTasks(tasks); // Save tasks to file after removing
    cout << "Tasks saved to file." << endl;

    viewTasks(tasks); // Display tasks after removal
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
    
    Task::saveTasks(tasks); // Save tasks to file after marking as completed
}

void ProgramFlow::undoTask(vector<Task>& tasks) 
{
    // Future feature to undo the last task action
    cout << "Undo task feature is not implemented yet." << endl;

    if (tasks.empty()) 
    {
        cout << "No tasks to undo." << endl;
        return; // Exit the function if there are no tasks
    }

    int idToUndo;
    cout << "Enter task ID to undo: ";
    if (!(cin >> idToUndo)) // Check if input is valid
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
        if (task.id == idToUndo) 
        {
            task.completed = false; // Mark the task as incomplete
            cout << "Task marked as incomplete!" << endl;
            found = true;
            break;
        }
    }

    if (!found) 
    {
        cout << "Task ID not found." << endl;
    }

    Task::saveTasks(tasks); 
    cout << "Tasks saved to file." << endl;
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

void ProgramFlow::daysLeft(vector<Task>& tasks) 
{
    // Future feature to return the days left until the due date
    cout << "Days left feature is not implemented yet." << endl;
}