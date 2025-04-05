// filepath: todo-list-app/todo-list-app/include/TaskManager.hpp
#pragma once
#include <vector>
#include <string>
#include "Task.hpp"
#include "Utils.hpp"

#include <iostream>

using namespace std;

/// @brief Class to manage a collection of tasks in the to-do list.
/// @details This class provides methods to add, remove, retrieve, save, and load tasks.
class TaskManager 
{
public:
    TaskManager();
    ~TaskManager();

    void addTask(const Task& task);
    void removeTask(int taskId);
    Task getTask(int taskId) const;
    vector<Task> getAllTasks() const;
    void saveTasksToFile(const string& filename) const;
    void loadTasksFromFile(const string& filename);

private:
    vector<Task> tasks; ///< Collection of tasks managed by the TaskManager.
    
};