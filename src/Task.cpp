#include "../include/Task.hpp"


void Task::display() const 
{
    string status = completed ? "[✓]" : "[ ]"; // Display completed status
    int daysLeft = this->daysLeft; // Get the number of days left until the due date
    cout << id << ".) " << status << " " << name << " - " << description;

    if (!dueDate.empty()) // Display due date if set
    {
        cout << " - Due Date: " << dueDate; // Display due date if set
    }
    else 
    {
        cout << " - No due date set"; // Display no due date status
    } 

    if (daysLeft > 0) // Display days left if positive
    {
        cout << " - Days left: " << daysLeft << endl; // Display days left until due date
    } 
    else if (daysLeft < 0) // Display overdue status if negative
    {
        cout << " - Overdue by: " << abs(daysLeft) << " days" << endl; // Display overdue status
    } 
    else 
    {
        cout << "- Due today!" << endl; // Display due today status
    }
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
            outFile << task.id << "," << task.name << "," << task.description << "," << task.completed << "," << task.dueDate << ", " << task.daysLeft << endl;
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

            if (taskData.size() == 6) // Check if all fields are present
            {
                Task task(stoi(taskData[0]), taskData[1], taskData[2], taskData[4], taskData[5]);
                task.completed = (taskData[3] == "1"); // Convert string to bool
                tasks.push_back(task);
                nextId = max(nextId, task.id + 1); // Update nextId
            }
            else if (taskData.size() == 5) // Check if all fields are present
            {
                Task task(stoi(taskData[0]), taskData[1], taskData[2], taskData[4]);
                task.completed = (taskData[3] == "1"); // Convert string to bool
                tasks.push_back(task);
                nextId = max(nextId, task.id + 1); // Update nextId
            } 
            else if (taskData.size() == 4) // Handle tasks without due date
            {
                Task task(stoi(taskData[0]), taskData[1], taskData[2]);
                task.completed = (taskData[3] == "1"); // Convert string to bool
                tasks.push_back(task);
                nextId = max(nextId, task.id + 1); // Update nextId
            } 
            else if (taskData.size() == 3) // Handle tasks without due date and completed status
            {
                Task task(stoi(taskData[0]), taskData[1], taskData[2]);
                task.completed = false; // Default to not completed
                tasks.push_back(task);
                nextId = max(nextId, task.id + 1); // Update nextId
            } 
            else if (taskData.size() == 2) // Handle tasks without due date, completed status, and description
            {
                Task task(stoi(taskData[0]), taskData[1], ""); // Empty description
                task.completed = false; // Default to not completed
                tasks.push_back(task);
                nextId = max(nextId, task.id + 1); // Update nextId
            } 
            else if (taskData.size() == 1) // Handle tasks with only ID and name
            {
                Task task(stoi(taskData[0]), taskData[1], ""); // Empty description
                task.completed = false; // Default to not completed
                tasks.push_back(task);
                nextId = max(nextId, task.id + 1); // Update nextId
            } 
            else if (taskData.size() == 0) // Handle empty lines
            {
                continue; // Skip empty lines
            } 
            else // Handle invalid lines
            {
                cout << "Invalid task format in file. Skipping line." << endl;
                continue; // Skip invalid lines
            }
        }
        inFile.close();
    } 
    else 
    {
        cout << "Unable to open file for loading tasks." << endl;
    }
}