#include "../include/Task.hpp"

Task::Task(int id, const string& name, const string& description)
    : taskId(id), taskName(name), taskDescription(description) 
{
    // Constructor implementation
}
int Task::getId() const 
{
    cout << "Getting task ID: " << taskId << endl;
    
    // Return the task ID
    return taskId;
}
string Task::getName() const 
{
    cout << "Getting task name: " << taskName << endl;

    // Return the task name
    return taskName;
}
string Task::getDescription() const 
{
    cout << "Getting task description: " << taskDescription << endl;

    // Return the task description
    return taskDescription;
}
void Task::setName(const string& name) 
{
    cout << "Setting task name: " << name << endl;

    // Set the task name
    taskName = name;
}
void Task::setDescription(const string& description) 
{
    cout << "Setting task description: " << description << endl;

    // Set the task description
    taskDescription = description;
}