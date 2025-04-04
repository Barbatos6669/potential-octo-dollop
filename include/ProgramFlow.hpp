#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <array>
#include <chrono>
#include <ctime>

#include "Task.hpp" // Include the Task class header file
#include "Time.hpp" // Include the Time class header file
#include "UserInput.hpp" // Include the UserInput class header file

using namespace std;

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

    /// @brief Future feature to undo the last task action.
    /// @details This function will allow the user to undo the last action performed on the task list.
    /// @param tasks A reference to the vector of tasks where the last action will be undone.
    /// @todo Implement the undo task feature.
    void undoTask(vector<Task>& tasks);

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
    
    /// @brief Future feature to return the days left until the due date.
    /// @details This function will return the number of days left until the due date of a task.
    /// @param tasks
    /// @todo Implement the days left feature.
    void daysLeft(vector<Task>& tasks); // Future feature to return the days left until the due date
};