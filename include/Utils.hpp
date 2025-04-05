// filepath: todo-list-app/todo-list-app/include/Utils.hpp
#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>



using namespace std;

namespace Utils 
{
    // Loads tasks from a file
    vector<string> loadTasksFromFile(const string& filename);

    // Saves tasks to a file
    void saveTasksToFile(const string& filename, const vector<string>& tasks);
}