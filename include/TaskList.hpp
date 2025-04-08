#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "TaskItem.hpp"



class TaskList
{
    public:
        TaskList(int width, int height, int x, int y); // Constructor with default values
        ~TaskList(); // Destructor

        void render(sf::RenderWindow& window); // Render function to draw task items
        void update(); // Update function to handle task item updates
        void processEvents(const sf::Event& event); // Process events related to task items
        void loadFromFile(const std::string& filename); // Load task items from a file
        void saveToFile(const std::string& filename); // Save task items to a file    

    private:
        std::vector<TaskItem> taskItems; // Vector to hold task items    
};