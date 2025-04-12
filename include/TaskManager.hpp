#pragma once
#include "UIConfig.hpp"
#include "fstream"
#include "sstream"
#include "vector"

class TaskManager
{
public:
    struct Task
    {
        int id; // Unique identifier for the task
        std::string name; // Name of the task
        bool completed; // Completion status of the task
    };

    std::vector<Task> tasks; // Vector to hold the list of tasks
    int nextTaskId; // ID for the next task to be added

    // Constructor
    TaskManager();

    // Destructor
    ~TaskManager();    
};