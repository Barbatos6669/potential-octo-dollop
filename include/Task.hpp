#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

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
    string dueDate; ///< The due date of the task (e.g, "2025-04-01").
    int daysLeft; ///< The number of days left until the due date.
    string priority; ///< The priority of the task (e.g., "high", "medium", "low").
    string category; ///< The category of the task (e.g., "work", "personal").
    string status; ///< The status of the task (e.g., "completed", "incomplete").
    string createdDate; ///< The date when the task was created.
    string createdTime; ///< The time when the task was created.

    bool completed = false; ///< Indicates whether the task is completed.   

    /// @brief Constructor for the Task class.
    /// @details Initializes a task with an ID, name, and description.
    /// @param i The unique ID of the task.
    /// @param n The name of the task.
    /// @param d The description of the task.
    /// @param date The due date of the task (optional).
    /// @return None
    /// @note The completed status is set to false by default.
    Task(int i, string n, string d, string date = "", string p = "", string c = "", int daysLeft = 0)
        : id(i), name(n), description(d), dueDate(date), priority(p), category(c), completed(false), daysLeft(daysLeft) {}

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