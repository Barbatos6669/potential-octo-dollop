#pragma once
#include <string>
#include <vector>

#include <iostream>

using namespace std;

/// @brief Class to represent a task in the to-do list.
/// @details This class contains the task ID, name, and description, along with methods to manage these properties.
class Task 
{
public:
    Task(int id, const string& name, const string& description);
    
    int getId() const;
    string getName() const;
    string getDescription() const;
    
    void setName(const string& name);
    void setDescription(const string& description);

private:
    int taskId;               ///< Unique identifier for the task
    string taskName;          ///< Name of the task
    string taskDescription;   ///< Description of the task
};