#include "../include/Utils.hpp"

// Loads tasks from a file
std::vector<string> Utils::loadTasksFromFile(const string& filename) 
{
    vector<string> tasks;
    ifstream file(filename);
    string line;
    if (file.is_open()) 
    {
        while (getline(file, line)) 
        {
            tasks.push_back(line);
        }
        file.close();
    } 
    else 
    {
        cout << "Unable to open file: " << filename << endl;
    }
    // Print loaded tasks for debugging
    cout << "Loaded tasks:" << endl;

    return tasks;
}

// Saves tasks to a file
void Utils::saveTasksToFile(const string& filename, const vector<string>& tasks) 
{
    ofstream file(filename);
    if (file.is_open()) 
    {
        for (const auto& task : tasks) 
        {
            file << task << endl;
        }
        file.close();
    } 
    else 
    {
        cout << "Unable to open file: " << filename << endl;
    }
    // Print saved tasks for debugging
    cout << "Saved tasks:" << endl;
    for (const auto& task : tasks) 
    {
        cout << task << endl;
    }

    // Print confirmation message
    cout << "Tasks saved to file: " << filename << endl;
}