#include "../include/TaskManager.hpp"

TaskManager::TaskManager() 
{
    // Constructor implementation
    cout << "TaskManager initialized." << endl;
}
TaskManager::~TaskManager() 
{
    // Destructor implementation
}

void TaskManager::addTask(const Task& task) 
{
    cout << "Adding task: " << task.getName() << endl;

    // Add the task to the collection
    tasks.push_back(task);
    cout << "Task added: " << task.getName() << endl;
    // Print all tasks for debugging
    cout << "All tasks:" << endl;
    for (const auto& t : tasks) 
    {
        cout << t.getName() << endl;
    }
    // Print total tasks for debugging
    cout << "Total tasks: " << tasks.size() << endl;
}

void TaskManager::removeTask(int taskId) 
{
    cout << "Removing task with ID: " << taskId << endl;

    // Find and remove the task with the given ID
    
}

Task TaskManager::getTask(int taskId) const 
{
    cout << "Getting task with ID: " << taskId << endl;
    // Return a dummy task for demonstration purposes
    return Task(taskId, "Dummy Task", "This is a dummy task description.");
}

std::vector<Task> TaskManager::getAllTasks() const 
{
    return std::vector<Task>();
}

void TaskManager::saveTasksToFile(const std::string& filename) const 
{
    cout << "Saving tasks to file: " << filename << endl;

    // Convert tasks to strings for saving
    std::vector<string> taskStrings;
    for (const auto& task : tasks) 
    {
        // Convert task to string (assuming a simple format for demonstration)
        std::ostringstream oss;
        oss << task.getId() << " " << task.getName() << " " << task.getDescription();
        taskStrings.push_back(oss.str());
    }
    // Save tasks to file using Utils
    Utils::saveTasksToFile(filename, taskStrings);
    cout << "Tasks saved to file." << endl;
    // Print saved tasks for debugging
    cout << "Saved tasks:" << endl;
    for (const auto& task : taskStrings) 
    {
        cout << task << endl;
    }
    // Print total tasks saved
    cout << "Total tasks saved: " << taskStrings.size() << endl;
}

void TaskManager::loadTasksFromFile(const std::string& filename) 
{
    cout << "Loading tasks from file: " << filename << endl;

    // Load tasks from file using Utils
    std::vector<string> loadedTasks = Utils::loadTasksFromFile(filename);

}
